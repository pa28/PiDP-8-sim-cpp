
// Generated from /mnt/v/CLionProjects/PiDP-8-sim-cpp/src/pdp8/asm_parser/Asm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  AsmParser : public antlr4::Parser {
public:
  enum {
      T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, DW = 7,
      AND = 8, TAD = 9, ISZ = 10, DCA = 11, JMS = 12, JMP = 13, NOP = 14,
      IAC = 15, RAL = 16, RTL = 17, RAR = 18, RTR = 19, BSW = 20, CML = 21,
      CMA = 22, CIA = 23, CLL = 24, STL = 25, CLA = 26, STA = 27, HLT = 28,
      OSR = 29, SKP = 30, SNL = 31, SZL = 32, SZA = 33, SNA = 34, SMA = 35,
      SPA = 36, CAM = 37, MQA = 38, MQL = 39, SWP = 40, IOT = 41, ION = 42,
      SKON = 43, IOF = 44, SRQ = 45, GTF = 46, RTF = 47, SGT = 48, CAF = 49,
      CDF = 50, CIF = 51, CIDF = 52, RDF = 53, RIF = 54, RIB = 55, RMF = 56,
      Octal = 57, Decimal = 58, ID = 59, WS = 60
  };

  enum {
    RuleCode = 0, RuleStatements = 1, RuleStatement = 2, RulePragma = 3, 
    RuleInstruction = 4, RuleSymbol = 5, RuleCpu_ins = 6, RuleCtl_ins = 7, 
    RuleStart = 8, RuleMem_ins = 9, RuleMem_op = 10, RuleMem_and = 11, RuleMem_tad = 12, 
    RuleMem_isz = 13, RuleMem_dca = 14, RuleMem_jms = 15, RuleMem_jmp = 16, 
    RuleZero = 17, RuleInd = 18, RuleAddress = 19, RuleOpr_ins = 20, RuleOpr_op1 = 21, 
    RuleOpr_op1_ins = 22, RuleNop = 23, RuleIac = 24, RuleRal = 25, RuleRtl = 26, 
    RuleRar = 27, RuleRtr = 28, RuleBsw = 29, RuleCml = 30, RuleCma = 31, 
    RuleCia = 32, RuleCll = 33, RuleStl = 34, RuleCla = 35, RuleSta = 36, 
    RuleOpr_op2 = 37, RuleOpr_op2_ins = 38, RuleHlt = 39, RuleOsr = 40, 
    RuleSkp = 41, RuleSnl = 42, RuleSzl = 43, RuleSza = 44, RuleSna = 45, 
    RuleSma = 46, RuleSpa = 47, RuleOpr_op3 = 48, RuleOpr_op3_ins = 49,
      RuleCam = 50, RuleMqa = 51, RuleMql = 52, RuleSwp = 53, RuleIot_ins = 54,
      RuleIot = 55, RuleIon = 56, RuleSkon = 57, RuleIof = 58, RuleSrq = 59,
      RuleGtf = 60, RuleRtf = 61, RuleSgt = 62, RuleCaf = 63, RuleCdf = 64,
      RuleCif = 65, RuleCidf = 66, RuleRdf = 67, RuleRif = 68, RuleRib = 69,
      RuleRmf = 70, RuleDef_const = 71, RuleDw = 72, RuleEol = 73
  };

  AsmParser(antlr4::TokenStream *input);
  ~AsmParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CodeContext;
  class StatementsContext;
  class StatementContext;
  class PragmaContext;
  class InstructionContext;
  class SymbolContext;
  class Cpu_insContext;
  class Ctl_insContext;
  class StartContext;
  class Mem_insContext;
  class Mem_opContext;
  class Mem_andContext;
  class Mem_tadContext;
  class Mem_iszContext;
  class Mem_dcaContext;
  class Mem_jmsContext;
  class Mem_jmpContext;
  class ZeroContext;
  class IndContext;
  class AddressContext;
  class Opr_insContext;
  class Opr_op1Context;
  class Opr_op1_insContext;
  class NopContext;
  class IacContext;
  class RalContext;
  class RtlContext;
  class RarContext;
  class RtrContext;
  class BswContext;
  class CmlContext;
  class CmaContext;
  class CiaContext;
  class CllContext;
  class StlContext;
  class ClaContext;
  class StaContext;
  class Opr_op2Context;
  class Opr_op2_insContext;
  class HltContext;
  class OsrContext;
  class SkpContext;
  class SnlContext;
  class SzlContext;
  class SzaContext;
  class SnaContext;
  class SmaContext;
  class SpaContext;
  class Opr_op3Context;
  class Opr_op3_insContext;
  class CamContext;
  class MqaContext;
  class MqlContext;
  class SwpContext;
  class Iot_insContext;
  class IotContext;
  class IonContext;
  class SkonContext;
  class IofContext;
  class SrqContext;
  class GtfContext;
  class RtfContext;

    class SgtContext;
  class CafContext;

    class CdfContext;

    class CifContext;

    class CidfContext;

    class RdfContext;

    class RifContext;

    class RibContext;

    class RmfContext;

    class Def_constContext;

    class DwContext;
  class EolContext; 

  class  CodeContext : public antlr4::ParserRuleContext {
  public:
    CodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementsContext *statements();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CodeContext* code();

  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementsContext* statements();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InstructionContext *instruction();
    PragmaContext *pragma();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  PragmaContext : public antlr4::ParserRuleContext {
  public:
    PragmaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ctl_insContext *ctl_ins();
    SymbolContext *symbol();
    std::vector<EolContext *> eol();
    EolContext* eol(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PragmaContext* pragma();

  class  InstructionContext : public antlr4::ParserRuleContext {
  public:
    InstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Cpu_insContext *cpu_ins();
    SymbolContext *symbol();
    std::vector<EolContext *> eol();
    EolContext* eol(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstructionContext* instruction();

  class  SymbolContext : public antlr4::ParserRuleContext {
  public:
    SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SymbolContext* symbol();

  class  Cpu_insContext : public antlr4::ParserRuleContext {
  public:
    Cpu_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mem_insContext *mem_ins();
    Opr_insContext *opr_ins();
    Iot_insContext *iot_ins();

      Def_constContext *def_const();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cpu_insContext* cpu_ins();

  class  Ctl_insContext : public antlr4::ParserRuleContext {
  public:
    Ctl_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StartContext *start();

      SymbolContext *symbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ctl_insContext* ctl_ins();

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddressContext *address();
    SymbolContext *symbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

  class  Mem_insContext : public antlr4::ParserRuleContext {
  public:
    Mem_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mem_opContext *mem_op();
    AddressContext *address();
    SymbolContext *symbol();
    ZeroContext *zero();
    IndContext *ind();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mem_insContext* mem_ins();

  class  Mem_opContext : public antlr4::ParserRuleContext {
  public:
    Mem_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mem_andContext *mem_and();
    Mem_tadContext *mem_tad();
    Mem_iszContext *mem_isz();
    Mem_dcaContext *mem_dca();
    Mem_jmsContext *mem_jms();
    Mem_jmpContext *mem_jmp();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mem_opContext* mem_op();

  class  Mem_andContext : public antlr4::ParserRuleContext {
  public:
    Mem_andContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mem_andContext* mem_and();

  class  Mem_tadContext : public antlr4::ParserRuleContext {
  public:
    Mem_tadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TAD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mem_tadContext* mem_tad();

  class  Mem_iszContext : public antlr4::ParserRuleContext {
  public:
    Mem_iszContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ISZ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mem_iszContext* mem_isz();

  class  Mem_dcaContext : public antlr4::ParserRuleContext {
  public:
    Mem_dcaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DCA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mem_dcaContext* mem_dca();

  class  Mem_jmsContext : public antlr4::ParserRuleContext {
  public:
    Mem_jmsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *JMS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mem_jmsContext* mem_jms();

  class  Mem_jmpContext : public antlr4::ParserRuleContext {
  public:
    Mem_jmpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *JMP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mem_jmpContext* mem_jmp();

  class  ZeroContext : public antlr4::ParserRuleContext {
  public:
    ZeroContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ZeroContext* zero();

  class  IndContext : public antlr4::ParserRuleContext {
  public:
    IndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndContext* ind();

  class  AddressContext : public antlr4::ParserRuleContext {
  public:
    AddressContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Octal();
    antlr4::tree::TerminalNode *Decimal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddressContext* address();

  class  Opr_insContext : public antlr4::ParserRuleContext {
  public:
    Opr_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Opr_op1Context *opr_op1();
    Opr_op2Context *opr_op2();
    Opr_op3Context *opr_op3();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Opr_insContext* opr_ins();

  class  Opr_op1Context : public antlr4::ParserRuleContext {
  public:
    Opr_op1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Opr_op1_insContext *> opr_op1_ins();
    Opr_op1_insContext* opr_op1_ins(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Opr_op1Context* opr_op1();

  class  Opr_op1_insContext : public antlr4::ParserRuleContext {
  public:
    Opr_op1_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NopContext *nop();
    IacContext *iac();
    RalContext *ral();
    RtlContext *rtl();
    RarContext *rar();
    RtrContext *rtr();
    BswContext *bsw();
    CmlContext *cml();
    CmaContext *cma();
    CiaContext *cia();
    CllContext *cll();
    StlContext *stl();
    ClaContext *cla();
    StaContext *sta();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Opr_op1_insContext* opr_op1_ins();

  class  NopContext : public antlr4::ParserRuleContext {
  public:
    NopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NopContext* nop();

  class  IacContext : public antlr4::ParserRuleContext {
  public:
    IacContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IAC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IacContext* iac();

  class  RalContext : public antlr4::ParserRuleContext {
  public:
    RalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

      antlr4::tree::TerminalNode *RAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RalContext* ral();

  class  RtlContext : public antlr4::ParserRuleContext {
  public:
    RtlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RTL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RtlContext* rtl();

  class  RarContext : public antlr4::ParserRuleContext {
  public:
    RarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RAR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RarContext* rar();

  class  RtrContext : public antlr4::ParserRuleContext {
  public:
    RtrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RTR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RtrContext* rtr();

  class  BswContext : public antlr4::ParserRuleContext {
  public:
    BswContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BSW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BswContext* bsw();

  class  CmlContext : public antlr4::ParserRuleContext {
  public:
    CmlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CML();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CmlContext* cml();

  class  CmaContext : public antlr4::ParserRuleContext {
  public:
    CmaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CmaContext* cma();

  class  CiaContext : public antlr4::ParserRuleContext {
  public:
    CiaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CIA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CiaContext* cia();

  class  CllContext : public antlr4::ParserRuleContext {
  public:
    CllContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CllContext* cll();

  class  StlContext : public antlr4::ParserRuleContext {
  public:
    StlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StlContext* stl();

  class  ClaContext : public antlr4::ParserRuleContext {
  public:
    ClaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClaContext* cla();

  class  StaContext : public antlr4::ParserRuleContext {
  public:
    StaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StaContext* sta();

  class  Opr_op2Context : public antlr4::ParserRuleContext {
  public:
    Opr_op2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Opr_op2_insContext *> opr_op2_ins();
    Opr_op2_insContext* opr_op2_ins(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Opr_op2Context* opr_op2();

  class  Opr_op2_insContext : public antlr4::ParserRuleContext {
  public:
    Opr_op2_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    HltContext *hlt();
    OsrContext *osr();
    SkpContext *skp();
    SnlContext *snl();
    SzlContext *szl();
    SzaContext *sza();
    SnaContext *sna();
    SmaContext *sma();
    SpaContext *spa();
    ClaContext *cla();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Opr_op2_insContext* opr_op2_ins();

  class  HltContext : public antlr4::ParserRuleContext {
  public:
    HltContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HLT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HltContext* hlt();

  class  OsrContext : public antlr4::ParserRuleContext {
  public:
    OsrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OSR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OsrContext* osr();

  class  SkpContext : public antlr4::ParserRuleContext {
  public:
    SkpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SKP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SkpContext* skp();

  class  SnlContext : public antlr4::ParserRuleContext {
  public:
    SnlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SNL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SnlContext* snl();

  class  SzlContext : public antlr4::ParserRuleContext {
  public:
    SzlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SZL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SzlContext* szl();

  class  SzaContext : public antlr4::ParserRuleContext {
  public:
    SzaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SZA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SzaContext* sza();

  class  SnaContext : public antlr4::ParserRuleContext {
  public:
    SnaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SNA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SnaContext* sna();

  class  SmaContext : public antlr4::ParserRuleContext {
  public:
    SmaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SmaContext* sma();

  class  SpaContext : public antlr4::ParserRuleContext {
  public:
    SpaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SPA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SpaContext* spa();

  class  Opr_op3Context : public antlr4::ParserRuleContext {
  public:
    Opr_op3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Opr_op3_insContext *> opr_op3_ins();
    Opr_op3_insContext* opr_op3_ins(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Opr_op3Context* opr_op3();

  class  Opr_op3_insContext : public antlr4::ParserRuleContext {
  public:
    Opr_op3_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CamContext *cam();
    MqaContext *mqa();
    MqlContext *mql();
    SwpContext *swp();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Opr_op3_insContext* opr_op3_ins();

  class  CamContext : public antlr4::ParserRuleContext {
  public:
    CamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CAM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CamContext* cam();

  class  MqaContext : public antlr4::ParserRuleContext {
  public:
    MqaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MQA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MqaContext* mqa();

  class  MqlContext : public antlr4::ParserRuleContext {
  public:
    MqlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MQL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MqlContext* mql();

  class  SwpContext : public antlr4::ParserRuleContext {
  public:
    SwpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SWP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwpContext* swp();

  class  Iot_insContext : public antlr4::ParserRuleContext {
  public:
    Iot_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IotContext *iot();
    IonContext *ion();
    SkonContext *skon();
    IofContext *iof();
    SrqContext *srq();
    GtfContext *gtf();
    RtfContext *rtf();

      SgtContext *sgt();
    CafContext *caf();

      CdfContext *cdf();

      CifContext *cif();

      CidfContext *cidf();

      RdfContext *rdf();

      RifContext *rif();

      RibContext *rib();

      RmfContext *rmf();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Iot_insContext* iot_ins();

  class  IotContext : public antlr4::ParserRuleContext {
  public:
    IotContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IotContext* iot();

  class  IonContext : public antlr4::ParserRuleContext {
  public:
    IonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IonContext* ion();

  class  SkonContext : public antlr4::ParserRuleContext {
  public:
    SkonContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SKON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SkonContext* skon();

  class  IofContext : public antlr4::ParserRuleContext {
  public:
    IofContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IofContext* iof();

  class  SrqContext : public antlr4::ParserRuleContext {
  public:
    SrqContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SRQ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SrqContext* srq();

  class  GtfContext : public antlr4::ParserRuleContext {
  public:
    GtfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GTF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GtfContext* gtf();

  class  RtfContext : public antlr4::ParserRuleContext {
  public:
    RtfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RTF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RtfContext* rtf();

    class SgtContext : public antlr4::ParserRuleContext {
    public:
        SgtContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        virtual size_t getRuleIndex() const override;

        antlr4::tree::TerminalNode *SGT();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

    };

    SgtContext *sgt();

  class  CafContext : public antlr4::ParserRuleContext {
  public:
    CafContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CAF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CafContext* caf();

    class CdfContext : public antlr4::ParserRuleContext {
    public:
        CdfContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        virtual size_t getRuleIndex() const override;

        antlr4::tree::TerminalNode *CDF();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

    };

    CdfContext *cdf();

    class CifContext : public antlr4::ParserRuleContext {
    public:
        CifContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        virtual size_t getRuleIndex() const override;

        antlr4::tree::TerminalNode *CIF();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

    };

    CifContext *cif();

    class CidfContext : public antlr4::ParserRuleContext {
    public:
        CidfContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        virtual size_t getRuleIndex() const override;

        antlr4::tree::TerminalNode *CIDF();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

    };

    CidfContext *cidf();

    class RdfContext : public antlr4::ParserRuleContext {
    public:
        RdfContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        virtual size_t getRuleIndex() const override;

        antlr4::tree::TerminalNode *RDF();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

    };

    RdfContext *rdf();

    class RifContext : public antlr4::ParserRuleContext {
    public:
        RifContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        virtual size_t getRuleIndex() const override;

        antlr4::tree::TerminalNode *RIF();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

    };

    RifContext *rif();

    class RibContext : public antlr4::ParserRuleContext {
    public:
        RibContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        virtual size_t getRuleIndex() const override;

        antlr4::tree::TerminalNode *RIB();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

    };

    RibContext *rib();

    class RmfContext : public antlr4::ParserRuleContext {
    public:
        RmfContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        virtual size_t getRuleIndex() const override;

        antlr4::tree::TerminalNode *RMF();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

    };

    RmfContext *rmf();

    class Def_constContext : public antlr4::ParserRuleContext {
    public:
        Def_constContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        virtual size_t getRuleIndex() const override;

        DwContext *dw();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

    };

    Def_constContext *def_const();

    class DwContext : public antlr4::ParserRuleContext {
    public:
        DwContext(antlr4::ParserRuleContext *parent, size_t invokingState);

        virtual size_t getRuleIndex() const override;

        antlr4::tree::TerminalNode *DW();

        AddressContext *address();

        virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

        virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

    };

    DwContext *dw();

  class  EolContext : public antlr4::ParserRuleContext {
  public:
    EolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EolContext* eol();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

