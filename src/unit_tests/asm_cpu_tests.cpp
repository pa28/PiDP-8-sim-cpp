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
#include "DK8EA.h"

template<class Param>
class cpuTestFixture : public ::testing::TestWithParam<Param> {
public:

    cpuTestFixture() : pc_boundary{0}, dk8ea_mode_a{false} {
        chassis = pdp8::chassis::make_chassis();
    }

    void SetUp() override {
        chassis->reset();
        chassis->initialize();
    }

    static void SetUpTestCase() {
    }

    static void TearDownTestCase() {
    }

    std::vector<std::any> assembler(std::stringstream &strm) {
        pdp8_asm::ParserProcessor<AsmParser::CodeContext, AsmLexer, AsmParser> asmProcessor;

        pali8Visitor visitor;
        visitor.dk8ea_mode = dk8ea_mode_a ? pdp8::DK8EA::DK8EA_Mode_A : pdp8::DK8EA::DK8EA_Mode_P;

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

        if (visitor.symbol_table.find("END") == visitor.symbol_table.end()) {
            pc_boundary = 0;
        } else {
            pc_boundary = visitor.symbol_table.at("END").memory_addr();
        }

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

    void test_memory(std::vector<std::any> &&code_list) {
        for (auto code : code_list) {
            if (code.type() == typeid(pdp8_asm::pdp8_instruction)) {
                auto instruction = std::any_cast<pdp8_asm::pdp8_instruction>(code);
                EXPECT_EQ(instruction.instruction(), chassis->cpu->examine());
            } else if (code.type() == typeid(pdp8_asm::pdp8_address)) {
                chassis->cpu->load_address(std::any_cast<pdp8_asm::pdp8_address>(code).memory_addr());
            }
        }
    }

    std::shared_ptr<pdp8::chassis> chassis;
    u_int16_t pc_boundary;
    bool dk8ea_mode_a;
};

struct instruction_test {
    instruction_test(std::string ins, u_int16_t op, bool mode = false) : instruction{std::move(ins)}, op_code{op},
                                                                         dk8ea_mode_a{mode} {}

