//
// Created by richard on 03/08/18.
//

#include <exception>
#include "cpu.h"
#include "chassis.h"

namespace pdp8 {

    void start_cpu_thread(CPU *cpu) {
        cpu->run_thread();
    }

    void CPU::run_thread() {
        while (run_flag) {

            /*
             * If an error occurs halt until the error condition is cleared.
             */
            if (error_flag) {
                while (error_flag && run_flag) {
                    if (cpuThread)
                        cpuThread->wait_on_condition();
                }
                continue;
            }

            /*
             * In halt condition wait while run_flag is set until step_flag is set or halt_flag is cleared.
             */
            if (halt_flag) {
                while (halt_flag && run_flag && (not step_flag)) {
                    if (cpuThread)
                        cpuThread->wait_on_condition();
                }

                // Left the loop due to halt_flag or run_flag cleared, go back to the top
                if (not step_flag)
                    continue;

                // Left due to step_flag set, clear idle flag so the cpu can cycle at least once
                // Clear the step flag so it will be caught next time through
                step_flag = idle_flag = false;
            }

            /*
             * If pause or idle flag is set hold the CPU until next tick
             */
            if (idle_flag) {
                if (cpuThread) {
                    cpuThread->wait_on_condition();
                }
                idle_flag = false;
                continue;
            }

            try {
                instruction_cycle();

                if (cpuThread && cpuThread->sim_time.get_sim_period().count() > 10000)
                    cpuThread->sim_time.thread_performance_match();
            } catch (std::logic_error &le) {
                error_flag = halt_flag = true;
                std::cerr << le.what() << std::endl;
            }
        }
    }

    void CPU::fetch() {
        // memory address is the instruction field - program counter
        if (pc_boundary && pc >= pc_boundary)
            throw std::logic_error("PC out of bounds."); // LCOV_EXCL_LINE

        ma << field_register[sf_if](mem_field) << pc[mem_word](mem_word);
        mb << core[ma][mem_word];
        ir = mb;
        pc << ++pc[cpu_word];

        // set the memory address to point to the direct argument
        if (mb[page])
            ma << ma[page](mem_page) << mb[addr](mem_addr);
        else
            ma << mem_page.clear() << mb[addr];
    }

    void CPU::defer() {
        // handle auto incrementing memory locations
        if (ma[page]() == 0 && (ma[addr]() & 0170) == 0010) {
            core[ma] << ++core[ma][mem_word];
        }
        ma << core[ma][mem_word];

        // deferred memory access functions use the data field.
        ma << field_register[sf_df](mem_field);
    }

    void CPU::deposit(base_type data) {
        ma << pc[cpu_word];
        mb = data;
        core[ma] << mb[mem_word];
        pc << ++pc[cpu_word];
    }

    base_type CPU::examine() {
        ma << field_register[sf_if](mem_field) << pc[mem_word](mem_word);
        mb << core[ma][mem_word];
        pc << ++pc[cpu_word];
        return mb();
    }

    void CPU::instruction_cycle() {
        if (not single_step_flag)
            cycle_state = Interrupt;

        do {
            instruction_step();
        } while ((not single_step_flag) && cycle_state != Pause);
    }

