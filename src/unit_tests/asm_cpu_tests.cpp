#include <utility>

//
// Created by richard on 2018-08-22.
//

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include "antlr4-runtime.h"
#include "AsmLexer.h"
#include "AsmParser.h"
#include "pali8Visitor.h"
#include "ParserProcessor.h"
#include "pdp8.h"
#include "chassis.h"
#include "cpu.h"

template<class Param>
class cpuTestFixture : public ::testing::TestWithParam<Param> {
public:

    cpuTestFixture() {
        chassis = pdp8::chassis::make_chassis();
    }

    void SetUp() override {
        chassis->initialize();
    }

    static void SetUpTestCase() {
    }

    static void TearDownTestCase() {
    }

    std::vector<std::any> assembler(std::stringstream &strm) {
        pdp8_asm::ParserProcessor<AsmParser::CodeContext, AsmLexer, AsmParser> asmProcessor;

        pali8Visitor visitor;

        auto parserRuleFunction =
                [](pdp8_asm::ParserRule<AsmParser::CodeContext, AsmLexer, AsmParser> &rule) -> auto {
                    return rule.parser->code();
                };

        auto parserVisitorFunction =
                [&visitor](pdp8_asm::ParserRule<AsmParser::CodeContext, AsmLexer, AsmParser> &rule) -> auto {
                    return visitor.visitCode(rule.rule);
                };

        auto anyResult = asmProcessor.process(strm, parserRuleFunction, parserVisitorFunction);

        auto code_list = std::any_cast<std::vector<std::any>>(anyResult);

        ++visitor.assembler_pass;
        visitor.program_counter.memory_addr = 0;

        code_list = std::any_cast<std::vector<std::any>>(visitor.visitCode(asmProcessor.parserRule.rule));

        return code_list;
    }

    void set_memory(std::vector<std::any> &&code_list) {
        for (auto code : code_list) {
            if (code.type() == typeid(pdp8_asm::pdp8_instruction)) {
                auto instruction = std::any_cast<pdp8_asm::pdp8_instruction>(code);
                chassis->cpu->deposit(instruction.instruction());
            } else if (code.type() == typeid(pdp8_asm::pdp8_address)) {
                chassis->cpu->load_address(std::any_cast<pdp8_asm::pdp8_address>(code).memory_addr());
            }
        }
    }

    std::shared_ptr<pdp8::chassis> chassis;
};

struct instruction_test {
    std::string instruction;
    u_int16_t op_code;
};

class asmErrFixture : public cpuTestFixture<instruction_test> {
};

TEST_P(asmErrFixture, AssemblerErrors) { // NOLINT(cert-err58-cpp)
    auto param = GetParam();

    std::stringstream strm{param.instruction};

    EXPECT_THROW(assembler(strm), std::exception); // NOLINT(cppcoreguidelines-avoid-goto)
}

INSTANTIATE_TEST_CASE_P(AssemberErrors, asmErrFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
//                                instruction_test{"junk;", 0}
                                instruction_test{".0200; tad 0400;", 0},     // Off-page addressing
                                instruction_test{".0200; tad ! 0210;", 0},   // Off-page 0 addressing
                                instruction_test{"ral rar;", 07014},         // Microcode not allowed
                                instruction_test{"rtl rtr;", 07016}          // Microcode not allowed
                        ),);

class asmTestFixture : public cpuTestFixture<instruction_test> {
};

TEST_P(asmTestFixture, OpCodes) { // NOLINT(cert-err58-cpp)
    auto param = GetParam();

    std::stringstream strm{param.instruction};

    auto code_list = assembler(strm);

    EXPECT_EQ(param.op_code, std::any_cast<pdp8_asm::pdp8_instruction>(code_list.front()).instruction());
}

INSTANTIATE_TEST_CASE_P(MemoryInstructions, asmTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                instruction_test{"and 010;", 00210},
                                instruction_test{"and @ 010;", 00610},
                                instruction_test{"and !@ 010;", 00410},
                                instruction_test{"tad 010;", 01210},
                                instruction_test{"tad @ 010;", 01610},
                                instruction_test{"tad !@ 010;", 01410},
                                instruction_test{"isz 010;", 02210},
                                instruction_test{"isz @ 010;", 02610},
                                instruction_test{"isz !@ 010;", 02410},
                                instruction_test{"dca 010;", 03210},
                                instruction_test{"dca @ 010;", 03610},
                                instruction_test{"dca !@ 010;", 03410},
                                instruction_test{"jms 010;", 04210},
                                instruction_test{"jms @ 010;", 04610},
                                instruction_test{"jms !@ 010;", 04410},
                                instruction_test{"jmp 010;", 05210},
                                instruction_test{"jmp @ 010;", 05610},
                                instruction_test{"jmp !@ 010;", 05410}
                        ),);

