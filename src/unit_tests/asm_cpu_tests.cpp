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

struct instruction_test {
    std::string instruction;
    u_int16_t op_code;
};

class asmTestFixture : public ::testing::TestWithParam<instruction_test> {
public:

    asmTestFixture() = default;

    static void SetUpTestCase() {
        // Test setup code
    }

    static void TearDownTestCase() {
        // Test tear down code
    }
};

TEST_P(asmTestFixture, OpCodes) { // NOLINT(cert-err58-cpp)
    auto param = GetParam();

    pdp8_asm::ParserProcessor<AsmParser::CodeContext, AsmLexer, AsmParser> asmProcessor;

    pali8Visitor visitor;

    std::stringstream strm{param.instruction};

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
                                instruction_test{"ral rar;", 07014}, // ToDo: should be an error
                                instruction_test{"rtl rtr;", 07016}, // ToDo: should be an error
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

    std::shared_ptr<pdp8::chassis> chassis;
};

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

    pdp8_asm::ParserProcessor<AsmParser::CodeContext, AsmLexer, AsmParser> asmProcessor;

    pali8Visitor visitor;

    std::stringstream strm{};

    strm << "start .0200; " << param.code << ".start;";

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
        visitor.clear();
        strm.str(param.memory);

        anyResult = asmProcessor.process(strm, parserRuleFunction, parserVisitorFunction);

        code_list = std::any_cast<std::vector<std::any>>(anyResult);

        ++visitor.assembler_pass;
        visitor.program_counter.memory_addr = 0;

        code_list = std::any_cast<std::vector<std::any>>(visitor.visitCode(asmProcessor.parserRule.rule));

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

INSTANTIATE_TEST_CASE_P(SingleInstructionCpu, InstructionTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                instruction_state{"and @ 0210; .010; dw 01234; .0210; dw 010; ", 01234, 0201, 07777,
                                                  ""},
                                instruction_state{"tad @ 0210; .010; dw 01234; .0210; dw 010; ", 01234, 0201, 0, ""},
                                instruction_state{"and ! 010; .010; dw 01234; ", 01234, 0201, 07777, ""},
                                instruction_state{"tad ! 010; .010; dw 01234; ", 01234, 0201, 0, ""},
                                instruction_state{"and  010; .0210; dw 01234; ", 01234, 0201, 07777, ""},
                                instruction_state{"tad  010; .0210; dw 01234; ", 01234, 0201, 0, ""},
                                instruction_state{"and !@ 010; .010; dw 0207; .0210; dw 01234; ", 01234, 0201, 07777,
                                                  ".010; dw 0210;"},
                                instruction_state{"tad !@ 010; .010; dw 0207; .0210; dw 01234; ", 01234, 0201, 0,
                                                  ".010; dw 0210;"},
                                instruction_state{"isz  010; .0210; dw 07777; ", 0, 0202, 0, ".0210; dw 0;"},
                                instruction_state{"isz  010; .0210; dw 01234; ", 0, 0201, 0, ".0210; dw 01235;"}
                        ),);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
