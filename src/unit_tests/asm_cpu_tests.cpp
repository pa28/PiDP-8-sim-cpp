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

struct instruction_state {
    std::string instruction;
    u_int16_t op_code;
};

class asmTestFixture : public ::testing::TestWithParam<instruction_state> {
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
                                instruction_state{"and 010;", 00210},
                                instruction_state{"and @ 010;", 00610},
                                instruction_state{"and !@ 010;", 00410},
                                instruction_state{"tad 010;", 01210},
                                instruction_state{"tad @ 010;", 01610},
                                instruction_state{"tad !@ 010;", 01410},
                                instruction_state{"isz 010;", 02210},
                                instruction_state{"isz @ 010;", 02610},
                                instruction_state{"isz !@ 010;", 02410},
                                instruction_state{"dca 010;", 03210},
                                instruction_state{"dca @ 010;", 03610},
                                instruction_state{"dca !@ 010;", 03410},
                                instruction_state{"jms 010;", 04210},
                                instruction_state{"jms @ 010;", 04610},
                                instruction_state{"jms !@ 010;", 04410},
                                instruction_state{"jmp 010;", 05210},
                                instruction_state{"jmp @ 010;", 05610},
                                instruction_state{"jmp !@ 010;", 05410}
                        ),);

INSTANTIATE_TEST_CASE_P(OperateInstructions, asmTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                instruction_state{"nop;", 07000},
                                instruction_state{"iac;", 07001},
                                instruction_state{"ral;", 07004},
                                instruction_state{"rtl;", 07006},
                                instruction_state{"rar;", 07010},
                                instruction_state{"rtr;", 07012},
                                instruction_state{"bsw;", 07002},
                                instruction_state{"cml;", 07020},
                                instruction_state{"cma;", 07040},
                                instruction_state{"cia;", 07041},
                                instruction_state{"cll;", 07100},
                                instruction_state{"stl;", 07120},
                                instruction_state{"cla;", 07200},
                                instruction_state{"sta;", 07240},
                                instruction_state{"cla stl;", 07320},
                                instruction_state{"sta stl;", 07360},
                                instruction_state{"ral rar;", 07014}, // ToDo: should be an error
                                instruction_state{"rtl rtr;", 07016}, // ToDo: should be an error
                                instruction_state{"hlt;", 07402},
                                instruction_state{"osr;", 07404},
                                instruction_state{"skp;", 07410},
                                instruction_state{"snl;", 07420},
                                instruction_state{"szl;", 07430},
                                instruction_state{"sza;", 07440},
                                instruction_state{"sna;", 07450},
                                instruction_state{"sma;", 07500},
                                instruction_state{"spa;", 07510},
                                instruction_state{"cla osr;", 07604},
                                instruction_state{"cam;", 07621},
                                instruction_state{"mqa;", 07501},
                                instruction_state{"mql;", 07421},
                                instruction_state{"swp;", 07521}
                        ),);

INSTANTIATE_TEST_CASE_P(InputOutputInstructions, asmTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                instruction_state{"iot;", 06000},
                                instruction_state{"ion;", 06001},
                                instruction_state{"skon;", 06000},
                                instruction_state{"iof;", 06002},
                                instruction_state{"srq;", 06003},
                                instruction_state{"gtf;", 06004},
                                instruction_state{"rtf;", 06005},
                                instruction_state{"sgt;", 06006},
                                instruction_state{"caf;", 06007}
                        ),);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
