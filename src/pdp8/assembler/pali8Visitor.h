//
// Created by richard on 2018-08-12.
//

#ifndef CPU_SIM_PALI8VISITOR_H
#define CPU_SIM_PALI8VISITOR_H

#include <map>
#include <vector>
#include "AsmBaseVisitor.h"
#include "pdp8_instruction.h"

class pali8Visitor : public AsmBaseVisitor {
public:
    pali8Visitor() : AsmBaseVisitor{}, assembler_pass{0}, program_counter{}, symbol_table{} {}

    size_t assembler_pass;

    antlrcpp::Any returnVector(std::vector<std::any> vector);

    pdp8_asm::pdp8_address program_counter;

    std::map<std::string, pdp8_asm::pdp8_address> symbol_table;

    void set_symbol(const std::string &name, pdp8_asm::pdp8_address addr) {
        if (symbol_table.find(name) == symbol_table.end())
            symbol_table.emplace(name, pdp8_asm::pdp8_address{addr});
        else
            symbol_table[name] = addr;
    }

    template <class C>
    std::vector<std::any> visitAllChildren(C *ctx) {
        std::vector<std::any> results{};
        for ( auto const & child : ctx->children) {
            auto r = visit(child);
            if (r.has_value())
                results.push_back(r);
        }

        return results;
    }

    antlrcpp::Any visitCode(AsmParser::CodeContext *ctx) override;

    antlrcpp::Any visitStatements(AsmParser::StatementsContext *ctx) override;

    antlrcpp::Any visitStatement(AsmParser::StatementContext *ctx) override;

    antlrcpp::Any visitInstruction(AsmParser::InstructionContext *ctx) override;

    antlrcpp::Any visitPragma(AsmParser::PragmaContext *ctx) override;

    antlrcpp::Any visitSymbol(AsmParser::SymbolContext *ctx) override;

    antlrcpp::Any visitMem_op(AsmParser::Mem_opContext *ctx) override;

    antlrcpp::Any visitAddress(AsmParser::AddressContext *ctx) override;

    antlrcpp::Any visitOpr_ins(AsmParser::Opr_insContext *ctx) override;

    antlrcpp::Any visitOpr_op1(AsmParser::Opr_op1Context *ctx) override;

    antlrcpp::Any visitMem_ins(AsmParser::Mem_insContext *ctx) override;

    antlrcpp::Any visitStart(AsmParser::StartContext *ctx) override;

    antlrcpp::Any visitZero(AsmParser::ZeroContext *ctx) override {
        return pdp8_asm::ZERO;
    }

    antlrcpp::Any visitInd(AsmParser::IndContext *ctx) override {
        return pdp8_asm::INDIRECT;
    }

    antlrcpp::Any visitMem_and(AsmParser::Mem_andContext *ctx) override {
        return pdp8_asm::AND;
    }

    antlrcpp::Any visitMem_tad(AsmParser::Mem_tadContext *ctx) override {
        return pdp8_asm::TAD;
    }

    antlrcpp::Any visitMem_isz(AsmParser::Mem_iszContext *ctx) override {
        return pdp8_asm::ISZ;
    }

    antlrcpp::Any visitMem_dca(AsmParser::Mem_dcaContext *ctx) override {
        return pdp8_asm::DCA;
    }

    antlrcpp::Any visitMem_jms(AsmParser::Mem_jmsContext *ctx) override {
        return pdp8_asm::JMS;
    }

    antlrcpp::Any visitMem_jmp(AsmParser::Mem_jmpContext *ctx) override {
        return pdp8_asm::JMP;
    }

    antlrcpp::Any visitNop(AsmParser::NopContext *ctx) override {
        return pdp8_asm::NOP;
    }

    antlrcpp::Any visitIac(AsmParser::IacContext *ctx) override {
        return pdp8_asm::IAC;
    }

    antlrcpp::Any visitRal(AsmParser::RalContext *ctx) override {
        return pdp8_asm::RAL;
    }

    antlrcpp::Any visitRtl(AsmParser::RtlContext *ctx) override {
        return pdp8_asm::RTL;
    }

