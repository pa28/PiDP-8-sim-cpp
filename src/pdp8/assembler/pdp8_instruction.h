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

    class pdp8_instruction {
    public:
        pdp8_instruction() = default;

        template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        explicit pdp8_instruction(T ins) : instruction(ins) {}

        sim::hw_register<12,sim::register_output_policy<8>> instruction;
    };

} // namespace pdp8_asm

#endif //CPU_SIM_PDP8_INSTRUCTION_H
