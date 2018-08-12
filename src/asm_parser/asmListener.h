
// Generated from asm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "asmParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by asmParser.
 */
class  asmListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCode(asmParser::CodeContext *ctx) = 0;
  virtual void exitCode(asmParser::CodeContext *ctx) = 0;

  virtual void enterStatement(asmParser::StatementContext *ctx) = 0;
  virtual void exitStatement(asmParser::StatementContext *ctx) = 0;

  virtual void enterSymbol(asmParser::SymbolContext *ctx) = 0;
  virtual void exitSymbol(asmParser::SymbolContext *ctx) = 0;

  virtual void enterInstruction(asmParser::InstructionContext *ctx) = 0;
  virtual void exitInstruction(asmParser::InstructionContext *ctx) = 0;

  virtual void enterCtl_ins(asmParser::Ctl_insContext *ctx) = 0;
  virtual void exitCtl_ins(asmParser::Ctl_insContext *ctx) = 0;

  virtual void enterStart(asmParser::StartContext *ctx) = 0;
  virtual void exitStart(asmParser::StartContext *ctx) = 0;

  virtual void enterMem_ins(asmParser::Mem_insContext *ctx) = 0;
  virtual void exitMem_ins(asmParser::Mem_insContext *ctx) = 0;

  virtual void enterMem_op(asmParser::Mem_opContext *ctx) = 0;
  virtual void exitMem_op(asmParser::Mem_opContext *ctx) = 0;

  virtual void enterZero(asmParser::ZeroContext *ctx) = 0;
  virtual void exitZero(asmParser::ZeroContext *ctx) = 0;

  virtual void enterInd(asmParser::IndContext *ctx) = 0;
  virtual void exitInd(asmParser::IndContext *ctx) = 0;

  virtual void enterAddress(asmParser::AddressContext *ctx) = 0;
  virtual void exitAddress(asmParser::AddressContext *ctx) = 0;

  virtual void enterOpr_ins(asmParser::Opr_insContext *ctx) = 0;
  virtual void exitOpr_ins(asmParser::Opr_insContext *ctx) = 0;

  virtual void enterOpr_op1(asmParser::Opr_op1Context *ctx) = 0;
  virtual void exitOpr_op1(asmParser::Opr_op1Context *ctx) = 0;

  virtual void enterOpr_op2(asmParser::Opr_op2Context *ctx) = 0;
  virtual void exitOpr_op2(asmParser::Opr_op2Context *ctx) = 0;

  virtual void enterOpr_op3(asmParser::Opr_op3Context *ctx) = 0;
  virtual void exitOpr_op3(asmParser::Opr_op3Context *ctx) = 0;

  virtual void enterIot_ins(asmParser::Iot_insContext *ctx) = 0;
  virtual void exitIot_ins(asmParser::Iot_insContext *ctx) = 0;

  virtual void enterEol(asmParser::EolContext *ctx) = 0;
  virtual void exitEol(asmParser::EolContext *ctx) = 0;


};

