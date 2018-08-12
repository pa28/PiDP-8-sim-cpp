
// Generated from Asm.g4 by ANTLR 4.7

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

  virtual antlrcpp::Any visitStatement(AsmParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbol(AsmParser::SymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstruction(AsmParser::InstructionContext *ctx) override {
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

  virtual antlrcpp::Any visitOpr_op2(AsmParser::Opr_op2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpr_op3(AsmParser::Opr_op3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIot_ins(AsmParser::Iot_insContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEol(AsmParser::EolContext *ctx) override {
    return visitChildren(ctx);
  }


};