INSTANTIATE_TEST_CASE_P(OperateInstructions, asmTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                instruction_test{"nop;", 07000},
                                instruction_test{"iac;", 07001},
                                instruction_test{"ral;", 07004},
                                instruction_test{"rtl;", 07006},
                                instruction_test{"rar;", 07010},
                                instruction_test{"rtr;", 07012},
                                instruction_test{"bsw;", 07002},
                                instruction_test{"cml;", 07020},
                                instruction_test{"cma;", 07040},
                                instruction_test{"cia;", 07041},
                                instruction_test{"cll;", 07100},
                                instruction_test{"stl;", 07120},
                                instruction_test{"cla;", 07200},
                                instruction_test{"sta;", 07240},
                                instruction_test{"cla stl;", 07320},
                                instruction_test{"sta stl;", 07360},
                                instruction_test{"hlt;", 07402},
                                instruction_test{"osr;", 07404},
                                instruction_test{"skp;", 07410},
                                instruction_test{"snl;", 07420},
                                instruction_test{"szl;", 07430},
                                instruction_test{"sza;", 07440},
                                instruction_test{"sna;", 07450},
                                instruction_test{"sma;", 07500},
                                instruction_test{"spa;", 07510},
                                instruction_test{"cla osr;", 07604},
                                instruction_test{"cam;", 07621},
                                instruction_test{"mqa;", 07501},
                                instruction_test{"mql;", 07421},
                                instruction_test{"swp;", 07521}
                        ),);

INSTANTIATE_TEST_CASE_P(InputOutputInstructions, asmTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                instruction_test{"iot;", 06000},
                                instruction_test{"ion;", 06001},
                                instruction_test{"skon;", 06000},
                                instruction_test{"iof;", 06002},
                                instruction_test{"srq;", 06003},
                                instruction_test{"gtf;", 06004},
                                instruction_test{"rtf;", 06005},
                                instruction_test{"sgt;", 06006},
                                instruction_test{"caf;", 06007}
                        ),);

struct instruction_state {
    instruction_state(std::string code, int acl, int pc, int acl_start, std::string memory)
            : code{std::move(code)}, memory{std::move(memory)}, acl{acl}, pc{pc},
              acl_start{acl_start} {}

    std::string code, memory;
    pdp8::register_t acl, pc, acl_start;
};

class InstructionTestFixture : public cpuTestFixture<instruction_state> {
};

TEST_P(InstructionTestFixture, SingleInstructionCpu) { // NOLINT(cert-err58-cpp)
    auto param = GetParam();

    std::stringstream strm{};

    strm << "start .0200; " << param.code << ".start;";

    auto code_list = assembler(strm);

    for (auto code : code_list) {
        if (code.type() == typeid(pdp8_asm::pdp8_instruction)) {
            auto instruction = std::any_cast<pdp8_asm::pdp8_instruction>(code);
            chassis->cpu->deposit(instruction.instruction());
        } else if (code.type() == typeid(pdp8_asm::pdp8_address)) {
            chassis->cpu->load_address(std::any_cast<pdp8_asm::pdp8_address>(code).memory_addr());
        }
    }

    chassis->cpu->acl = param.acl_start;
    chassis->cpu->instruction_cycle();

    EXPECT_EQ(param.acl[chassis->cpu->ac_link], chassis->cpu->acl[chassis->cpu->ac_link]);
    EXPECT_EQ(param.pc[chassis->cpu->mem_word], chassis->cpu->pc[chassis->cpu->mem_word]);

    if (not param.memory.empty()) {
        strm.str(param.memory);

        code_list = assembler(strm);

        for (auto code : code_list) {
            if (code.type() == typeid(pdp8_asm::pdp8_instruction)) {
                auto instruction = std::any_cast<pdp8_asm::pdp8_instruction>(code);
                EXPECT_EQ(instruction.instruction(), chassis->cpu->examine());
            } else if (code.type() == typeid(pdp8_asm::pdp8_address)) {
                chassis->cpu->load_address(std::any_cast<pdp8_asm::pdp8_address>(code).memory_addr());
            }
        }
    }
}

