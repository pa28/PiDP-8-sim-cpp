//
// Created by richard on 04/08/18.
//

#ifndef CPU_SIM_CPUTHREAD_H
#define CPU_SIM_CPUTHREAD_H

#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include "PerformanceClock.h"

namespace sim {

    class CpuThread : public std::thread { // LCOV_EXCL_LINE
    public:
        CpuThread() : std::thread()
        , sim_time{0us}
        , wait_condition{}
        , wait_mutex{}
        , wait_flag{false} {}

        template<class Fn, class... Args>
        CpuThread(std::chrono::microseconds factor, Fn fn, Args ...args)
                : std::thread(fn, std::forward<Args>(args)...)
                , sim_time{factor}
                , wait_condition{}
                , wait_mutex{}
                , wait_flag{false} {}

        std::mutex shared_resource_mutex;

        sim::PerformanceClock sim_time;

        bool wait_on_condition() {
            bool return_value = false;
            if (joinable()) {
                std::unique_lock<std::mutex> lock(wait_mutex);
                wait_flag = true;

                sim_time.condition_wait_start();
                while (wait_flag)
                    wait_condition.wait(lock);
                sim_time.condition_wait_stop();
                sim_time.start();
                return_value = true;
            }
            return return_value;
        }

        void notify_condition() {
            std::unique_lock<std::mutex> lock(wait_mutex);
            wait_flag = false;
            wait_condition.notify_all();
        }

    protected:
        std::condition_variable wait_condition;
        std::mutex wait_mutex;
        bool wait_flag;
    };

} // namespace sim


#endif //CPU_SIM_CPUTHREAD_H
