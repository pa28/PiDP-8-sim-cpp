
// Generated from Asm.g4 by ANTLR 4.7

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

  virtual void enterStatement(AsmParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(AsmParser::StatementContext * /*ctx*/) override { }

  virtual void enterSymbol(AsmParser::SymbolContext * /*ctx*/) override { }
  virtual void exitSymbol(AsmParser::SymbolContext * /*ctx*/) override { }

  virtual void enterInstruction(AsmParser::InstructionContext * /*ctx*/) override { }
  virtual void exitInstruction(AsmParser::InstructionContext * /*ctx*/) override { }

  virtual void enterCtl_ins(AsmParser::Ctl_insContext * /*ctx*/) override { }
  virtual void exitCtl_ins(AsmParser::Ctl_insContext * /*ctx*/) override { }

  virtual void enterStart(AsmParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(AsmParser::StartContext * /*ctx*/) override { }

  virtual void enterMem_ins(AsmParser::Mem_insContext * /*ctx*/) override { }
  virtual void exitMem_ins(AsmParser::Mem_insContext * /*ctx*/) override { }

  virtual void enterMem_op(AsmParser::Mem_opContext * /*ctx*/) override { }
  virtual void exitMem_op(AsmParser::Mem_opContext * /*ctx*/) override { }

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

  virtual void enterOpr_op2(AsmParser::Opr_op2Context * /*ctx*/) override { }
  virtual void exitOpr_op2(AsmParser::Opr_op2Context * /*ctx*/) override { }

  virtual void enterOpr_op3(AsmParser::Opr_op3Context * /*ctx*/) override { }
  virtual void exitOpr_op3(AsmParser::Opr_op3Context * /*ctx*/) override { }

  virtual void enterIot_ins(AsmParser::Iot_insContext * /*ctx*/) override { }
  virtual void exitIot_ins(AsmParser::Iot_insContext * /*ctx*/) override { }

  virtual void enterEol(AsmParser::EolContext * /*ctx*/) override { }
  virtual void exitEol(AsmParser::EolContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

