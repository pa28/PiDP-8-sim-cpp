
// Generated from /mnt/v/CLionProjects/PiDP-8-sim-cpp/src/pdp8/asm_parser/Asm.g4 by ANTLR 4.7

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

    virtual antlrcpp::Any visitStatements(AsmParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitStatement(AsmParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitSymbol(AsmParser::SymbolContext *context) = 0;

    virtual antlrcpp::Any visitInstruction(AsmParser::InstructionContext *context) = 0;

    virtual antlrcpp::Any visitCtl_ins(AsmParser::Ctl_insContext *context) = 0;

    virtual antlrcpp::Any visitStart(AsmParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitMem_ins(AsmParser::Mem_insContext *context) = 0;

    virtual antlrcpp::Any visitMem_op(AsmParser::Mem_opContext *context) = 0;

    virtual antlrcpp::Any visitMem_and(AsmParser::Mem_andContext *context) = 0;

    virtual antlrcpp::Any visitMem_tad(AsmParser::Mem_tadContext *context) = 0;

    virtual antlrcpp::Any visitMem_isz(AsmParser::Mem_iszContext *context) = 0;

    virtual antlrcpp::Any visitMem_dca(AsmParser::Mem_dcaContext *context) = 0;

    virtual antlrcpp::Any visitMem_jms(AsmParser::Mem_jmsContext *context) = 0;

    virtual antlrcpp::Any visitMem_jmp(AsmParser::Mem_jmpContext *context) = 0;

    virtual antlrcpp::Any visitZero(AsmParser::ZeroContext *context) = 0;

    virtual antlrcpp::Any visitInd(AsmParser::IndContext *context) = 0;

    virtual antlrcpp::Any visitAddress(AsmParser::AddressContext *context) = 0;

    virtual antlrcpp::Any visitOpr_ins(AsmParser::Opr_insContext *context) = 0;

    virtual antlrcpp::Any visitOpr_op1(AsmParser::Opr_op1Context *context) = 0;

    virtual antlrcpp::Any visitOpr_op1_ins(AsmParser::Opr_op1_insContext *context) = 0;

    virtual antlrcpp::Any visitNop(AsmParser::NopContext *context) = 0;

    virtual antlrcpp::Any visitIac(AsmParser::IacContext *context) = 0;

    virtual antlrcpp::Any visitRal(AsmParser::RalContext *context) = 0;

    virtual antlrcpp::Any visitRtl(AsmParser::RtlContext *context) = 0;

    virtual antlrcpp::Any visitRar(AsmParser::RarContext *context) = 0;

    virtual antlrcpp::Any visitRtr(AsmParser::RtrContext *context) = 0;

    virtual antlrcpp::Any visitBsw(AsmParser::BswContext *context) = 0;

    virtual antlrcpp::Any visitCml(AsmParser::CmlContext *context) = 0;

    virtual antlrcpp::Any visitCma(AsmParser::CmaContext *context) = 0;

    virtual antlrcpp::Any visitCia(AsmParser::CiaContext *context) = 0;

    virtual antlrcpp::Any visitCll(AsmParser::CllContext *context) = 0;

    virtual antlrcpp::Any visitStl(AsmParser::StlContext *context) = 0;

    virtual antlrcpp::Any visitCla(AsmParser::ClaContext *context) = 0;

    virtual antlrcpp::Any visitSta(AsmParser::StaContext *context) = 0;

    virtual antlrcpp::Any visitOpr_op2(AsmParser::Opr_op2Context *context) = 0;

    virtual antlrcpp::Any visitOpr_op2_ins(AsmParser::Opr_op2_insContext *context) = 0;

    virtual antlrcpp::Any visitHlt(AsmParser::HltContext *context) = 0;

    virtual antlrcpp::Any visitOsr(AsmParser::OsrContext *context) = 0;

    virtual antlrcpp::Any visitSkp(AsmParser::SkpContext *context) = 0;

    virtual antlrcpp::Any visitSnl(AsmParser::SnlContext *context) = 0;

    virtual antlrcpp::Any visitSzl(AsmParser::SzlContext *context) = 0;

    virtual antlrcpp::Any visitSza(AsmParser::SzaContext *context) = 0;

    virtual antlrcpp::Any visitSna(AsmParser::SnaContext *context) = 0;

    virtual antlrcpp::Any visitSma(AsmParser::SmaContext *context) = 0;

    virtual antlrcpp::Any visitSpa(AsmParser::SpaContext *context) = 0;

    virtual antlrcpp::Any visitOpr_op3(AsmParser::Opr_op3Context *context) = 0;

    virtual antlrcpp::Any visitOpr_op3_ins(AsmParser::Opr_op3_insContext *context) = 0;

    virtual antlrcpp::Any visitCam(AsmParser::CamContext *context) = 0;

    virtual antlrcpp::Any visitMqa(AsmParser::MqaContext *context) = 0;

    virtual antlrcpp::Any visitMql(AsmParser::MqlContext *context) = 0;

    virtual antlrcpp::Any visitSwp(AsmParser::SwpContext *context) = 0;

    virtual antlrcpp::Any visitIot_ins(AsmParser::Iot_insContext *context) = 0;

    virtual antlrcpp::Any visitIot(AsmParser::IotContext *context) = 0;

    virtual antlrcpp::Any visitIon(AsmParser::IonContext *context) = 0;

    virtual antlrcpp::Any visitSkon(AsmParser::SkonContext *context) = 0;

    virtual antlrcpp::Any visitIof(AsmParser::IofContext *context) = 0;

    virtual antlrcpp::Any visitSrq(AsmParser::SrqContext *context) = 0;

    virtual antlrcpp::Any visitGtf(AsmParser::GtfContext *context) = 0;

    virtual antlrcpp::Any visitRtf(AsmParser::RtfContext *context) = 0;

    virtual antlrcpp::Any visitCaf(AsmParser::CafContext *context) = 0;

    virtual antlrcpp::Any visitEol(AsmParser::EolContext *context) = 0;


};

