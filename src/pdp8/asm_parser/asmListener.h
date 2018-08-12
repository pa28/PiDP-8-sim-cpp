
// Generated from Asm.g4 by ANTLR 4.7

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

  virtual void enterStatement(AsmParser::StatementContext *ctx) = 0;
  virtual void exitStatement(AsmParser::StatementContext *ctx) = 0;

  virtual void enterSymbol(AsmParser::SymbolContext *ctx) = 0;
  virtual void exitSymbol(AsmParser::SymbolContext *ctx) = 0;

  virtual void enterInstruction(AsmParser::InstructionContext *ctx) = 0;
  virtual void exitInstruction(AsmParser::InstructionContext *ctx) = 0;

  virtual void enterCtl_ins(AsmParser::Ctl_insContext *ctx) = 0;
  virtual void exitCtl_ins(AsmParser::Ctl_insContext *ctx) = 0;

  virtual void enterStart(AsmParser::StartContext *ctx) = 0;
  virtual void exitStart(AsmParser::StartContext *ctx) = 0;

  virtual void enterMem_ins(AsmParser::Mem_insContext *ctx) = 0;
  virtual void exitMem_ins(AsmParser::Mem_insContext *ctx) = 0;

  virtual void enterMem_op(AsmParser::Mem_opContext *ctx) = 0;
  virtual void exitMem_op(AsmParser::Mem_opContext *ctx) = 0;

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

  virtual void enterOpr_op2(AsmParser::Opr_op2Context *ctx) = 0;
  virtual void exitOpr_op2(AsmParser::Opr_op2Context *ctx) = 0;

  virtual void enterOpr_op3(AsmParser::Opr_op3Context *ctx) = 0;
  virtual void exitOpr_op3(AsmParser::Opr_op3Context *ctx) = 0;

  virtual void enterIot_ins(AsmParser::Iot_insContext *ctx) = 0;
  virtual void exitIot_ins(AsmParser::Iot_insContext *ctx) = 0;

  virtual void enterEol(AsmParser::EolContext *ctx) = 0;
  virtual void exitEol(AsmParser::EolContext *ctx) = 0;


};