    void CPU::instruction_step() {
        switch (cycle_state) {
            case Fetch:
                fetch();
                sim_time(16us);
                cycle_state = ir[op_code]() < _IOT && mb[ia] ? Defer : Execute;
                break;
            case Defer:
                defer();
                sim_time(16us);
                cycle_state = Execute;
                break;
            case Execute:
                sim_time(16us);
                switch (ir[op_code]()) {
                    case AND:
                        acl << (acl[cpu_word] & core[ma][mem_word]);
                        break;
                    case TAD:
                        acl << (acl[ac_link] + core[ma][mem_word](ac_link));
                        break;
                    case ISZ:
                        core[ma] << ++core[ma][mem_word];
                        if (not core[ma][mem_word])
                            pc << ++pc[cpu_word];
                        break;
                    case DCA:
                        core[ma] << acl[cpu_word];
                        acl = 0;
                        break;
                    case JMS:
                        field_register << field_buffer[sf_if];
                        ma << field_register[sf_if](mem_field);
                        core[ma] << pc[mem_word];
                        pc << ++ma[mem_word];
                        interrupt_deferred = false;
                        break;
                    case JMP:
                        if (not mb[ia]) {
                            if ((pc[cpu_word]() - 2) == ma[mem_word]()) { // JMP .-1
                                auto no = core[ma][mem_word];
                                if (no() == OP_KSF || no() == OP_CLSC) {
                                    idle_flag = true;   // idle loop detected
                                }
                            } else if ((pc[cpu_word]() - 1) == ma[mem_word]()) { // JMP .
                                if (interrupt_enable || interrupt_delayed > 0) {
                                    interrupt_enable = true;
                                    interrupt_delayed = 0;
                                    idle_flag = true;
                                } else {
                                    halt_flag = true;   // endless loop
                                }
                            }
                        }
                        field_register << field_buffer[sf_if];
                        pc << ma[mem_word];
                        interrupt_deferred = false;
                        break;
                    case _IOT:
                        execute_iot();
                        sim_time(11us); // in addition to execute time.
                        break;
                    case _OPR:
                        execute_opr();
                        break;
                    default: // LCOV_EXCL_LINE
                        throw std::logic_error("op code out of range."); // LCOV_EXCL_LINE
                }
                cycle_state = Pause;
                break;
            case Interrupt:
                if ((not interrupt_deferred) && interrupt_enable && interrupt_request) {
                    interrupt_buffer = field_register;
                    field_register << sf_if.clear() << sf_df.clear();
                    interrupt_enable = false;
                    ma << mem_field.clear() << mem_word.clear();
                    core[ma] << pc[mem_word];
                    pc = 1;
                }

                if (interrupt_delayed)
                    interrupt_enable = (--interrupt_delayed) == 0;

                cycle_state = Fetch;
                break;
            case Pause: // LCOV_EXCL_LINE
                break; // LCOV_EXCL_LINE
        }
    }

    void CPU::execute_opr() {
        auto bits = mb[opr_bits]();

        if (bits == 0) // NOP
            return;

        if ((bits & 0400) == 0) { // Group 1
            if (bits & 0200) acl << cpu_word.clear();
            if (bits & 0100) acl << link.clear();
            if (bits & 0040) acl << ~acl[cpu_word];
            if (bits & 0020) acl << ~acl[link];
            if (bits & 0001) acl << ++acl[cpu_word];
            switch (bits & 016) {
                case 000: // NOP
                    break;
                case 012: // RTR
                    acl = (acl() >> 1) | (acl() << 12);
                case 010: // RAR
                    acl = (acl() >> 1) | (acl() << 12);
                    break;
                case 006: // RTL
                    acl = (acl() << 1) | acl[link]();
                case 004: // RAL
                    acl = (acl() << 1) | acl[link]();
                    break;
                case 002: // BSW
                    acl = ((acl() >> 6) & 077) | ((acl() & 077) << 6);
                    break;
                default: // LCOV_EXCL_LINE
                    throw std::logic_error("Group 1 OPR error."); // LCOV_EXCL_LINE
            }
        } else if ((bits & 01) == 0) { // Group 2
            bool skip = false;
            switch (bits & 0170) {
                case 0010: // SKP
                    skip = true;
                    break;
                case 0020: // SNL
                    skip = acl[link] != 0;
                    break;
                case 0030: // SZL
                    skip = acl[link] == 0;
                    break;
                case 0040: // SZA
                    skip = acl[cpu_word] == 0;
                    break;
                case 0050: // SNA
                    skip = acl[cpu_word] != 0;
                    break;
                case 0100: // SMA
                    skip = acl[ac_sign] != 0;
                    break;
                case 0110: // SPA
                    skip = acl[ac_sign] == 0;
                    break;
                case 0000: // Not one of this group.
                    break;
                default: // LCOV_EXCL_LINE
                    throw std::logic_error("Group 2 OPR error."); // LCOV_EXCL_LINE
            }
            if (skip)
                pc << ++pc[cpu_word];

            if (bits & 0200) acl << cpu_word.clear(); // CLA
            if (bits & 0004) acl << (acl[cpu_word] | sr[cpu_word]); // OSR
            if (bits & 0002)
                halt_flag = true; // HLT
        } else { // Group 3

        }
    }

