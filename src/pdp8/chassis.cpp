//
// Created by richard on 06/08/18.
//

#include "chassis.h"


namespace pdp8 {

    using cpu_t = std::unique_ptr<CPU>;

    void start_chassis_thread(chassis *chs) {
        chs->run_thread();
    }

    chassis::chassis() : cpu{}, devices{}, bus{}, chassisThread{}, run_flag{true} {
    }

    void chassis::run_thread() {
        while (run_flag) {
            std::this_thread::sleep_for(20000us);
            tick();
        }
    }

    std::shared_ptr<chassis> chassis::make_chassis() {
        auto ch = std::make_shared<chassis>();
        ch->cpu = std::make_unique<CPU>(ch->shared_from_this());
        return ch;
    }

    void chassis::initialize() {
        bus.reset();
        cpu->initialize();
        for (auto &dev : devices) {
            bus.set_device_id(dev.first);
            std::visit([this](auto &&arg) { arg->initialize(bus); }, dev.second);
        }
    }

    void chassis::reset() {
        bus.reset();
        cpu->reset();
        for (auto &dev : devices) {
            bus.set_device_id(dev.first);
            std::visit([this](auto &&arg) { arg->reset(bus); }, dev.second);
        }
    }

    void chassis::stop() {
        cpu->stop();
        for (auto &dev : devices) {
            bus.set_device_id(dev.first);
            std::visit([this](auto &&arg) { arg->stop(bus); }, dev.second);
        }
    }

    void chassis::tick() {
        cpu->tick();
        for (auto &dev : devices) {
            bus.set_device_id(dev.first);
            std::visit([this](auto &&arg) { arg->tick(bus); }, dev.second);
        }
        update_interrupts();
    }

    base_type chassis::dispatch(base_type id, base_type command, base_type data) {
        if (devices.find(id) != devices.end()) {
            bus.skip = false;
            bus.set_device_id(static_cast<uint8_t >(id));
            data = std::visit([&](auto &&arg) -> base_type { return arg->dispatch(bus, command, data); },
                              devices[id]);
            if (bus.skip)
                cpu->pc << ++cpu->pc[cpu->cpu_word];
            update_interrupts();
        }
        return data;
    }

    void chassis::start() {
        cpu->halt_flag = false;
        cpu->tick();
    }

    void chassis::start_threads() {
        cpu->start_thread();
        chassisThread = std::make_unique<sim::CpuThread>(10us, start_chassis_thread, this);
    }

} // namespace pdp8
