//
// Created by richard on 2018-08-12.
//

#ifndef CPU_SIM_PDP8_INSTRUCTION_H
#define CPU_SIM_PDP8_INSTRUCTION_H

#include "register.h"

namespace pdp8_asm {

    enum MemoryInstruction {
        AND, TAD, ISZ, DCA, JMS, JMP
    };

    enum MemoryInstructionFlags {
        ZERO, INDIRECT
    };

    enum OperateCommon {
        CLA
    };

    enum OperateGroup1 {
        NOP, IAC, RAL, RTL, RAR, RTR, BSW, CML, CMA, CIA, CLL, STL, STA,
    };

    enum OperateGroup2 {
        HLT, OSR, SKP, SNL, SZL, SZA, SNA, SMA, SPA
    };

    enum OperateGroup3 {
        CAM, MQA, MQL, SWP
    };

    enum InputOutputTransfer {
        IOT, ION, SKON, IOF, SRQ, GTF, RTF, SGT, CAF, CDF, CIF, CIDF, RDF, RIF, RIB, RMF
    };

    class pdp8_address {
    public:
        pdp8_address() = default; // LCOV_EXCL_LINE

        pdp8_address &operator++() {
            memory_addr = memory_addr() + 1;
            return *this;
        }

        template<typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        pdp8_address &operator=(T value) {
            memory_addr = value;
            return *this;
        }

        pdp8_address &operator=(const pdp8_address &address) {
            memory_addr.value = address.memory_addr.value;
            return *this;
        }

        using address_register_t = sim::hw_register<15, sim::register_output_policy<8>>;
        address_register_t memory_addr;

        sim::slice_accessor<address_register_t::base_type, sim::slice_spec<11,05,false,12>> word{memory_addr.value};
        sim::slice_accessor<address_register_t::base_type, sim::slice_spec<04,00,false,12>> page{memory_addr.value};
        sim::slice_accessor<address_register_t::base_type, sim::slice_spec<-1,-3,false,12>> field{memory_addr.value};
    };

    class pdp8_instruction {
    public:
        pdp8_instruction() = default;

        template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        explicit pdp8_instruction(T ins) : instruction(ins) {}

        template <typename T, typename = typename std::enable_if_t<std::is_integral_v<T>>>
        pdp8_instruction &set_address(T addr) {
            word = addr;
            return *this;
        }

        pdp8_instruction &operator=(const pdp8_instruction &inst) {
            instruction.value = inst.instruction.value;
            return *this;
        }

        using instruction_t = sim::hw_register<12,sim::register_output_policy<8>>;
        instruction_t instruction;
        sim::slice_accessor<instruction_t::base_type, sim::slice_spec<11,05,false,12>> word{instruction.value};
        sim::slice_accessor<instruction_t::base_type, sim::slice_spec<04,04,false,12>> zero{instruction.value};
        sim::slice_accessor<instruction_t::base_type, sim::slice_spec<03,03,false,12>> indirect{instruction.value};
        sim::slice_accessor<instruction_t::base_type, sim::slice_spec<02,00,false,12>> opcode{instruction.value};
    };

} // namespace pdp8_asm

#endif //CPU_SIM_PDP8_INSTRUCTION_H
