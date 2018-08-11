#include <utility>

//
// Created by richard on 03/08/18.
//

#ifndef CPU_SIM_CPU_H
#define CPU_SIM_CPU_H

#include <memory>
#include "pdp8.h"
#include "PerformanceClock.h"
#include "CpuThread.h"

namespace pdp8 {

    inline constexpr size_t mem_blocks = 8;
    inline constexpr size_t mem_block_size = 4096;

    class Memory {
    public:
        static constexpr sim::hw_slice_spec<12, 0> memory_word{};

        Memory() {
            core = std::unique_ptr<memory_t[]>{new memory_t[mem_blocks * mem_block_size]};
        }

        memory_t &operator()(base_type idx) {
            return core[idx];
        }

        memory_t &operator[](base_type idx) {
            return core[idx];
        }

        memory_t &operator()(register_t idx) {
            return core[idx()];
        }

        memory_t &operator[](register_t idx) {
            return core[idx()];
        }

    protected:
        std::shared_ptr<memory_t[]> core;
    };

    class CPU {
    public:
        enum InstructionCode {
            AND, TAD, ISZ, DCA, JMS, JMP, _IOT, _OPR
        };

        enum CycleState {
            Interrupt, Fetch, Defer, Execute, Pause
        };

        register_t acl,
                pc,
                mb,
                ma,
                ir,
                pc_boundary,
                sr,
                save_field,
                field_register,
                field_buffer,
                interrupt_buffer;

        CycleState cycle_state;

        Memory core;

        static constexpr sim::hw_slice_spec<12, 0> cpu_word{};
        static constexpr sim::hw_slice_spec<1, 12> link{};
        static constexpr sim::hw_slice_spec<13, 0> ac_link{};
        static constexpr sim::hw_slice_spec<1, 11> ac_sign{};
        static constexpr sim::hw_slice_spec<3, pdp8_off_v<12,2>> op_code{};
        static constexpr sim::hw_slice_spec<1, pdp8_off_v<12,3>> ia{};
        static constexpr sim::hw_slice_spec<1, pdp8_off_v<12,4>> page{};
        static constexpr sim::hw_slice_spec<7, pdp8_off_v<12,11>> addr{};
        static constexpr sim::hw_slice_spec<6, pdp8_off_v<12,8>> dev_sel{};
        static constexpr sim::hw_slice_spec<3, pdp8_off_v<12,8>> op_field{};
        static constexpr sim::hw_slice_spec<3, pdp8_off_v<12,11>> dev_cmd{};
        static constexpr sim::hw_slice_spec<9, pdp8_off_v<12,11>> opr_bits{};
        static constexpr sim::hw_slice_spec<3, pdp8_off_v<16,2>> mem_field{};
        static constexpr sim::hw_slice_spec<5, pdp8_off_v<16,7>> mem_page{};
        static constexpr sim::hw_slice_spec<7, pdp8_off_v<16,15>> mem_addr{};
        static constexpr sim::hw_slice_spec<12, pdp8_off_v<16,15>> mem_word{};

        static constexpr sim::hw_slice_spec<1, pdp8_off_v<12,0>> sf_link{};
        static constexpr sim::hw_slice_spec<1, pdp8_off_v<12,1>> sf_gt{};
        static constexpr sim::hw_slice_spec<1, pdp8_off_v<12,2>> sf_int_req{};
        static constexpr sim::hw_slice_spec<1, pdp8_off_v<12,3>> sf_no_int{};
        static constexpr sim::hw_slice_spec<1, pdp8_off_v<12,4>> sf_int_enable{};
        static constexpr sim::hw_slice_spec<1, pdp8_off_v<12,5>> sf_uf{};
        static constexpr sim::hw_slice_spec<3, pdp8_off_v<12,8>> sf_if{};
        static constexpr sim::hw_slice_spec<3, pdp8_off_v<12,11>> sf_df{};


        bool interrupt_enable;
        bool interrupt_deferred;        // deferred until a JMP or JSR
        int interrupt_delayed;          // delayed until after next instruction
        bool interrupt_request;
        bool greater_than_flag;

        std::atomic_bool run_flag;      // CPU thread function runs while this is true
        std::atomic_bool halt_flag;     // CPU halted by HLT or other difficulty
        std::atomic_bool idle_flag;     // CPU has detected an idle condition
        std::atomic_bool error_flag;    // CPU has thrown an exception
        std::atomic_bool step_flag;     // Allow the CPU to run one step if the halt_flag is set
        std::atomic_bool single_step_flag; // The CPU will progress through a single time slice

        std::unique_ptr<sim::CpuThread> cpuThread;
        // : sim::CpuThread(10us, start_cpu_thread, this)

        std::shared_ptr<chassis> the_chassis;

        explicit CPU(std::shared_ptr<chassis> chassis)
                : acl{},
                pc{},
                pc_boundary{},
                mb{},
                ma{},
                ir{},
                sr{},
                run_flag{true},
                halt_flag{true},
                step_flag{false},
                idle_flag{false},
                error_flag{false},
                single_step_flag{false},
                the_chassis{std::move(chassis)},
                save_field{},
                interrupt_enable{false},
                interrupt_deferred{false},
                interrupt_delayed{0},
                interrupt_request{false},
                greater_than_flag{false},
                field_register{},
                field_buffer{},
                interrupt_buffer{},
                cycle_state{Interrupt} {
        }

        void start_thread();

        void stop_thread() {
            run_flag = false;
            if (cpuThread) {
                if (cpuThread->joinable()) {
                    cpuThread->notify_condition();
                    cpuThread->join();
                }
            }
        }

        void run_thread();

        void fetch();

        void defer();

        void execute_iot();

        void execute_opr();

        void reset();

        void initialize();

        void stop() { halt_flag = true; }

        void tick() { cpuThread->notify_condition(); }

        void load_address(base_type address) { pc = address; }

        void deposit(base_type data);

        void instruction_cycle();

        void instruction_step();

        void sim_time(std::chrono::microseconds t) {
            if (cpuThread)
                cpuThread->sim_time += t;
        }
    };

} // namespace pdp8


#endif //CPU_SIM_CPU_H
