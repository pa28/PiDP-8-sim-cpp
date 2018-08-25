//
// Created by richard on 06/08/18.
//

#ifndef CPU_SIM_CHASSIS_H
#define CPU_SIM_CHASSIS_H

#include <map>
#include <variant>
#include <any>
#include "CpuThread.h"
#include "cpu.h"
#include "DK8EA.h"


namespace pdp8 {

    class chassis : public std::enable_shared_from_this<chassis> { // LCOV_EXCL_LINE

    public:
        using device_variant_t = std::variant<null_device_p,DK8EA_p>;

        static std::shared_ptr<chassis> make_chassis();
        chassis();

        template<class Device>
        void add_device(base_type id) {
            auto did = static_cast<uint8_t>(id);
            if (devices.find(did) == devices.end())
                devices.emplace(did, std::make_unique<Device>());
        }

        void initialize();

        void reset();

        void start();

        void stop();

        void tick();

        void update_interrupts();

        base_type dispatch(base_type id, base_type command, base_type data);

        std::unique_ptr<CPU> cpu;

        void run_thread();

        void start_threads();

        void stop_threads() {
            run_flag = false;
            cpu->run_flag = false;
            cpu->cpuThread->notify_condition();
        }

    protected:
        std::map<uint8_t, device_variant_t> devices;
        device_bus bus;

        std::atomic_bool run_flag;
        std::unique_ptr<sim::CpuThread> chassisThread;
    };

} // namespace pdp8


#endif //CPU_SIM_CHASSIS_H
