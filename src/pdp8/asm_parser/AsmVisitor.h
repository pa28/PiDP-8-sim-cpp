
// Generated from Asm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "AsmParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by AsmParser.
 */
class  AsmVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by AsmParser.
   */
    virtual antlrcpp::Any visitCode(AsmParser::CodeContext *context) = 0;

    virtual antlrcpp::Any visitStatement(AsmParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitSymbol(AsmParser::SymbolContext *context) = 0;

    virtual antlrcpp::Any visitInstruction(AsmParser::InstructionContext *context) = 0;

    virtual antlrcpp::Any visitCtl_ins(AsmParser::Ctl_insContext *context) = 0;

    virtual antlrcpp::Any visitStart(AsmParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitMem_ins(AsmParser::Mem_insContext *context) = 0;

    virtual antlrcpp::Any visitMem_op(AsmParser::Mem_opContext *context) = 0;

    virtual antlrcpp::Any visitZero(AsmParser::ZeroContext *context) = 0;

    virtual antlrcpp::Any visitInd(AsmParser::IndContext *context) = 0;

    virtual antlrcpp::Any visitAddress(AsmParser::AddressContext *context) = 0;

    virtual antlrcpp::Any visitOpr_ins(AsmParser::Opr_insContext *context) = 0;

    virtual antlrcpp::Any visitOpr_op1(AsmParser::Opr_op1Context *context) = 0;

    virtual antlrcpp::Any visitOpr_op2(AsmParser::Opr_op2Context *context) = 0;

    virtual antlrcpp::Any visitOpr_op3(AsmParser::Opr_op3Context *context) = 0;

    virtual antlrcpp::Any visitIot_ins(AsmParser::Iot_insContext *context) = 0;

    virtual antlrcpp::Any visitEol(AsmParser::EolContext *context) = 0;


};

