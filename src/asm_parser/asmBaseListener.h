
// Generated from asm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "asmListener.h"


/**
 * This class provides an empty implementation of asmListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  asmBaseListener : public asmListener {
public:

  virtual void enterCode(asmParser::CodeContext * /*ctx*/) override { }
  virtual void exitCode(asmParser::CodeContext * /*ctx*/) override { }

  virtual void enterStatement(asmParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(asmParser::StatementContext * /*ctx*/) override { }

  virtual void enterSymbol(asmParser::SymbolContext * /*ctx*/) override { }
  virtual void exitSymbol(asmParser::SymbolContext * /*ctx*/) override { }

  virtual void enterInstruction(asmParser::InstructionContext * /*ctx*/) override { }
  virtual void exitInstruction(asmParser::InstructionContext * /*ctx*/) override { }

  virtual void enterCtl_ins(asmParser::Ctl_insContext * /*ctx*/) override { }
  virtual void exitCtl_ins(asmParser::Ctl_insContext * /*ctx*/) override { }

  virtual void enterStart(asmParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(asmParser::StartContext * /*ctx*/) override { }

  virtual void enterMem_ins(asmParser::Mem_insContext * /*ctx*/) override { }
  virtual void exitMem_ins(asmParser::Mem_insContext * /*ctx*/) override { }

  virtual void enterMem_op(asmParser::Mem_opContext * /*ctx*/) override { }
  virtual void exitMem_op(asmParser::Mem_opContext * /*ctx*/) override { }

  virtual void enterZero(asmParser::ZeroContext * /*ctx*/) override { }
  virtual void exitZero(asmParser::ZeroContext * /*ctx*/) override { }

  virtual void enterInd(asmParser::IndContext * /*ctx*/) override { }
  virtual void exitInd(asmParser::IndContext * /*ctx*/) override { }

  virtual void enterAddress(asmParser::AddressContext * /*ctx*/) override { }
  virtual void exitAddress(asmParser::AddressContext * /*ctx*/) override { }

  virtual void enterOpr_ins(asmParser::Opr_insContext * /*ctx*/) override { }
  virtual void exitOpr_ins(asmParser::Opr_insContext * /*ctx*/) override { }

  virtual void enterOpr_op1(asmParser::Opr_op1Context * /*ctx*/) override { }
  virtual void exitOpr_op1(asmParser::Opr_op1Context * /*ctx*/) override { }

  virtual void enterOpr_op2(asmParser::Opr_op2Context * /*ctx*/) override { }
  virtual void exitOpr_op2(asmParser::Opr_op2Context * /*ctx*/) override { }

  virtual void enterOpr_op3(asmParser::Opr_op3Context * /*ctx*/) override { }
  virtual void exitOpr_op3(asmParser::Opr_op3Context * /*ctx*/) override { }

  virtual void enterIot_ins(asmParser::Iot_insContext * /*ctx*/) override { }
  virtual void exitIot_ins(asmParser::Iot_insContext * /*ctx*/) override { }

  virtual void enterEol(asmParser::EolContext * /*ctx*/) override { }
  virtual void exitEol(asmParser::EolContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

