
// Generated from asm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  asmParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, Octal = 7, 
    Decimal = 8, ID = 9, WS = 10, A = 11, N = 12, D = 13, T = 14, I = 15, 
    S = 16, Z = 17, C = 18, J = 19, M = 20, P = 21, O = 22, R = 23, L = 24, 
    B = 25, W = 26, H = 27, K = 28, Q = 29, F = 30, G = 31
  };

  enum {
    RuleCode = 0, RuleStatement = 1, RuleSymbol = 2, RuleInstruction = 3, 
    RuleCtl_ins = 4, RuleStart = 5, RuleMem_ins = 6, RuleMem_op = 7, RuleZero = 8, 
    RuleInd = 9, RuleAddress = 10, RuleOpr_ins = 11, RuleOpr_op1 = 12, RuleOpr_op2 = 13, 
    RuleOpr_op3 = 14, RuleIot_ins = 15, RuleEol = 16
  };

  asmParser(antlr4::TokenStream *input);
  ~asmParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CodeContext;
  class StatementContext;
  class SymbolContext;
  class InstructionContext;
  class Ctl_insContext;
  class StartContext;
  class Mem_insContext;
  class Mem_opContext;
  class ZeroContext;
  class IndContext;
  class AddressContext;
  class Opr_insContext;
  class Opr_op1Context;
  class Opr_op2Context;
  class Opr_op3Context;
  class Iot_insContext;
  class EolContext; 

  class  CodeContext : public antlr4::ParserRuleContext {
  public:
    CodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CodeContext* code();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InstructionContext *instruction();
    SymbolContext *symbol();
    std::vector<EolContext *> eol();
    EolContext* eol(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  SymbolContext : public antlr4::ParserRuleContext {
  public:
    SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SymbolContext* symbol();

  class  InstructionContext : public antlr4::ParserRuleContext {
  public:
    InstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mem_insContext *mem_ins();
    Opr_insContext *opr_ins();
    Iot_insContext *iot_ins();
    Ctl_insContext *ctl_ins();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InstructionContext* instruction();

  class  Ctl_insContext : public antlr4::ParserRuleContext {
  public:
    Ctl_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StartContext *start();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ctl_insContext* ctl_ins();

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddressContext *address();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  Mem_insContext : public antlr4::ParserRuleContext {
  public:
    Mem_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mem_opContext *mem_op();
    AddressContext *address();
    ZeroContext *zero();
    IndContext *ind();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Mem_insContext* mem_ins();

  class  Mem_opContext : public antlr4::ParserRuleContext {
  public:
    Mem_opContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *A();
    antlr4::tree::TerminalNode *N();
    antlr4::tree::TerminalNode *D();
    antlr4::tree::TerminalNode *T();
    antlr4::tree::TerminalNode *I();
    antlr4::tree::TerminalNode *S();
    antlr4::tree::TerminalNode *Z();
    antlr4::tree::TerminalNode *C();
    antlr4::tree::TerminalNode *J();
    antlr4::tree::TerminalNode *M();
    antlr4::tree::TerminalNode *P();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Mem_opContext* mem_op();

  class  ZeroContext : public antlr4::ParserRuleContext {
  public:
    ZeroContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ZeroContext* zero();

  class  IndContext : public antlr4::ParserRuleContext {
  public:
    IndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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
   
  };

  AddressContext* address();

  class  Opr_insContext : public antlr4::ParserRuleContext {
  public:
    Opr_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Opr_op1Context *> opr_op1();
    Opr_op1Context* opr_op1(size_t i);
    std::vector<Opr_op2Context *> opr_op2();
    Opr_op2Context* opr_op2(size_t i);
    std::vector<Opr_op3Context *> opr_op3();
    Opr_op3Context* opr_op3(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Opr_insContext* opr_ins();

  class  Opr_op1Context : public antlr4::ParserRuleContext {
  public:
    Opr_op1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *N();
    antlr4::tree::TerminalNode *O();
    antlr4::tree::TerminalNode *P();
    antlr4::tree::TerminalNode *I();
    antlr4::tree::TerminalNode *A();
    antlr4::tree::TerminalNode *C();
    std::vector<antlr4::tree::TerminalNode *> R();
    antlr4::tree::TerminalNode* R(size_t i);
    std::vector<antlr4::tree::TerminalNode *> L();
    antlr4::tree::TerminalNode* L(size_t i);
    antlr4::tree::TerminalNode *T();
    antlr4::tree::TerminalNode *B();
    antlr4::tree::TerminalNode *S();
    antlr4::tree::TerminalNode *W();
    antlr4::tree::TerminalNode *M();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Opr_op1Context* opr_op1();

  class  Opr_op2Context : public antlr4::ParserRuleContext {
  public:
    Opr_op2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *H();
    antlr4::tree::TerminalNode *L();
    antlr4::tree::TerminalNode *T();
    antlr4::tree::TerminalNode *O();
    antlr4::tree::TerminalNode *S();
    antlr4::tree::TerminalNode *R();
    antlr4::tree::TerminalNode *K();
    antlr4::tree::TerminalNode *P();
    antlr4::tree::TerminalNode *N();
    antlr4::tree::TerminalNode *Z();
    antlr4::tree::TerminalNode *A();
    antlr4::tree::TerminalNode *M();
    antlr4::tree::TerminalNode *C();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Opr_op2Context* opr_op2();

  class  Opr_op3Context : public antlr4::ParserRuleContext {
  public:
    Opr_op3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *C();
    antlr4::tree::TerminalNode *M();
    antlr4::tree::TerminalNode *A();
    antlr4::tree::TerminalNode *Q();
    antlr4::tree::TerminalNode *L();
    antlr4::tree::TerminalNode *S();
    antlr4::tree::TerminalNode *W();
    antlr4::tree::TerminalNode *P();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Opr_op3Context* opr_op3();

  class  Iot_insContext : public antlr4::ParserRuleContext {
  public:
    Iot_insContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *I();
    antlr4::tree::TerminalNode *O();
    antlr4::tree::TerminalNode *T();
    antlr4::tree::TerminalNode *N();
    antlr4::tree::TerminalNode *S();
    antlr4::tree::TerminalNode *K();
    antlr4::tree::TerminalNode *F();
    antlr4::tree::TerminalNode *R();
    antlr4::tree::TerminalNode *Q();
    antlr4::tree::TerminalNode *G();
    antlr4::tree::TerminalNode *C();
    antlr4::tree::TerminalNode *A();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Iot_insContext* iot_ins();

  class  EolContext : public antlr4::ParserRuleContext {
  public:
    EolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
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

