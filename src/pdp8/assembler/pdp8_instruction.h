//
// Created by richard on 2018-08-12.
//

#ifndef CPU_SIM_PDP8_INSTRUCTION_H
#define CPU_SIM_PDP8_INSTRUCTION_H

#include "hardware.h"

namespace pdp8_asm {

    enum MemoryInstruction {
        AND, TAD, ISZ, DCA, JMS, JMP
    };

    enum MemoryInstructionFlags {
        ZERO, INDIRECT
    };

    enum OperateGroup1 {
        NOP, IAC, RAL, RTL, RAR, RTR, BSW, CML, CMA, CIA, CLL, STL, CLA, STA,
    };

    enum OperatorGroup2 {
        HLT, OSR, SKP, SNL, SZL, SZA, SNA, SMA, SPA, CLA2
    };

    enum OperateGroup3 {
        CAM, MQA, MQL, SWP
    };

    enum InputOutputTransfer {
        IOT, ION, SKON, IOF, SRQ, GTF, RTF, CAF
    };

    class pdp8_address {
    public:
        pdp8_address() = default;

        pdp8_address &operator++() {
            memory_addr = memory_addr() + 1;
        }

        sim::hw_register<15, sim::register_output_policy<8>> memory_addr;
        static constexpr sim::hw_slice_spec<7, 0> address{};
        static constexpr sim::hw_slice_spec<5, 7> page{};
        static constexpr sim::hw_slice_spec<3, 12> field{};
    };

    class pdp8_instruction {
    public:
        pdp8_instruction() = default;

        template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        explicit pdp8_instruction(T ins) : instruction(ins) {}

        template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        pdp8_instruction &set_address(T addr) {
            instruction << address(addr);
        }

        sim::hw_register<12,sim::register_output_policy<8>> instruction;
        static constexpr sim::hw_slice_spec<7,0> address{};
        static constexpr sim::hw_slice_spec<1,8> indirect{};
        static constexpr sim::hw_slice_spec<1,7> zero{};
    };

} // namespace pdp8_asm

#endif //CPU_SIM_PDP8_INSTRUCTION_H