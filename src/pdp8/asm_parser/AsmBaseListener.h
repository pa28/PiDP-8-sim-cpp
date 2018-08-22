
// Generated from /mnt/v/CLionProjects/PiDP-8-sim-cpp/src/pdp8/asm_parser/Asm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "AsmListener.h"


/**
 * This class provides an empty implementation of AsmListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AsmBaseListener : public AsmListener {
public:

  virtual void enterCode(AsmParser::CodeContext * /*ctx*/) override { }
  virtual void exitCode(AsmParser::CodeContext * /*ctx*/) override { }

  virtual void enterStatements(AsmParser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(AsmParser::StatementsContext * /*ctx*/) override { }

  virtual void enterStatement(AsmParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(AsmParser::StatementContext * /*ctx*/) override { }

  virtual void enterPragma(AsmParser::PragmaContext * /*ctx*/) override { }
  virtual void exitPragma(AsmParser::PragmaContext * /*ctx*/) override { }

  virtual void enterInstruction(AsmParser::InstructionContext * /*ctx*/) override { }
  virtual void exitInstruction(AsmParser::InstructionContext * /*ctx*/) override { }

  virtual void enterSymbol(AsmParser::SymbolContext * /*ctx*/) override { }
  virtual void exitSymbol(AsmParser::SymbolContext * /*ctx*/) override { }

  virtual void enterCpu_ins(AsmParser::Cpu_insContext * /*ctx*/) override { }
  virtual void exitCpu_ins(AsmParser::Cpu_insContext * /*ctx*/) override { }

  virtual void enterCtl_ins(AsmParser::Ctl_insContext * /*ctx*/) override { }
  virtual void exitCtl_ins(AsmParser::Ctl_insContext * /*ctx*/) override { }

  virtual void enterStart(AsmParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(AsmParser::StartContext * /*ctx*/) override { }

  virtual void enterMem_ins(AsmParser::Mem_insContext * /*ctx*/) override { }
  virtual void exitMem_ins(AsmParser::Mem_insContext * /*ctx*/) override { }

  virtual void enterMem_op(AsmParser::Mem_opContext * /*ctx*/) override { }
  virtual void exitMem_op(AsmParser::Mem_opContext * /*ctx*/) override { }

  virtual void enterMem_and(AsmParser::Mem_andContext * /*ctx*/) override { }
  virtual void exitMem_and(AsmParser::Mem_andContext * /*ctx*/) override { }

  virtual void enterMem_tad(AsmParser::Mem_tadContext * /*ctx*/) override { }
  virtual void exitMem_tad(AsmParser::Mem_tadContext * /*ctx*/) override { }

  virtual void enterMem_isz(AsmParser::Mem_iszContext * /*ctx*/) override { }
  virtual void exitMem_isz(AsmParser::Mem_iszContext * /*ctx*/) override { }

  virtual void enterMem_dca(AsmParser::Mem_dcaContext * /*ctx*/) override { }
  virtual void exitMem_dca(AsmParser::Mem_dcaContext * /*ctx*/) override { }

  virtual void enterMem_jms(AsmParser::Mem_jmsContext * /*ctx*/) override { }
  virtual void exitMem_jms(AsmParser::Mem_jmsContext * /*ctx*/) override { }

  virtual void enterMem_jmp(AsmParser::Mem_jmpContext * /*ctx*/) override { }
  virtual void exitMem_jmp(AsmParser::Mem_jmpContext * /*ctx*/) override { }

  virtual void enterZero(AsmParser::ZeroContext * /*ctx*/) override { }
  virtual void exitZero(AsmParser::ZeroContext * /*ctx*/) override { }

  virtual void enterInd(AsmParser::IndContext * /*ctx*/) override { }
  virtual void exitInd(AsmParser::IndContext * /*ctx*/) override { }

  virtual void enterAddress(AsmParser::AddressContext * /*ctx*/) override { }
  virtual void exitAddress(AsmParser::AddressContext * /*ctx*/) override { }

  virtual void enterOpr_ins(AsmParser::Opr_insContext * /*ctx*/) override { }
  virtual void exitOpr_ins(AsmParser::Opr_insContext * /*ctx*/) override { }

  virtual void enterOpr_op1(AsmParser::Opr_op1Context * /*ctx*/) override { }
  virtual void exitOpr_op1(AsmParser::Opr_op1Context * /*ctx*/) override { }

  virtual void enterOpr_op1_ins(AsmParser::Opr_op1_insContext * /*ctx*/) override { }
  virtual void exitOpr_op1_ins(AsmParser::Opr_op1_insContext * /*ctx*/) override { }

  virtual void enterNop(AsmParser::NopContext * /*ctx*/) override { }
  virtual void exitNop(AsmParser::NopContext * /*ctx*/) override { }

  virtual void enterIac(AsmParser::IacContext * /*ctx*/) override { }
  virtual void exitIac(AsmParser::IacContext * /*ctx*/) override { }

  virtual void enterRal(AsmParser::RalContext * /*ctx*/) override { }
  virtual void exitRal(AsmParser::RalContext * /*ctx*/) override { }

  virtual void enterRtl(AsmParser::RtlContext * /*ctx*/) override { }
  virtual void exitRtl(AsmParser::RtlContext * /*ctx*/) override { }

  virtual void enterRar(AsmParser::RarContext * /*ctx*/) override { }
  virtual void exitRar(AsmParser::RarContext * /*ctx*/) override { }

  virtual void enterRtr(AsmParser::RtrContext * /*ctx*/) override { }
  virtual void exitRtr(AsmParser::RtrContext * /*ctx*/) override { }

  virtual void enterBsw(AsmParser::BswContext * /*ctx*/) override { }
  virtual void exitBsw(AsmParser::BswContext * /*ctx*/) override { }

  virtual void enterCml(AsmParser::CmlContext * /*ctx*/) override { }
  virtual void exitCml(AsmParser::CmlContext * /*ctx*/) override { }

  virtual void enterCma(AsmParser::CmaContext * /*ctx*/) override { }
  virtual void exitCma(AsmParser::CmaContext * /*ctx*/) override { }

  virtual void enterCia(AsmParser::CiaContext * /*ctx*/) override { }
  virtual void exitCia(AsmParser::CiaContext * /*ctx*/) override { }

  virtual void enterCll(AsmParser::CllContext * /*ctx*/) override { }
  virtual void exitCll(AsmParser::CllContext * /*ctx*/) override { }

  virtual void enterStl(AsmParser::StlContext * /*ctx*/) override { }
  virtual void exitStl(AsmParser::StlContext * /*ctx*/) override { }

  virtual void enterCla(AsmParser::ClaContext * /*ctx*/) override { }
  virtual void exitCla(AsmParser::ClaContext * /*ctx*/) override { }

  virtual void enterSta(AsmParser::StaContext * /*ctx*/) override { }
  virtual void exitSta(AsmParser::StaContext * /*ctx*/) override { }

  virtual void enterOpr_op2(AsmParser::Opr_op2Context * /*ctx*/) override { }
  virtual void exitOpr_op2(AsmParser::Opr_op2Context * /*ctx*/) override { }

  virtual void enterOpr_op2_ins(AsmParser::Opr_op2_insContext * /*ctx*/) override { }
  virtual void exitOpr_op2_ins(AsmParser::Opr_op2_insContext * /*ctx*/) override { }

  virtual void enterHlt(AsmParser::HltContext * /*ctx*/) override { }
  virtual void exitHlt(AsmParser::HltContext * /*ctx*/) override { }

  virtual void enterOsr(AsmParser::OsrContext * /*ctx*/) override { }
  virtual void exitOsr(AsmParser::OsrContext * /*ctx*/) override { }

  virtual void enterSkp(AsmParser::SkpContext * /*ctx*/) override { }
  virtual void exitSkp(AsmParser::SkpContext * /*ctx*/) override { }

  virtual void enterSnl(AsmParser::SnlContext * /*ctx*/) override { }
  virtual void exitSnl(AsmParser::SnlContext * /*ctx*/) override { }

  virtual void enterSzl(AsmParser::SzlContext * /*ctx*/) override { }
  virtual void exitSzl(AsmParser::SzlContext * /*ctx*/) override { }

  virtual void enterSza(AsmParser::SzaContext * /*ctx*/) override { }
  virtual void exitSza(AsmParser::SzaContext * /*ctx*/) override { }

  virtual void enterSna(AsmParser::SnaContext * /*ctx*/) override { }
  virtual void exitSna(AsmParser::SnaContext * /*ctx*/) override { }

  virtual void enterSma(AsmParser::SmaContext * /*ctx*/) override { }
  virtual void exitSma(AsmParser::SmaContext * /*ctx*/) override { }

  virtual void enterSpa(AsmParser::SpaContext * /*ctx*/) override { }
  virtual void exitSpa(AsmParser::SpaContext * /*ctx*/) override { }

  virtual void enterOpr_op3(AsmParser::Opr_op3Context * /*ctx*/) override { }
  virtual void exitOpr_op3(AsmParser::Opr_op3Context * /*ctx*/) override { }

  virtual void enterOpr_op3_ins(AsmParser::Opr_op3_insContext * /*ctx*/) override { }
  virtual void exitOpr_op3_ins(AsmParser::Opr_op3_insContext * /*ctx*/) override { }

  virtual void enterCam(AsmParser::CamContext * /*ctx*/) override { }
  virtual void exitCam(AsmParser::CamContext * /*ctx*/) override { }

  virtual void enterMqa(AsmParser::MqaContext * /*ctx*/) override { }
  virtual void exitMqa(AsmParser::MqaContext * /*ctx*/) override { }

  virtual void enterMql(AsmParser::MqlContext * /*ctx*/) override { }
  virtual void exitMql(AsmParser::MqlContext * /*ctx*/) override { }

  virtual void enterSwp(AsmParser::SwpContext * /*ctx*/) override { }
  virtual void exitSwp(AsmParser::SwpContext * /*ctx*/) override { }

  virtual void enterIot_ins(AsmParser::Iot_insContext * /*ctx*/) override { }
  virtual void exitIot_ins(AsmParser::Iot_insContext * /*ctx*/) override { }

  virtual void enterIot(AsmParser::IotContext * /*ctx*/) override { }
  virtual void exitIot(AsmParser::IotContext * /*ctx*/) override { }

  virtual void enterIon(AsmParser::IonContext * /*ctx*/) override { }
  virtual void exitIon(AsmParser::IonContext * /*ctx*/) override { }

  virtual void enterSkon(AsmParser::SkonContext * /*ctx*/) override { }
  virtual void exitSkon(AsmParser::SkonContext * /*ctx*/) override { }

  virtual void enterIof(AsmParser::IofContext * /*ctx*/) override { }
  virtual void exitIof(AsmParser::IofContext * /*ctx*/) override { }

  virtual void enterSrq(AsmParser::SrqContext * /*ctx*/) override { }
  virtual void exitSrq(AsmParser::SrqContext * /*ctx*/) override { }

  virtual void enterGtf(AsmParser::GtfContext * /*ctx*/) override { }
  virtual void exitGtf(AsmParser::GtfContext * /*ctx*/) override { }

  virtual void enterRtf(AsmParser::RtfContext * /*ctx*/) override { }
  virtual void exitRtf(AsmParser::RtfContext * /*ctx*/) override { }

    virtual void enterSgt(AsmParser::SgtContext * /*ctx*/) override {}

    virtual void exitSgt(AsmParser::SgtContext * /*ctx*/) override {}

  virtual void enterCaf(AsmParser::CafContext * /*ctx*/) override { }
  virtual void exitCaf(AsmParser::CafContext * /*ctx*/) override { }

    virtual void enterDef_const(AsmParser::Def_constContext * /*ctx*/) override {}

    virtual void exitDef_const(AsmParser::Def_constContext * /*ctx*/) override {}

    virtual void enterDw(AsmParser::DwContext * /*ctx*/) override {}

    virtual void exitDw(AsmParser::DwContext * /*ctx*/) override {}

  virtual void enterEol(AsmParser::EolContext * /*ctx*/) override { }
  virtual void exitEol(AsmParser::EolContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

