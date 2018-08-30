//
// Created by richard on 2018-08-26.
//

#pragma once

#include <memory>
#include <ratio>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <condition_variable>
#include <functional>

namespace sim {

    /**
     * @brief A template class to provide locking and notification around virtual front panel input and output.
     * @tparam DataStruct A data structure type that contains values flowing from a source to a destination.
     */
    template<class DataStruct>
    class VirtualPanel {
    public:
        using data_type_t = DataStruct;
        using data_ptr_t = std::unique_ptr<data_type_t>;
        using time_point_t = std::chrono::steady_clock::time_point;

        /**
         * @brief (constructor)
         */
        VirtualPanel() : data{}, data_ready{false},
                         mutex{}, data_condition_lck{},
                         data_condition{} {
            data = std::make_unique<data_type_t>();
            last_data_write = std::chrono::steady_clock::now();
        }

        /**
         * @brief Get the time point of the last data
         * @return sim::VirtualPanel::time_point_t
         * @details The time point may be used to determine if the data is more recent than held by the caller.
         * The read is mitigated by a shared mutex lock to ensure thread safety and prevent race conditions.
         */
        time_point_t get_last_data_write() const {
            std::shared_lock<std::shared_mutex> lock(mutex);
            return last_data_write;
        }

        /**
         * @brief Arrange to read the data.
         * @param reader A function that will copy data from the data structure to the destination.
         * @return sim::VirtualPanel::time_point_t
         * @details A shared lock is obtained and held against the mutex. The reader function is called with a shared
         * pointer reference to the data; this function should copy or use the data but must return smartly since
         * no more data can be received while the mutex is held. The last data write timepoint is returned ensuring
         * the caller has the time associated with the data just read.
         */
        time_point_t read_data(std::function<void(std::unique_ptr<data_type_t> const &)> reader) const {
            std::shared_lock<std::shared_mutex> lock(mutex);
            reader(data);
            return last_data_write;
        }

        /**
         * @brief Arrange to write the data
         * @param writer A function that will copy data from the source to the data structure.
         * @details A unique lock is obtained and held against the mutex. The writer function is called with a shared
         * pointer reference to the data structure; this function should set the structure value and return smartly
         * since no other access to the VirtualPannel is possible while the lock is held.
         *
         * The last data write timepoint is updated and threads waiting at @wait_on_data() are notified.
         */
        void write_data(std::function<void(std::unique_ptr<data_type_t> &)> writer) {
            std::unique_lock<std::shared_mutex> lock(mutex);
            writer(data);
            last_data_write = std::chrono::steady_clock::now();
            notify();
        }

        /**
         * @brief Wait until new data is available
         * @param time_point The last timepoint returned from a call to @get_last_data_write() or @read_data(),
         * or a default initialized time_point_t.
         * @details While the provided time point is the same as, or later than the last data write time point
         * wait on the data condition variable. See @write_data().
         */
        void wait_on_data(time_point_t time_point) const {
            std::unique_lock<std::mutex> lock(data_condition_lck);
            while (time_point >= last_data_write) data_condition.wait(lock);
        }

        /**
         * @brief Wait for at least one update and when reader returns false.
         * @param reader A callable object taking a unique_ptr to the data and returning a bool
         * @details Calls wait_on_data_state with the last data write time point and reader.
         */
        void wait_on_data_state(std::function<bool(std::unique_ptr<data_type_t> const &)> reader) const {
            wait_on_data_state(last_data_write, reader);
        }

        /**
         * @brief Wait until an update after time_point and when reader returns false.
         * @param time_point
         * @param reader A callable object taking a unique_ptr to the data and returning a bool
         * @details For each data write after time_point reader is called until it returns false.
         */
        void wait_on_data_state(time_point_t time_point,
                                std::function<bool(std::unique_ptr<data_type_t> const &)> reader) const {
            bool wait_state = true;
            while (wait_state) {
                wait_on_data(time_point);
                std::shared_lock<std::shared_mutex> lock(mutex);
                wait_state = reader(data);
                time_point = last_data_write;
            }
        }

    protected:
        std::unique_ptr<data_type_t> data;

        bool data_ready;

        time_point_t last_data_write;

        mutable std::shared_mutex mutex;
        mutable std::mutex data_condition_lck;
        mutable std::condition_variable data_condition;

        /**
         * @brief Notify threads waiting at @wait_on_data().
         */
        void notify() {
            std::unique_lock<std::mutex> lock(data_condition_lck);
            data_ready = true;
            data_condition.notify_all();
        }
    };

} // namespace sim

