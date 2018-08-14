
// Generated from /mnt/v/CLionProjects/PiDP-8-sim-cpp/src/pdp8/asm_parser/Asm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "AsmVisitor.h"


/**
 * This class provides an empty implementation of AsmVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  AsmBaseVisitor : public AsmVisitor {
public:

  virtual antlrcpp::Any visitCode(AsmParser::CodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatements(AsmParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(AsmParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

    virtual antlrcpp::Any visitPragma(AsmParser::PragmaContext *ctx) override {
      return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitInstruction(AsmParser::InstructionContext *ctx) override {
      return visitChildren(ctx);
    }

  virtual antlrcpp::Any visitSymbol(AsmParser::SymbolContext *ctx) override {
    return visitChildren(ctx);
  }

    virtual antlrcpp::Any visitCpu_ins(AsmParser::Cpu_insContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCtl_ins(AsmParser::Ctl_insContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStart(AsmParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMem_ins(AsmParser::Mem_insContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMem_op(AsmParser::Mem_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMem_and(AsmParser::Mem_andContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMem_tad(AsmParser::Mem_tadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMem_isz(AsmParser::Mem_iszContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMem_dca(AsmParser::Mem_dcaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMem_jms(AsmParser::Mem_jmsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMem_jmp(AsmParser::Mem_jmpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitZero(AsmParser::ZeroContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInd(AsmParser::IndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddress(AsmParser::AddressContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpr_ins(AsmParser::Opr_insContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpr_op1(AsmParser::Opr_op1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpr_op1_ins(AsmParser::Opr_op1_insContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNop(AsmParser::NopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIac(AsmParser::IacContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRal(AsmParser::RalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRtl(AsmParser::RtlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRar(AsmParser::RarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRtr(AsmParser::RtrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBsw(AsmParser::BswContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCml(AsmParser::CmlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCma(AsmParser::CmaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCia(AsmParser::CiaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCll(AsmParser::CllContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStl(AsmParser::StlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCla(AsmParser::ClaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSta(AsmParser::StaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpr_op2(AsmParser::Opr_op2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpr_op2_ins(AsmParser::Opr_op2_insContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHlt(AsmParser::HltContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOsr(AsmParser::OsrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSkp(AsmParser::SkpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSnl(AsmParser::SnlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSzl(AsmParser::SzlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSza(AsmParser::SzaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSna(AsmParser::SnaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSma(AsmParser::SmaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpa(AsmParser::SpaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpr_op3(AsmParser::Opr_op3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpr_op3_ins(AsmParser::Opr_op3_insContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCam(AsmParser::CamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMqa(AsmParser::MqaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMql(AsmParser::MqlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSwp(AsmParser::SwpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIot_ins(AsmParser::Iot_insContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIot(AsmParser::IotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIon(AsmParser::IonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSkon(AsmParser::SkonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIof(AsmParser::IofContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSrq(AsmParser::SrqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGtf(AsmParser::GtfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRtf(AsmParser::RtfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCaf(AsmParser::CafContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEol(AsmParser::EolContext *ctx) override {
    return visitChildren(ctx);
  }


};