    antlrcpp::Any visitRar(AsmParser::RarContext *ctx) override {
        return pdp8_asm::RAR;
    }

    antlrcpp::Any visitRtr(AsmParser::RtrContext *ctx) override {
        return pdp8_asm::RTR;
    }

    antlrcpp::Any visitBsw(AsmParser::BswContext *ctx) override {
        return pdp8_asm::BSW;
    }

    antlrcpp::Any visitCml(AsmParser::CmlContext *ctx) override {
        return pdp8_asm::CML;
    }

    antlrcpp::Any visitCma(AsmParser::CmaContext *ctx) override {
        return pdp8_asm::CMA;
    }

    antlrcpp::Any visitCia(AsmParser::CiaContext *ctx) override {
        return pdp8_asm::CIA;
    }

    antlrcpp::Any visitCll(AsmParser::CllContext *ctx) override {
        return pdp8_asm::CLL;
    }

    antlrcpp::Any visitStl(AsmParser::StlContext *ctx) override {
        return pdp8_asm::STL;
    }

    antlrcpp::Any visitCla(AsmParser::ClaContext *ctx) override {
        return pdp8_asm::CLA;
    }

    antlrcpp::Any visitSta(AsmParser::StaContext *ctx) override {
        return pdp8_asm::STA;
    }

    antlrcpp::Any visitHlt(AsmParser::HltContext *ctx) override {
        return pdp8_asm::HLT;
    }

    antlrcpp::Any visitOsr(AsmParser::OsrContext *ctx) override {
        return pdp8_asm::OSR;
    }

    antlrcpp::Any visitSkp(AsmParser::SkpContext *ctx) override {
        return pdp8_asm::SKP;
    }

    antlrcpp::Any visitSnl(AsmParser::SnlContext *ctx) override {
        return pdp8_asm::SNL;
    }

    antlrcpp::Any visitSzl(AsmParser::SzlContext *ctx) override {
        return pdp8_asm::SZL;
    }

    antlrcpp::Any visitSza(AsmParser::SzaContext *ctx) override {
        return pdp8_asm::SZA;
    }

    antlrcpp::Any visitSna(AsmParser::SnaContext *ctx) override {
        return pdp8_asm::SNA;
    }

    antlrcpp::Any visitSma(AsmParser::SmaContext *ctx) override {
        return pdp8_asm::SMA;
    }

    antlrcpp::Any visitSpa(AsmParser::SpaContext *ctx) override {
        return pdp8_asm::SPA;
    }

    antlrcpp::Any visitCam(AsmParser::CamContext *ctx) override {
        return pdp8_asm::CAM;
    }

    antlrcpp::Any visitMqa(AsmParser::MqaContext *ctx) override {
        return pdp8_asm::MQA;
    }

    antlrcpp::Any visitMql(AsmParser::MqlContext *ctx) override {
        return pdp8_asm::MQL;
    }

    antlrcpp::Any visitSwp(AsmParser::SwpContext *ctx) override {
        return pdp8_asm::SWP;
    }

    antlrcpp::Any visitIot(AsmParser::IotContext *ctx) override {
        return pdp8_asm::IOT;
    }

    antlrcpp::Any visitIon(AsmParser::IonContext *ctx) override {
        return pdp8_asm::ION;
    }

    antlrcpp::Any visitSkon(AsmParser::SkonContext *ctx) override {
        return pdp8_asm::SKON;
    }

    antlrcpp::Any visitIof(AsmParser::IofContext *ctx) override {
        return pdp8_asm::IOF;
    }

    antlrcpp::Any visitSrq(AsmParser::SrqContext *ctx) override {
        return pdp8_asm::SRQ;
    }

    antlrcpp::Any visitGtf(AsmParser::GtfContext *ctx) override {
        return pdp8_asm::GTF;
    }

    antlrcpp::Any visitRtf(AsmParser::RtfContext *ctx) override {
        return pdp8_asm::RTF;
    }

    antlrcpp::Any visitCaf(AsmParser::CafContext *ctx) override {
        return pdp8_asm::CAF;
    }
};


#endif //CPU_SIM_PALI8VISITOR_H
