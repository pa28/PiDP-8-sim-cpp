//
// Created by richard on 06/08/18.
//

#ifndef CPU_SIM_CHASSIS_H
#define CPU_SIM_CHASSIS_H

#include <map>
#include <variant>
#include <any>
#include <functional>
#include "VirtualPanel.h"
#include "PanelStatus.h"
#include "CpuThread.h"
#include "cpu.h"
#include "DK8EA.h"


namespace pdp8 {

    class chassis : public std::enable_shared_from_this<chassis> { // LCOV_EXCL_LINE

    public:
        using device_variant_t = std::variant<null_device_p, DK8EA_p>;

        static std::shared_ptr<chassis> make_chassis();

        chassis();

        template<class Device, typename ...Args>
        void add_device(base_type id, Args &&...args) {
            auto did = static_cast<uint8_t>(id);
            if (devices.find(did) == devices.end())
                devices.emplace(did, std::make_unique<Device>(std::forward<Args>(args)...));
        }

        /**
         * @brief Reset the chassis.
         * @details Reset the device bus, reset the CPU, reset each device.
         */
        void reset();

        /**
         * @brief Initialize the chassis.
         * @details Reset the device bus, initialize the CPU, initialize each device.
         */
        void initialize();

        /**
         * @brief Start the CPU
         * @details Set halt_flag to false, call the CPU tick() method.
         */
        void start();

        /**
         * @brief Stop the CPU
         * @details Call the CPU stop() method, call the stop() method for each device.
         */
        void stop();

        /**
         * @brief Register a chassis time interval.
         * @details Call the CPU tick() method, call each device tick() method using @device_tick().
         */
        void tick();

        /**
         * @brief Call each device tick() method.
         */
        void device_tick();

        /**
         * @brief Update the chassis interrupt state.
         * @details Call the bus update_interrupts() method, set the CPU interrupt_request flag to the value
         * returned.
         */
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

        void write_status_lights() {
            status_lights.write_data(std::bind(&chassis::status_lights_writer, this, std::placeholders::_1));
        }

        void read_status_switches() {
            status_switches.read_data(std::bind(&chassis::status_switches_reader, this, std::placeholders::_1));
        }

        using status_lights_t = sim::VirtualPanel<PanelStatusLights>;
        using status_switches_t = sim::VirtualPanel<PanelStatusSwitches>;

        void status_lights_writer(status_lights_t::data_ptr_t &lights);

        void status_switches_reader(status_switches_t::data_ptr_t const &switches);

        status_lights_t status_lights;
        status_switches_t status_switches;

    protected:
        std::map<uint8_t, device_variant_t> devices;
        device_bus bus;

        std::atomic_bool run_flag;
        std::unique_ptr<sim::CpuThread> chassisThread;
    };

} // namespace pdp8


#endif //CPU_SIM_CHASSIS_H
