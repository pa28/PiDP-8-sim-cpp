//
// Created by richard on 06/08/18.
//

#ifndef CPU_SIM_DEVICE_H
#define CPU_SIM_DEVICE_H

#include <memory>
#include "pdp8.h"

namespace pdp8 {

    class device_bus {
    public:
        device_bus() : int_enable{0}, int_req{0}, dev_done{0}, stop_inst{0}, skip{false}, device_flag{},
                       device_mask{} {}

        void reset() {
            int_enable = int_req = dev_done = stop_inst = device_flag = 0;
            skip = false;
        }

        void update_interrupts() {
            int_req = int_enable | dev_done;
        }

        device_bus &set_device_done() {
            dev_done |= device_flag;
            return *this;
        }

        device_bus &clr_device_done() {
            dev_done &= device_mask;
            return *this;
        }

        device_bus &set_device_enable() {
            int_enable |= device_flag;
            return *this;
        }

        device_bus &clr_device_enable() {
            int_enable &= device_mask;
            return *this;
        }

        void set_device_id(uint8_t id) {
            device_flag = (1 << id);
            device_mask = ~device_flag;
        }

        bool is_device_done() { return (dev_done & device_flag) != 0; }

        device_bus_t int_enable, int_req, dev_done, stop_inst;
        device_bus_t device_flag, device_mask;
        bool skip;
    };

    struct null_device {

        null_device() = default;

        void initialize(device_bus &bus) {}

        void reset(device_bus &bus) {}

        void stop(device_bus &bus) {}

        void tick(device_bus &bus) {}

        base_type dispatch(device_bus &bus, base_type command, base_type data) { return data; }

        std::string name() const { return std::string{"null"}; }
        std::string long_name() const { return std::string{"A example device that does nothing."};}
    };

    using null_device_p = std::unique_ptr<null_device>;

} // namespace pdp8
#endif //CPU_SIM_DEVICE_H