    void CPU::execute_iot() {
        switch (mb[dev_sel]()) {
            case 0:
                switch (mb[dev_cmd]()) {
                    case 0: //SKON
                        if (interrupt_enable)
                            pc << ++pc[cpu_word];
                    case 2: //IOF
                        interrupt_enable = false;
                        break;
                    case 1: //ION
                        interrupt_delayed = 2;
                        break;
                    case 3: //SRQ
                        if (interrupt_request)
                            pc << ++pc[cpu_word];
                        break;
                    case 4: //GTF
                        save_field << acl[link](sf_link) << sf_int_enable(interrupt_enable)
                                   << sf_int_req(interrupt_request ? 1 : 0) << sf_gt(greater_than_flag)
                                   << field_register[sf_if] << field_register[sf_df];
                        acl << save_field[cpu_word];
                        break;
                    case 5: //RTF
                        save_field << acl[cpu_word];
                        acl << save_field[sf_link](link);
                        interrupt_delayed = save_field[sf_int_enable] ? 2 : 0;
                        greater_than_flag = (bool)save_field[sf_gt];
                        field_buffer << save_field[sf_if] << save_field[sf_df];
                        field_register << save_field[sf_df];
                        break;
                    case 6: // SGT
                        if (greater_than_flag)
                            pc << ++pc[cpu_word];
                        break;
                    case 7: // CAF
                        initialize();
                        break;
                    default:
                        throw std::logic_error("IOT 00 error."); // LCOV_EXCL_LINE
                }
                break;
            case 020:
            case 021:
            case 022:
            case 023:
            case 024:
            case 025:
            case 026:
            case 027:            /* memory extension */
                switch (mb[dev_cmd]()) {
                    case 1: // CDF
                        field_register << mb[op_field](sf_df);
                        break;
                    case 2: // CIF
                        field_buffer << mb[op_field](sf_if);
                        interrupt_enable = false;
                        break;
                    case 3: // CDF CIF
                        field_register << mb[op_field](sf_df);
                        field_buffer << mb[op_field](sf_if);
                        interrupt_enable = false;
                        break;
                    case 4: //
                        switch (mb[dev_sel]() & 7) {
                            case 1: // RDF
                                acl << (acl[op_field] | field_register[sf_df](op_field));
                                break;
                            case 2: // RIF
                                acl << field_register[sf_if](sf_if);
                                break;
                            case 3: // RIB
                                acl << (acl[addr] | interrupt_buffer[addr]);
                                break;
                            case 4: // RMF
                                field_register << interrupt_buffer[sf_df];
                                field_buffer << interrupt_buffer[sf_if];
                                break;
                            default: // LCOV_EXCL_LINE
                                throw std::logic_error("Time share instructions not supported."); // LCOV_EXCL_LINE
                        }
                        break;
                    default: // LCOV_EXCL_LINE
                        throw std::logic_error("Ill-formed IOT memory extention."); // LCOV_EXCL_LINE
                }
                break;
            default:
                acl << cpu_word(the_chassis->dispatch(mb[dev_sel](), mb[dev_cmd](), acl[cpu_word]()));
                break;
        }
    }

    void CPU::initialize() {
        pc = 0;
        cycle_state = Interrupt;
    }

    void CPU::reset() {
        acl = 0;
        interrupt_enable = false;
        interrupt_deferred = false;
        interrupt_request = false;
        error_flag = false;
        cycle_state = Interrupt;
    }

    void CPU::start_thread() {
        cpuThread = std::make_unique<sim::CpuThread>(10us, start_cpu_thread, this);
    }

} // namespace pdp8