    std::string instruction;
    u_int16_t op_code;
    bool dk8ea_mode_a;
};

class asmErrFixture : public cpuTestFixture<instruction_test> {
};

TEST_P(asmErrFixture, AssemblerErrors) { // NOLINT(cert-err58-cpp)
    auto param = GetParam();
    dk8ea_mode_a = param.dk8ea_mode_a;

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
    dk8ea_mode_a = param.dk8ea_mode_a;

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
                                instruction_test{"caf;", 06007},
                                instruction_test{"cdf;", 06201},
                                instruction_test{"cif;", 06202},
                                instruction_test{"cidf;", 06203},
                                instruction_test{"clsf;", 06050},
                                instruction_test{"clei;", 06051},
                                instruction_test{"cldi;", 06052},
                                instruction_test{"clsc;", 06053},
                                instruction_test{"clsi;", 06054},
                                instruction_test{"clsm;", 06055},
                                instruction_test{"rand;", 06056},
                                instruction_test{"clsk;", 06057},
                                instruction_test{"clei;", 06051, true},
                                instruction_test{"cldi;", 06052, true},
                                instruction_test{"clsc;", 06053, true},
                                instruction_test{"clle;", 06055, true},
                                instruction_test{"clcl;", 06056, true}
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

    set_memory(assembler(strm));
    chassis->cpu->acl = param.acl_start;
    chassis->cpu->instruction_cycle();

    EXPECT_EQ(param.acl[chassis->cpu->ac_link], chassis->cpu->acl[chassis->cpu->ac_link]);
    EXPECT_EQ(param.pc[chassis->cpu->mem_word], chassis->cpu->pc[chassis->cpu->mem_word]);

    if (not param.memory.empty()) {
        strm.str(param.memory);

        test_memory(assembler(strm));
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

    set_memory(assembler(strm));

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
                                iot_test_data{"srq;", 1, false, false, true, 0202},
                                // ToDo: The next four will need more comprehensive tests.
                                iot_test_data{"gtf;", 1, false, false, false, 0201},
                                iot_test_data{"rtf;", 1, false, false, false, 0201},
                                iot_test_data{"sgt;", 1, false, false, false, 0201},
                                iot_test_data{"sgt;", 1, false, false, false, 0201}
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

        chassis->cpu->sr = 01234;
        strm.str("start .0200; cla osr; .start;");
        set_memory(assembler(strm));
        chassis->cpu->instruction_cycle();
        EXPECT_EQ(01234, chassis->cpu->acl[chassis->cpu->cpu_word]);
        chassis->cpu->acl = 0;

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

struct ProgramTestData {
    pdp8::DK8EA::DK8EA_Constants clk_mode;
    std::string program, results;
};

class ProgramTestFixture : public cpuTestFixture<ProgramTestData> {
    void SetUp() override {
        auto param = GetParam();
        chassis->add_device<pdp8::DK8EA>(pdp8::INT_V_CLK, param.clk_mode);
        chassis->reset();
        chassis->initialize();
    }

    void TearDown() override {
        chassis->stop();
        chassis->stop_threads();
    }
};

/**
 * @brief Run test programs.
 * @details A test program must terminate with a HLT instruction. If the accumulator contains zero at halt the
 * test has failed. Optionally a memory configuration test can also be specified. The test program will be
 * configured to start at 00200. A PC boundary value may be specified. If the PC is >= the boundary during a fetch
 * cycle the CPU will abort with a std::logic_error exception.
 */
TEST_P(ProgramTestFixture, ProgramTests) { // NOLINT(cert-err58-cpp)
    auto param = GetParam();
    std::stringstream strm;

    /**
     * Prepare the test program to load and start at 0200 and set the pc_boundary
     */
    strm << "start .0200; " << param.program << "END hlt; .start;";

    set_memory(assembler(strm));
    chassis->cpu->pc_boundary = pc_boundary;

    /**
     * Start chassis threads, then issue the start command
     */
    chassis->start_threads();
    chassis->start();

    /**
     * Wait until the next time the CPU writes the status lights with the run flag false.
     */
    chassis->status_lights.wait_on_data_state([](pdp8::chassis::status_lights_t::data_ptr_t const &data_ptr) -> bool {
        return data_ptr->get_run_flag();
    });

    /**
     * Get the test values from the status lights.
     */
    pdp8::register_t acl{};
    chassis->status_lights.read_data([&](pdp8::chassis::status_lights_t::data_ptr_t const &data_ptr) -> void {
        acl = data_ptr->get_acl();
    });

    EXPECT_NE(0, acl());

    /**
     * Compare the current memory state to the required state.
     */
    if (not param.results.empty()) {
        strm.str(param.results);
        test_memory(assembler(strm));
    }
}

INSTANTIATE_TEST_CASE_P(ProgramTests, ProgramTestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                ProgramTestData{pdp8::DK8EA::DK8EA_Mode_P, "rand; loop clsc; jmp loop; sta; hlt;", ""},
                                ProgramTestData{pdp8::DK8EA::DK8EA_Mode_P,
                                                " .0; dw 0014; .0200; cla; tad ! 0; clsf; CLA CLL CML RTL; clsi; CLA CLL CML RTL; clsm;"
                                                " loop clsc; jmp loop; sta; hlt;",
                                        ""},
                                ProgramTestData{pdp8::DK8EA::DK8EA_Mode_P,
                                                " .0; dw 0004; .0200; cla; tad ! 0; clsf; CLA CLL CML RTL; clsi; CLA CLL CML RTL; clsm;"
                                                " loop clsc; jmp loop; sta; hlt;",
                                                ""},
                                ProgramTestData{pdp8::DK8EA::DK8EA_Mode_P,
                                                " .0; dw 0012; .0200; cla; tad ! 0; clsf; CLA CLL CML RTL; clsi; CLA CLL CML RTL; clsm;"
                                                " loop clsc; jmp loop; sta; hlt;",
                                                ""},
                                ProgramTestData{pdp8::DK8EA::DK8EA_Mode_P,
                                                " .0; dw 0002; .0200; cla; tad ! 0; clsf; CLA CLL CML RTL; clsi; CLA CLL CML RTL; clsm;"
                                                " loop clsc; jmp loop; sta; hlt;",
                                                ""},
                                ProgramTestData{pdp8::DK8EA::DK8EA_Mode_P,
                                                ".01; sta; hlt; .0200; clei; ion; loop jmp loop; hlt;", ".0; dw 0203;"},
                                ProgramTestData{pdp8::DK8EA::DK8EA_Mode_P,
                                                "cla; dca ! 0; loop cla cma; isz !0; jmp loop; hlt;", ""}
                        ),);

struct DK8EATestData {
    pdp8::DK8EA::DK8EA_Constants mode;
};

class DK8EATestFixture : public cpuTestFixture<DK8EATestData> {
    void SetUp() override {
        auto param = GetParam();
        chassis->add_device<pdp8::DK8EA>(pdp8::INT_V_CLK, param.mode);
        chassis->reset();
        chassis->initialize();
    }

    void TearDown() override {
    }
};

TEST_P(DK8EATestFixture, DK8EATestData) { // NOLINT(cert-err58-cpp)
    auto param = GetParam();

    switch (param.mode) {
        case pdp8::DK8EA::DK8EA_Mode_P: {
            auto ac = chassis->dispatch(pdp8::INT_V_CLK, 7, 0); // CLRF
            EXPECT_EQ(pdp8::DK8EA::CLK_INT_FUNDAMENTAL, ac);

            chassis->dispatch(pdp8::INT_V_CLK, 1, 0); // CLEI
            chassis->device_tick();
            EXPECT_TRUE(chassis->cpu->interrupt_request);

            chassis->cpu->pc = 0;
            chassis->dispatch(pdp8::INT_V_CLK, 3, 0); // CLSC
            EXPECT_FALSE(chassis->cpu->interrupt_request);
            EXPECT_EQ(01, chassis->cpu->pc());

            chassis->dispatch(pdp8::INT_V_CLK, 2, 0); // CLDI
            chassis->device_tick();
            EXPECT_FALSE(chassis->cpu->interrupt_request);
            chassis->dispatch(pdp8::INT_V_CLK, 3, 0); // CLSC

            chassis->dispatch(pdp8::INT_V_CLK, 4, 3); // CLSI
            ac = chassis->dispatch(pdp8::INT_V_CLK, 4, 3); // CLSI
            EXPECT_EQ(3, ac);

            chassis->dispatch(pdp8::INT_V_CLK, 5, 2); // CLSM
            ac = chassis->dispatch(pdp8::INT_V_CLK, 5, 2); // CLSM
            EXPECT_EQ(2, ac);
            chassis->dispatch(pdp8::INT_V_CLK, 0, 014); // CLSF seq multi
            chassis->dispatch(pdp8::INT_V_CLK, 1, 0); // CLEI

            for (int i = 0; i < 5; ++i) {
                EXPECT_FALSE(chassis->cpu->interrupt_request);
                chassis->device_tick();
            }
            EXPECT_TRUE(chassis->cpu->interrupt_request);

            ac = chassis->dispatch(pdp8::INT_V_CLK, 6, 3); // RAND
            EXPECT_LE(0, ac);
        }
            break;
        case pdp8::DK8EA::DK8EA_Mode_A: {
            chassis->dispatch(pdp8::INT_V_CLK, 1, 0); // CLEI
            chassis->device_tick();
            EXPECT_TRUE(chassis->cpu->interrupt_request);

            chassis->cpu->pc = 0;
            chassis->dispatch(pdp8::INT_V_CLK, 3, 0); // CLSC
            EXPECT_FALSE(chassis->cpu->interrupt_request);
            EXPECT_EQ(01, chassis->cpu->pc());

            chassis->dispatch(pdp8::INT_V_CLK, 2, 0); // CLDI
            chassis->device_tick();
            EXPECT_FALSE(chassis->cpu->interrupt_request);
            chassis->dispatch(pdp8::INT_V_CLK, 3, 0); // CLSC

            chassis->dispatch(pdp8::INT_V_CLK, 6, 0); // CLCL
            chassis->device_tick();
            EXPECT_FALSE(chassis->cpu->interrupt_request);
            chassis->dispatch(pdp8::INT_V_CLK, 3, 0); // CLSC

            chassis->dispatch(pdp8::INT_V_CLK, 5, 1); // CLLE 1
            chassis->device_tick();
            EXPECT_TRUE(chassis->cpu->interrupt_request);

            chassis->cpu->pc = 0;
            chassis->dispatch(pdp8::INT_V_CLK, 7, 0); // CLSK
            EXPECT_TRUE(chassis->cpu->interrupt_request);
            EXPECT_EQ(01, chassis->cpu->pc());

            chassis->dispatch(pdp8::INT_V_CLK, 5, 0); // CLLE 0
            chassis->device_tick();
            EXPECT_FALSE(chassis->cpu->interrupt_request);
        }
            break;
    }
}

INSTANTIATE_TEST_CASE_P(DK8EATests, DK8EATestFixture, // NOLINT(cert-err58-cpp)
                        testing::Values(
                                DK8EATestData{pdp8::DK8EA::DK8EA_Mode_P},
                                DK8EATestData{pdp8::DK8EA::DK8EA_Mode_A}
                        ),);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
