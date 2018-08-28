//
// Created by richard on 06/08/18.
//

#include "chassis.h"


namespace pdp8 {

    using cpu_t = std::unique_ptr<CPU>;

    void start_chassis_thread(chassis *chs) {
        chs->run_thread();
    }

    chassis::chassis() : cpu{}, devices{}, bus{}, run_flag{true}, chassisThread{} {
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

    void chassis::start() {
        cpu->halt_flag = false;
        cpu->tick();
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
        device_tick();
    }

    void chassis::device_tick() {
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

    void chassis::update_interrupts() {
        cpu->interrupt_request = bus.update_interrupts();
    }

    void chassis::start_threads() {
        cpu->start_thread();
        chassisThread = std::make_unique<sim::CpuThread>(10us, start_chassis_thread, this);
    }

    void chassis::status_lights_writer(sim::VirtualPanel<PanelStatusLights>::data_ptr_t &lights) {
        lights->set_pc(PanelStatusLights::word_type_t{cpu->pc});
        lights->set_ma(PanelStatusLights::word_type_t{cpu->ma});
        lights->set_mb(PanelStatusLights::word_type_t{cpu->mb});
        lights->set_acl(PanelStatusLights::word_type_t{cpu->acl});
        lights->set_mq(PanelStatusLights::word_type_t{cpu->mq});
        lights->set_inst_field(PanelStatusLights::word_type_t{cpu->field_register[cpu->sf_if]()});
        lights->set_instruction(PanelStatusLights::word_type_t{cpu->ir[cpu->op_code]()});
        lights->set_flags(cpu->cycle_state == CPU::Fetch,
                          cpu->cycle_state == CPU::Execute,
                          cpu->cycle_state == CPU::Defer,
                          false,
                          false,
                          false,
                          cpu->interrupt_request,
                          false,
                          not cpu->halt_flag,
                          cpu->idle_flag);
    }

    void chassis::status_switches_reader(sim::VirtualPanel<PanelStatusSwitches>::data_ptr_t const &switches) {

    }

} // namespace pdp8
