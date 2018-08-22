
// Generated from /mnt/v/CLionProjects/PiDP-8-sim-cpp/src/pdp8/asm_parser/Asm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "AsmParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AsmParser.
 */
class  AsmListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCode(AsmParser::CodeContext *ctx) = 0;
  virtual void exitCode(AsmParser::CodeContext *ctx) = 0;

  virtual void enterStatements(AsmParser::StatementsContext *ctx) = 0;
  virtual void exitStatements(AsmParser::StatementsContext *ctx) = 0;

  virtual void enterStatement(AsmParser::StatementContext *ctx) = 0;
  virtual void exitStatement(AsmParser::StatementContext *ctx) = 0;

  virtual void enterPragma(AsmParser::PragmaContext *ctx) = 0;
  virtual void exitPragma(AsmParser::PragmaContext *ctx) = 0;

  virtual void enterInstruction(AsmParser::InstructionContext *ctx) = 0;
  virtual void exitInstruction(AsmParser::InstructionContext *ctx) = 0;

  virtual void enterSymbol(AsmParser::SymbolContext *ctx) = 0;
  virtual void exitSymbol(AsmParser::SymbolContext *ctx) = 0;

  virtual void enterCpu_ins(AsmParser::Cpu_insContext *ctx) = 0;
  virtual void exitCpu_ins(AsmParser::Cpu_insContext *ctx) = 0;

  virtual void enterCtl_ins(AsmParser::Ctl_insContext *ctx) = 0;
  virtual void exitCtl_ins(AsmParser::Ctl_insContext *ctx) = 0;

  virtual void enterStart(AsmParser::StartContext *ctx) = 0;
  virtual void exitStart(AsmParser::StartContext *ctx) = 0;

  virtual void enterMem_ins(AsmParser::Mem_insContext *ctx) = 0;
  virtual void exitMem_ins(AsmParser::Mem_insContext *ctx) = 0;

  virtual void enterMem_op(AsmParser::Mem_opContext *ctx) = 0;
  virtual void exitMem_op(AsmParser::Mem_opContext *ctx) = 0;

  virtual void enterMem_and(AsmParser::Mem_andContext *ctx) = 0;
  virtual void exitMem_and(AsmParser::Mem_andContext *ctx) = 0;

  virtual void enterMem_tad(AsmParser::Mem_tadContext *ctx) = 0;
  virtual void exitMem_tad(AsmParser::Mem_tadContext *ctx) = 0;

  virtual void enterMem_isz(AsmParser::Mem_iszContext *ctx) = 0;
  virtual void exitMem_isz(AsmParser::Mem_iszContext *ctx) = 0;

  virtual void enterMem_dca(AsmParser::Mem_dcaContext *ctx) = 0;
  virtual void exitMem_dca(AsmParser::Mem_dcaContext *ctx) = 0;

  virtual void enterMem_jms(AsmParser::Mem_jmsContext *ctx) = 0;
  virtual void exitMem_jms(AsmParser::Mem_jmsContext *ctx) = 0;

  virtual void enterMem_jmp(AsmParser::Mem_jmpContext *ctx) = 0;
  virtual void exitMem_jmp(AsmParser::Mem_jmpContext *ctx) = 0;

  virtual void enterZero(AsmParser::ZeroContext *ctx) = 0;
  virtual void exitZero(AsmParser::ZeroContext *ctx) = 0;

  virtual void enterInd(AsmParser::IndContext *ctx) = 0;
  virtual void exitInd(AsmParser::IndContext *ctx) = 0;

  virtual void enterAddress(AsmParser::AddressContext *ctx) = 0;
  virtual void exitAddress(AsmParser::AddressContext *ctx) = 0;

  virtual void enterOpr_ins(AsmParser::Opr_insContext *ctx) = 0;
  virtual void exitOpr_ins(AsmParser::Opr_insContext *ctx) = 0;

  virtual void enterOpr_op1(AsmParser::Opr_op1Context *ctx) = 0;
  virtual void exitOpr_op1(AsmParser::Opr_op1Context *ctx) = 0;

  virtual void enterOpr_op1_ins(AsmParser::Opr_op1_insContext *ctx) = 0;
  virtual void exitOpr_op1_ins(AsmParser::Opr_op1_insContext *ctx) = 0;

  virtual void enterNop(AsmParser::NopContext *ctx) = 0;
  virtual void exitNop(AsmParser::NopContext *ctx) = 0;

  virtual void enterIac(AsmParser::IacContext *ctx) = 0;
  virtual void exitIac(AsmParser::IacContext *ctx) = 0;

  virtual void enterRal(AsmParser::RalContext *ctx) = 0;
  virtual void exitRal(AsmParser::RalContext *ctx) = 0;

  virtual void enterRtl(AsmParser::RtlContext *ctx) = 0;
  virtual void exitRtl(AsmParser::RtlContext *ctx) = 0;

  virtual void enterRar(AsmParser::RarContext *ctx) = 0;
  virtual void exitRar(AsmParser::RarContext *ctx) = 0;

  virtual void enterRtr(AsmParser::RtrContext *ctx) = 0;
  virtual void exitRtr(AsmParser::RtrContext *ctx) = 0;

  virtual void enterBsw(AsmParser::BswContext *ctx) = 0;
  virtual void exitBsw(AsmParser::BswContext *ctx) = 0;

  virtual void enterCml(AsmParser::CmlContext *ctx) = 0;
  virtual void exitCml(AsmParser::CmlContext *ctx) = 0;

  virtual void enterCma(AsmParser::CmaContext *ctx) = 0;
  virtual void exitCma(AsmParser::CmaContext *ctx) = 0;

  virtual void enterCia(AsmParser::CiaContext *ctx) = 0;
  virtual void exitCia(AsmParser::CiaContext *ctx) = 0;

  virtual void enterCll(AsmParser::CllContext *ctx) = 0;
  virtual void exitCll(AsmParser::CllContext *ctx) = 0;

  virtual void enterStl(AsmParser::StlContext *ctx) = 0;
  virtual void exitStl(AsmParser::StlContext *ctx) = 0;

  virtual void enterCla(AsmParser::ClaContext *ctx) = 0;
  virtual void exitCla(AsmParser::ClaContext *ctx) = 0;

  virtual void enterSta(AsmParser::StaContext *ctx) = 0;
  virtual void exitSta(AsmParser::StaContext *ctx) = 0;

  virtual void enterOpr_op2(AsmParser::Opr_op2Context *ctx) = 0;
  virtual void exitOpr_op2(AsmParser::Opr_op2Context *ctx) = 0;

  virtual void enterOpr_op2_ins(AsmParser::Opr_op2_insContext *ctx) = 0;
  virtual void exitOpr_op2_ins(AsmParser::Opr_op2_insContext *ctx) = 0;

  virtual void enterHlt(AsmParser::HltContext *ctx) = 0;
  virtual void exitHlt(AsmParser::HltContext *ctx) = 0;

  virtual void enterOsr(AsmParser::OsrContext *ctx) = 0;
  virtual void exitOsr(AsmParser::OsrContext *ctx) = 0;

  virtual void enterSkp(AsmParser::SkpContext *ctx) = 0;
  virtual void exitSkp(AsmParser::SkpContext *ctx) = 0;

  virtual void enterSnl(AsmParser::SnlContext *ctx) = 0;
  virtual void exitSnl(AsmParser::SnlContext *ctx) = 0;

  virtual void enterSzl(AsmParser::SzlContext *ctx) = 0;
  virtual void exitSzl(AsmParser::SzlContext *ctx) = 0;

  virtual void enterSza(AsmParser::SzaContext *ctx) = 0;
  virtual void exitSza(AsmParser::SzaContext *ctx) = 0;

  virtual void enterSna(AsmParser::SnaContext *ctx) = 0;
  virtual void exitSna(AsmParser::SnaContext *ctx) = 0;

  virtual void enterSma(AsmParser::SmaContext *ctx) = 0;
  virtual void exitSma(AsmParser::SmaContext *ctx) = 0;

  virtual void enterSpa(AsmParser::SpaContext *ctx) = 0;
  virtual void exitSpa(AsmParser::SpaContext *ctx) = 0;

  virtual void enterOpr_op3(AsmParser::Opr_op3Context *ctx) = 0;
  virtual void exitOpr_op3(AsmParser::Opr_op3Context *ctx) = 0;

  virtual void enterOpr_op3_ins(AsmParser::Opr_op3_insContext *ctx) = 0;
  virtual void exitOpr_op3_ins(AsmParser::Opr_op3_insContext *ctx) = 0;

  virtual void enterCam(AsmParser::CamContext *ctx) = 0;
  virtual void exitCam(AsmParser::CamContext *ctx) = 0;

  virtual void enterMqa(AsmParser::MqaContext *ctx) = 0;
  virtual void exitMqa(AsmParser::MqaContext *ctx) = 0;

  virtual void enterMql(AsmParser::MqlContext *ctx) = 0;
  virtual void exitMql(AsmParser::MqlContext *ctx) = 0;

  virtual void enterSwp(AsmParser::SwpContext *ctx) = 0;
  virtual void exitSwp(AsmParser::SwpContext *ctx) = 0;

  virtual void enterIot_ins(AsmParser::Iot_insContext *ctx) = 0;
  virtual void exitIot_ins(AsmParser::Iot_insContext *ctx) = 0;

  virtual void enterIot(AsmParser::IotContext *ctx) = 0;
  virtual void exitIot(AsmParser::IotContext *ctx) = 0;

  virtual void enterIon(AsmParser::IonContext *ctx) = 0;
  virtual void exitIon(AsmParser::IonContext *ctx) = 0;

  virtual void enterSkon(AsmParser::SkonContext *ctx) = 0;
  virtual void exitSkon(AsmParser::SkonContext *ctx) = 0;

  virtual void enterIof(AsmParser::IofContext *ctx) = 0;
  virtual void exitIof(AsmParser::IofContext *ctx) = 0;

  virtual void enterSrq(AsmParser::SrqContext *ctx) = 0;
  virtual void exitSrq(AsmParser::SrqContext *ctx) = 0;

  virtual void enterGtf(AsmParser::GtfContext *ctx) = 0;
  virtual void exitGtf(AsmParser::GtfContext *ctx) = 0;

  virtual void enterRtf(AsmParser::RtfContext *ctx) = 0;
  virtual void exitRtf(AsmParser::RtfContext *ctx) = 0;

    virtual void enterSgt(AsmParser::SgtContext *ctx) = 0;

    virtual void exitSgt(AsmParser::SgtContext *ctx) = 0;

  virtual void enterCaf(AsmParser::CafContext *ctx) = 0;
  virtual void exitCaf(AsmParser::CafContext *ctx) = 0;

    virtual void enterDef_const(AsmParser::Def_constContext *ctx) = 0;

    virtual void exitDef_const(AsmParser::Def_constContext *ctx) = 0;

    virtual void enterDw(AsmParser::DwContext *ctx) = 0;

    virtual void exitDw(AsmParser::DwContext *ctx) = 0;

  virtual void enterEol(AsmParser::EolContext *ctx) = 0;
  virtual void exitEol(AsmParser::EolContext *ctx) = 0;


};