INSTANTIATE_TEST_CASE_P(SingleInstructionCpuMem, InstructionTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                instruction_state{"and @ 0210; .010; dw 01234; .0210; dw 010; ", 01234, 0201, 07777,
                                                  ""},
                                instruction_state{"tad @ 0210; .010; dw 01234; .0210; dw 010; ", 01234, 0201, 0, ""},
                                instruction_state{"and ! 010; .010; dw 01234; ", 01234, 0201, 07777, ""},
                                instruction_state{"tad ! 010; .010; dw 01234; ", 01234, 0201, 0, ""},
                                instruction_state{"and  0210; .0210; dw 01234; ", 01234, 0201, 07777, ""},
                                instruction_state{"tad  0210; .0210; dw 01234; ", 01234, 0201, 0, ""},
                                instruction_state{"and !@ 010; .010; dw 0207; .0210; dw 01234; ", 01234, 0201, 07777,
                                                  ".010; dw 0210;"},
                                instruction_state{"tad !@ 010; .010; dw 0207; .0210; dw 01234; ", 01234, 0201, 0,
                                                  ".010; dw 0210;"},
                                instruction_state{"isz  0210; .0210; dw 07777; ", 0, 0202, 0, ".0210; dw 0;"},
                                instruction_state{"isz  0210; .0210; dw 01234; ", 0, 0201, 0, ".0210; dw 01235;"},
                                instruction_state{"dca  0210; ", 0, 0201, 01234, ".0210; dw 01234;"},
                                instruction_state{"dca ! 010; ", 0, 0201, 01234, ".010; dw 01234;"},
                                instruction_state{"dca @ 0210; .0210; dw 0211;", 0, 0201, 01234, ".0211; dw 01234;"},
                                instruction_state{"dca !@ 010; .010; dw 0207;", 0, 0201, 01234,
                                                  ".0210; dw 01234; .010; dw 0210;"},
                                instruction_state{"jmp  0210; ", 0, 0210, 0, ""},
                                instruction_state{"jmp ! 010; ", 0, 0010, 0, ""},
                                instruction_state{"jmp @ 0210; .0210; dw 0310;", 0, 0310, 0, ""},
                                instruction_state{"jmp !@ 010; .010; dw 0207;", 0, 0210, 0, ""},
                                instruction_state{"jms  0210; ", 0, 0211, 0, ".0210; dw 0201;"},
                                instruction_state{"jms ! 010; ", 0, 0011, 0, ".0010; dw 0201;"},
                                instruction_state{"jms @ 0210; .0210; dw 0310;", 0, 0311, 0, ".0310; dw 0201;"},
                                instruction_state{"jms !@ 010; .010; dw 0207;", 0, 0211, 0,
                                                  ".0210; dw 0201; .010; dw 0210;"}
                        ),);

INSTANTIATE_TEST_CASE_P(SingleInstructionCpuOpr1, InstructionTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                instruction_state{"nop;", 0, 0201, 0, ""},
                                instruction_state{"iac;", 0, 0201, 07777, ""},
                                instruction_state{"ral;", 010000, 0201, 04000, ""},
                                instruction_state{"rtl;", 01, 0201, 04000, ""},
                                instruction_state{"rar;", 010000, 0201, 01, ""},
                                instruction_state{"rtr;", 04000, 0201, 01, ""},
                                instruction_state{"bsw;", 03412, 0201, 01234, ""},
                                instruction_state{"cml;", 010000, 0201, 0, ""},
                                instruction_state{"cml;", 0, 0201, 010000, ""},
                                instruction_state{"cma;", 07777, 0201, 0, ""},
                                instruction_state{"cma;", 0, 0201, 07777, ""},
                                instruction_state{"cma;", 06543, 0201, 01234, ""},
                                instruction_state{"cia;", 0, 0201, 0, ""},
                                instruction_state{"cia;", 06544, 0201, 01234, ""},
                                instruction_state{"cll;", 01234, 0201, 011234, ""},
                                instruction_state{"stl;", 011234, 0201, 01234, ""},
                                instruction_state{"cla;", 010000, 0201, 011234, ""},
                                instruction_state{"sta;", 07777, 0201, 01234, ""}
                        ),);

INSTANTIATE_TEST_CASE_P(SingleInstructionCpuOpr2, InstructionTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                instruction_state{"hlt;", 01234, 0201, 01234, ""},
                                // ToDo: OSR
                                instruction_state{"skp;", 01234, 0202, 01234, ""},
                                instruction_state{"snl;", 011234, 0202, 011234, ""},
                                instruction_state{"snl;", 01234, 0201, 01234, ""},
                                instruction_state{"szl;", 01234, 0202, 01234, ""},
                                instruction_state{"szl;", 011234, 0201, 011234, ""},
                                instruction_state{"sza;", 011234, 0201, 011234, ""},
                                instruction_state{"sza;", 010000, 0202, 010000, ""},
                                instruction_state{"sna;", 01234, 0202, 01234, ""},
                                instruction_state{"sna;", 0, 0201, 0, ""},
                                instruction_state{"sma;", 01234, 0201, 01234, ""},
                                instruction_state{"sma;", 05234, 0202, 05234, ""},
                                instruction_state{"spa;", 01234, 0202, 01234, ""},
                                instruction_state{"spa;", 05234, 0201, 05234, ""},
                                instruction_state{"cla hlt;", 0, 0201, 01234, ""}
                        ),);

