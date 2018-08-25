//
// Created by richard on 04/08/18.
//

#ifndef CPU_SIM_PERFORMANCECLOCK_H
#define CPU_SIM_PERFORMANCECLOCK_H

#include <ratio>
#include <chrono>
#include <utility>
#include <thread>
#include <iostream>
#include <tuple>

using namespace std::chrono;

namespace sim {

    class PerformanceClock {
    public:
        explicit PerformanceClock(std::chrono::microseconds factor) : factor{factor} {}

        PerformanceClock &operator+=(std::chrono::microseconds sim_ticks) {
            sim_period += sim_ticks;
            return *this;
        }

        void start() {
            t0 = steady_clock::now();
            sim_period = 0us;
        }

        void condition_wait_start() {
            condition_wait = steady_clock::now();
        }

        void condition_wait_stop() {
            steady_clock::time_point now = steady_clock::now();
            total_sleep_time += duration_cast<std::chrono::microseconds>(now - condition_wait);
        }

        std::pair<std::chrono::microseconds, std::chrono::microseconds> check(bool reset = true) {
            t1 = steady_clock::now();
            std::pair<std::chrono::microseconds, std::chrono::microseconds>
                    result{sim_period / factor, duration_cast<std::chrono::microseconds>(t1 - t0)};
            if (reset) {
                t0 = t1;
                total_sim_period += sim_period;
                sim_period = 0us;
            }
            return result;
        }

        void start_total() {
            epoch = steady_clock::now();
            total_sim_period = 0us;
            total_sleep_time = 0us;
        }

/*
        std::tuple<std::chrono::microseconds, std::chrono::microseconds, std::chrono::microseconds> check_total() {
            steady_clock::time_point t = steady_clock::now();
            total_sim_period += sim_period;
            std::tuple<std::chrono::microseconds, std::chrono::microseconds, std::chrono::microseconds>
                    result{total_sim_period/factor, duration_cast<std::chrono::microseconds>(t - epoch), total_sleep_time};
            epoch = t;
            total_sim_period = 0us;
            return result;
        }
*/

        std::chrono::microseconds get_sim_period() const { return sim_period; }

        void thread_performance_match() {
            auto[sim, real] = check(true);
            if (sim > real) {
                std::this_thread::sleep_for(sim - real);
                total_sleep_time += (sim - real);
            }
        }

    protected:
        steady_clock::time_point t0, t1, epoch, condition_wait;

        std::chrono::microseconds total_sim_period{0};
        std::chrono::microseconds total_sleep_time{0};
        std::chrono::microseconds sim_period{0};
        std::chrono::microseconds factor;
    };

} // namespace sim


#endif //CPU_SIM_PERFORMANCECLOCK_H