/*
INSTANTIATE_TEST_CASE_P(SingleInstructionCpuOpr3, InstructionTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                // ToDo: Implement group 3 instructions.
                        ),);
*/

struct iot_test_data {
    std::string code;
    int cpu_cycles;
    bool int_f_b, int_f_e, int_req;
    uint16_t pc;
};

class IotTestFixture : public cpuTestFixture<iot_test_data> {
};

TEST_P(IotTestFixture, IotInstructionCpu) { // NOLINT(cert-err58-cpp)
    auto param = GetParam();

    std::stringstream strm{};

    strm << "start .0200; " << param.code << ".start;";

    auto code_list = assembler(strm);

    for (auto code : code_list) {
        if (code.type() == typeid(pdp8_asm::pdp8_instruction)) {
            auto instruction = std::any_cast<pdp8_asm::pdp8_instruction>(code);
            chassis->cpu->deposit(instruction.instruction());
        } else if (code.type() == typeid(pdp8_asm::pdp8_address)) {
            chassis->cpu->load_address(std::any_cast<pdp8_asm::pdp8_address>(code).memory_addr());
        }
    }

    chassis->cpu->interrupt_enable = param.int_f_b;
    chassis->cpu->interrupt_request = param.int_req;
    for (int n = 0; n < param.cpu_cycles; ++n)
        chassis->cpu->instruction_cycle();
    EXPECT_EQ(param.int_f_e, chassis->cpu->interrupt_enable);
    EXPECT_EQ(param.pc, chassis->cpu->pc());
}

INSTANTIATE_TEST_CASE_P(SingleInstructionCpuIOT, IotTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                iot_test_data{"ion; nop; nop;", 3, false, true, false, 0203},
                                iot_test_data{"skon;", 1, true, false, false, 0202},
                                iot_test_data{"skon;", 1, false, false, false, 0201},
                                iot_test_data{"iof;", 1, true, false, false, 0201},
                                iot_test_data{"srq;", 1, false, false, false, 0201},
                                iot_test_data{"srq;", 1, false, false, true, 0202}
                        ),);

struct RemainderTestData {
    bool enable;
};

class RemainderTestFixture : public cpuTestFixture<RemainderTestData> {
};

TEST_P(RemainderTestFixture, RemainderTests) { // NOLINT(cert-err58-cpp)
    auto param = GetParam();

    if (param.enable) {
        std::stringstream strm;

        strm.str("start .0200; dw 06251; .start;");
        set_memory(assembler(strm));
        chassis->cpu->instruction_cycle();
        EXPECT_EQ(05, chassis->cpu->field_register[chassis->cpu->sf_df]());

        strm.str("start .0200; dw 06252; .start;");
        set_memory(assembler(strm));
        chassis->cpu->instruction_cycle();
        EXPECT_EQ(05, chassis->cpu->field_buffer[chassis->cpu->sf_if]());

        chassis->cpu->field_register = 0;
        chassis->cpu->field_buffer = 0;
        strm.str("start .0200; dw 06253; .start;");
        set_memory(assembler(strm));
        chassis->cpu->instruction_cycle();
        EXPECT_EQ(05, chassis->cpu->field_register[chassis->cpu->sf_df]());
        EXPECT_EQ(05, chassis->cpu->field_buffer[chassis->cpu->sf_if]());

        strm.str("start .0200; rdf; .start;");
        set_memory(assembler(strm));
        chassis->cpu->instruction_cycle();
        EXPECT_EQ(05, chassis->cpu->acl[chassis->cpu->op_field]());

        strm.str("start .0200; rif; .start;");
        set_memory(assembler(strm));
        chassis->cpu->instruction_cycle();
        EXPECT_EQ(0, chassis->cpu->acl[chassis->cpu->op_field]());

        strm.str("start .0200; rib; .start;");
        set_memory(assembler(strm));
        chassis->cpu->instruction_cycle();
        EXPECT_EQ(0, chassis->cpu->acl[chassis->cpu->op_field]());

        strm.str("start .0200; rmf; .start;");
        set_memory(assembler(strm));
        chassis->cpu->instruction_cycle();
        EXPECT_EQ(0, chassis->cpu->field_register[chassis->cpu->sf_df]());
        EXPECT_EQ(0, chassis->cpu->field_buffer[chassis->cpu->sf_if]());
    }
}

INSTANTIATE_TEST_CASE_P(RemainderTests, RemainderTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(RemainderTestData{true}
                        ),);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
