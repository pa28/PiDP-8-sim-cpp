
// Generated from /mnt/v/CLionProjects/PiDP-8-sim-cpp/src/pdp8/asm_parser/Asm.g4 by ANTLR 4.7


#include "AsmListener.h"
#include "AsmVisitor.h"

#include "AsmParser.h"


using namespace antlrcpp;
using namespace antlr4;

AsmParser::AsmParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AsmParser::~AsmParser() {
  delete _interpreter;
}

std::string AsmParser::getGrammarFileName() const {
  return "Asm.g4";
}

const std::vector<std::string>& AsmParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AsmParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CodeContext ------------------------------------------------------------------

AsmParser::CodeContext::CodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::StatementsContext* AsmParser::CodeContext::statements() {
  return getRuleContext<AsmParser::StatementsContext>(0);
}

tree::TerminalNode* AsmParser::CodeContext::EOF() {
  return getToken(AsmParser::EOF, 0);
}


size_t AsmParser::CodeContext::getRuleIndex() const {
  return AsmParser::RuleCode;
}

void AsmParser::CodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCode(this);
}

void AsmParser::CodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCode(this);
}


antlrcpp::Any AsmParser::CodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitCode(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::CodeContext* AsmParser::code() {
  CodeContext *_localctx = _tracker.createInstance<CodeContext>(_ctx, getState());
  enterRule(_localctx, 0, AsmParser::RuleCode);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    statements();
    setState(135);
    match(AsmParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AsmParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AsmParser::StatementContext *> AsmParser::StatementsContext::statement() {
  return getRuleContexts<AsmParser::StatementContext>();
}

AsmParser::StatementContext* AsmParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AsmParser::StatementContext>(i);
}


size_t AsmParser::StatementsContext::getRuleIndex() const {
  return AsmParser::RuleStatements;
}

void AsmParser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void AsmParser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


antlrcpp::Any AsmParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::StatementsContext* AsmParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 2, AsmParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(137);
      statement();
      setState(140); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AsmParser::T__0)
                        | (1ULL << AsmParser::DW)
                        | (1ULL << AsmParser::AND)
                        | (1ULL << AsmParser::TAD)
                        | (1ULL << AsmParser::ISZ)
                        | (1ULL << AsmParser::DCA)
                        | (1ULL << AsmParser::JMS)
                        | (1ULL << AsmParser::JMP)
                        | (1ULL << AsmParser::NOP)
                        | (1ULL << AsmParser::IAC)
                        | (1ULL << AsmParser::RAL)
                        | (1ULL << AsmParser::RTL)
                        | (1ULL << AsmParser::RAR)
                        | (1ULL << AsmParser::RTR)
                        | (1ULL << AsmParser::BSW)
                        | (1ULL << AsmParser::CML)
                        | (1ULL << AsmParser::CMA)
                        | (1ULL << AsmParser::CIA)
                        | (1ULL << AsmParser::CLL)
                        | (1ULL << AsmParser::STL)
                        | (1ULL << AsmParser::CLA)
                        | (1ULL << AsmParser::STA)
                        | (1ULL << AsmParser::HLT)
                        | (1ULL << AsmParser::OSR)
                        | (1ULL << AsmParser::SKP)
                        | (1ULL << AsmParser::SNL)
                        | (1ULL << AsmParser::SZL)
                        | (1ULL << AsmParser::SZA)
                        | (1ULL << AsmParser::SNA)
                        | (1ULL << AsmParser::SMA)
                        | (1ULL << AsmParser::SPA)
                        | (1ULL << AsmParser::CAM)
                        | (1ULL << AsmParser::MQA)
                        | (1ULL << AsmParser::MQL)
                        | (1ULL << AsmParser::SWP)
                        | (1ULL << AsmParser::IOT)
                        | (1ULL << AsmParser::ION)
                        | (1ULL << AsmParser::SKON)
                        | (1ULL << AsmParser::IOF)
                        | (1ULL << AsmParser::SRQ)
                        | (1ULL << AsmParser::GTF)
                        | (1ULL << AsmParser::RTF)
                        | (1ULL << AsmParser::SGT)
                        | (1ULL << AsmParser::CAF)
                        | (1ULL << AsmParser::ID))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AsmParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::InstructionContext* AsmParser::StatementContext::instruction() {
  return getRuleContext<AsmParser::InstructionContext>(0);
}

AsmParser::PragmaContext* AsmParser::StatementContext::pragma() {
  return getRuleContext<AsmParser::PragmaContext>(0);
}


size_t AsmParser::StatementContext::getRuleIndex() const {
  return AsmParser::RuleStatement;
}

void AsmParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void AsmParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any AsmParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::StatementContext* AsmParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, AsmParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(142);
      instruction();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(143);
      pragma();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PragmaContext ------------------------------------------------------------------

AsmParser::PragmaContext::PragmaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::Ctl_insContext* AsmParser::PragmaContext::ctl_ins() {
  return getRuleContext<AsmParser::Ctl_insContext>(0);
}

AsmParser::SymbolContext* AsmParser::PragmaContext::symbol() {
  return getRuleContext<AsmParser::SymbolContext>(0);
}

std::vector<AsmParser::EolContext *> AsmParser::PragmaContext::eol() {
  return getRuleContexts<AsmParser::EolContext>();
}

AsmParser::EolContext* AsmParser::PragmaContext::eol(size_t i) {
  return getRuleContext<AsmParser::EolContext>(i);
}


size_t AsmParser::PragmaContext::getRuleIndex() const {
  return AsmParser::RulePragma;
}

void AsmParser::PragmaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma(this);
}

void AsmParser::PragmaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma(this);
}


antlrcpp::Any AsmParser::PragmaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitPragma(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::PragmaContext* AsmParser::pragma() {
  PragmaContext *_localctx = _tracker.createInstance<PragmaContext>(_ctx, getState());
  enterRule(_localctx, 6, AsmParser::RulePragma);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(146);
      symbol();
        break;
    }

    }
    setState(149);
    ctl_ins();

    setState(151); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(150);
      eol();
      setState(153); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AsmParser::T__3)
      | (1ULL << AsmParser::T__4)
      | (1ULL << AsmParser::T__5))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

AsmParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::Cpu_insContext* AsmParser::InstructionContext::cpu_ins() {
  return getRuleContext<AsmParser::Cpu_insContext>(0);
}

AsmParser::SymbolContext* AsmParser::InstructionContext::symbol() {
  return getRuleContext<AsmParser::SymbolContext>(0);
}

std::vector<AsmParser::EolContext *> AsmParser::InstructionContext::eol() {
  return getRuleContexts<AsmParser::EolContext>();
}

AsmParser::EolContext* AsmParser::InstructionContext::eol(size_t i) {
  return getRuleContext<AsmParser::EolContext>(i);
}


size_t AsmParser::InstructionContext::getRuleIndex() const {
  return AsmParser::RuleInstruction;
}

void AsmParser::InstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstruction(this);
}

void AsmParser::InstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstruction(this);
}


antlrcpp::Any AsmParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::InstructionContext* AsmParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 8, AsmParser::RuleInstruction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AsmParser::ID) {
      setState(155);
      symbol();
    }
    setState(158);
    cpu_ins();

    setState(160); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(159);
      eol();
      setState(162); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AsmParser::T__3)
      | (1ULL << AsmParser::T__4)
      | (1ULL << AsmParser::T__5))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolContext ------------------------------------------------------------------

AsmParser::SymbolContext::SymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SymbolContext::ID() {
  return getToken(AsmParser::ID, 0);
}


size_t AsmParser::SymbolContext::getRuleIndex() const {
  return AsmParser::RuleSymbol;
}

void AsmParser::SymbolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSymbol(this);
}

void AsmParser::SymbolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSymbol(this);
}


antlrcpp::Any AsmParser::SymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSymbol(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SymbolContext* AsmParser::symbol() {
  SymbolContext *_localctx = _tracker.createInstance<SymbolContext>(_ctx, getState());
  enterRule(_localctx, 10, AsmParser::RuleSymbol);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(AsmParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cpu_insContext ------------------------------------------------------------------

AsmParser::Cpu_insContext::Cpu_insContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::Mem_insContext* AsmParser::Cpu_insContext::mem_ins() {
  return getRuleContext<AsmParser::Mem_insContext>(0);
}

AsmParser::Opr_insContext* AsmParser::Cpu_insContext::opr_ins() {
  return getRuleContext<AsmParser::Opr_insContext>(0);
}

AsmParser::Iot_insContext* AsmParser::Cpu_insContext::iot_ins() {
  return getRuleContext<AsmParser::Iot_insContext>(0);
}

AsmParser::Def_constContext *AsmParser::Cpu_insContext::def_const() {
  return getRuleContext<AsmParser::Def_constContext>(0);
}


size_t AsmParser::Cpu_insContext::getRuleIndex() const {
  return AsmParser::RuleCpu_ins;
}

void AsmParser::Cpu_insContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCpu_ins(this);
}

void AsmParser::Cpu_insContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCpu_ins(this);
}


antlrcpp::Any AsmParser::Cpu_insContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitCpu_ins(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Cpu_insContext* AsmParser::cpu_ins() {
  Cpu_insContext *_localctx = _tracker.createInstance<Cpu_insContext>(_ctx, getState());
  enterRule(_localctx, 12, AsmParser::RuleCpu_ins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AsmParser::AND:
      case AsmParser::TAD:
      case AsmParser::ISZ:
      case AsmParser::DCA:
      case AsmParser::JMS:
      case AsmParser::JMP: {
        enterOuterAlt(_localctx, 1);
        setState(166);
        mem_ins();
        break;
      }

      case AsmParser::NOP:
      case AsmParser::IAC:
      case AsmParser::RAL:
      case AsmParser::RTL:
      case AsmParser::RAR:
      case AsmParser::RTR:
      case AsmParser::BSW:
      case AsmParser::CML:
      case AsmParser::CMA:
      case AsmParser::CIA:
      case AsmParser::CLL:
      case AsmParser::STL:
      case AsmParser::CLA:
      case AsmParser::STA:
      case AsmParser::HLT:
      case AsmParser::OSR:
      case AsmParser::SKP:
      case AsmParser::SNL:
      case AsmParser::SZL:
      case AsmParser::SZA:
      case AsmParser::SNA:
      case AsmParser::SMA:
      case AsmParser::SPA:
      case AsmParser::CAM:
      case AsmParser::MQA:
      case AsmParser::MQL:
      case AsmParser::SWP: {
        enterOuterAlt(_localctx, 2);
        setState(167);
        opr_ins();
        break;
      }

      case AsmParser::IOT:
      case AsmParser::ION:
      case AsmParser::SKON:
      case AsmParser::IOF:
      case AsmParser::SRQ:
      case AsmParser::GTF:
      case AsmParser::RTF:
      case AsmParser::SGT:
      case AsmParser::CAF: {
        enterOuterAlt(_localctx, 3);
        setState(168);
        iot_ins();
        break;
      }

      case AsmParser::DW: {
        enterOuterAlt(_localctx, 4);
        setState(169);
        def_const();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ctl_insContext ------------------------------------------------------------------

AsmParser::Ctl_insContext::Ctl_insContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::StartContext* AsmParser::Ctl_insContext::start() {
  return getRuleContext<AsmParser::StartContext>(0);
}

AsmParser::SymbolContext *AsmParser::Ctl_insContext::symbol() {
  return getRuleContext<AsmParser::SymbolContext>(0);
}


size_t AsmParser::Ctl_insContext::getRuleIndex() const {
  return AsmParser::RuleCtl_ins;
}

void AsmParser::Ctl_insContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCtl_ins(this);
}

void AsmParser::Ctl_insContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCtl_ins(this);
}


antlrcpp::Any AsmParser::Ctl_insContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitCtl_ins(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Ctl_insContext* AsmParser::ctl_ins() {
  Ctl_insContext *_localctx = _tracker.createInstance<Ctl_insContext>(_ctx, getState());
  enterRule(_localctx, 14, AsmParser::RuleCtl_ins);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AsmParser::ID) {
      setState(172);
      symbol();
    }
    setState(175);
    start();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartContext ------------------------------------------------------------------

AsmParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::AddressContext* AsmParser::StartContext::address() {
  return getRuleContext<AsmParser::AddressContext>(0);
}

AsmParser::SymbolContext* AsmParser::StartContext::symbol() {
  return getRuleContext<AsmParser::SymbolContext>(0);
}


size_t AsmParser::StartContext::getRuleIndex() const {
  return AsmParser::RuleStart;
}

void AsmParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void AsmParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


antlrcpp::Any AsmParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::StartContext* AsmParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 16, AsmParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
    match(AsmParser::T__0);
    setState(180);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AsmParser::Octal:
      case AsmParser::Decimal: {
        setState(178);
        address();
        break;
      }

      case AsmParser::ID: {
        setState(179);
        symbol();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mem_insContext ------------------------------------------------------------------

AsmParser::Mem_insContext::Mem_insContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::Mem_opContext* AsmParser::Mem_insContext::mem_op() {
  return getRuleContext<AsmParser::Mem_opContext>(0);
}

AsmParser::AddressContext* AsmParser::Mem_insContext::address() {
  return getRuleContext<AsmParser::AddressContext>(0);
}

AsmParser::SymbolContext* AsmParser::Mem_insContext::symbol() {
  return getRuleContext<AsmParser::SymbolContext>(0);
}

AsmParser::ZeroContext* AsmParser::Mem_insContext::zero() {
  return getRuleContext<AsmParser::ZeroContext>(0);
}

AsmParser::IndContext* AsmParser::Mem_insContext::ind() {
  return getRuleContext<AsmParser::IndContext>(0);
}


size_t AsmParser::Mem_insContext::getRuleIndex() const {
  return AsmParser::RuleMem_ins;
}

void AsmParser::Mem_insContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMem_ins(this);
}

void AsmParser::Mem_insContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMem_ins(this);
}


antlrcpp::Any AsmParser::Mem_insContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitMem_ins(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Mem_insContext* AsmParser::mem_ins() {
  Mem_insContext *_localctx = _tracker.createInstance<Mem_insContext>(_ctx, getState());
  enterRule(_localctx, 18, AsmParser::RuleMem_ins);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    mem_op();
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AsmParser::T__1) {
      setState(183);
      zero();
    }
    setState(187);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AsmParser::T__2) {
      setState(186);
      ind();
    }
    setState(191);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AsmParser::Octal:
      case AsmParser::Decimal: {
        setState(189);
        address();
        break;
      }

      case AsmParser::ID: {
        setState(190);
        symbol();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mem_opContext ------------------------------------------------------------------

AsmParser::Mem_opContext::Mem_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::Mem_andContext* AsmParser::Mem_opContext::mem_and() {
  return getRuleContext<AsmParser::Mem_andContext>(0);
}

AsmParser::Mem_tadContext* AsmParser::Mem_opContext::mem_tad() {
  return getRuleContext<AsmParser::Mem_tadContext>(0);
}

AsmParser::Mem_iszContext* AsmParser::Mem_opContext::mem_isz() {
  return getRuleContext<AsmParser::Mem_iszContext>(0);
}

AsmParser::Mem_dcaContext* AsmParser::Mem_opContext::mem_dca() {
  return getRuleContext<AsmParser::Mem_dcaContext>(0);
}

AsmParser::Mem_jmsContext* AsmParser::Mem_opContext::mem_jms() {
  return getRuleContext<AsmParser::Mem_jmsContext>(0);
}

AsmParser::Mem_jmpContext* AsmParser::Mem_opContext::mem_jmp() {
  return getRuleContext<AsmParser::Mem_jmpContext>(0);
}


size_t AsmParser::Mem_opContext::getRuleIndex() const {
  return AsmParser::RuleMem_op;
}

void AsmParser::Mem_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMem_op(this);
}

void AsmParser::Mem_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMem_op(this);
}


antlrcpp::Any AsmParser::Mem_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitMem_op(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Mem_opContext* AsmParser::mem_op() {
  Mem_opContext *_localctx = _tracker.createInstance<Mem_opContext>(_ctx, getState());
  enterRule(_localctx, 20, AsmParser::RuleMem_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(199);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AsmParser::AND: {
        enterOuterAlt(_localctx, 1);
        setState(193);
        mem_and();
        break;
      }

      case AsmParser::TAD: {
        enterOuterAlt(_localctx, 2);
        setState(194);
        mem_tad();
        break;
      }

      case AsmParser::ISZ: {
        enterOuterAlt(_localctx, 3);
        setState(195);
        mem_isz();
        break;
      }

      case AsmParser::DCA: {
        enterOuterAlt(_localctx, 4);
        setState(196);
        mem_dca();
        break;
      }

      case AsmParser::JMS: {
        enterOuterAlt(_localctx, 5);
        setState(197);
        mem_jms();
        break;
      }

      case AsmParser::JMP: {
        enterOuterAlt(_localctx, 6);
        setState(198);
        mem_jmp();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mem_andContext ------------------------------------------------------------------

AsmParser::Mem_andContext::Mem_andContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::Mem_andContext::AND() {
  return getToken(AsmParser::AND, 0);
}


size_t AsmParser::Mem_andContext::getRuleIndex() const {
  return AsmParser::RuleMem_and;
}

void AsmParser::Mem_andContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMem_and(this);
}

void AsmParser::Mem_andContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMem_and(this);
}


antlrcpp::Any AsmParser::Mem_andContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitMem_and(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Mem_andContext* AsmParser::mem_and() {
  Mem_andContext *_localctx = _tracker.createInstance<Mem_andContext>(_ctx, getState());
  enterRule(_localctx, 22, AsmParser::RuleMem_and);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(AsmParser::AND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mem_tadContext ------------------------------------------------------------------

AsmParser::Mem_tadContext::Mem_tadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::Mem_tadContext::TAD() {
  return getToken(AsmParser::TAD, 0);
}


size_t AsmParser::Mem_tadContext::getRuleIndex() const {
  return AsmParser::RuleMem_tad;
}

void AsmParser::Mem_tadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMem_tad(this);
}

void AsmParser::Mem_tadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMem_tad(this);
}


antlrcpp::Any AsmParser::Mem_tadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitMem_tad(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Mem_tadContext* AsmParser::mem_tad() {
  Mem_tadContext *_localctx = _tracker.createInstance<Mem_tadContext>(_ctx, getState());
  enterRule(_localctx, 24, AsmParser::RuleMem_tad);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(203);
    match(AsmParser::TAD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mem_iszContext ------------------------------------------------------------------

AsmParser::Mem_iszContext::Mem_iszContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::Mem_iszContext::ISZ() {
  return getToken(AsmParser::ISZ, 0);
}


size_t AsmParser::Mem_iszContext::getRuleIndex() const {
  return AsmParser::RuleMem_isz;
}

void AsmParser::Mem_iszContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMem_isz(this);
}

void AsmParser::Mem_iszContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMem_isz(this);
}


antlrcpp::Any AsmParser::Mem_iszContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitMem_isz(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Mem_iszContext* AsmParser::mem_isz() {
  Mem_iszContext *_localctx = _tracker.createInstance<Mem_iszContext>(_ctx, getState());
  enterRule(_localctx, 26, AsmParser::RuleMem_isz);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(AsmParser::ISZ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mem_dcaContext ------------------------------------------------------------------

AsmParser::Mem_dcaContext::Mem_dcaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::Mem_dcaContext::DCA() {
  return getToken(AsmParser::DCA, 0);
}


size_t AsmParser::Mem_dcaContext::getRuleIndex() const {
  return AsmParser::RuleMem_dca;
}

void AsmParser::Mem_dcaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMem_dca(this);
}

void AsmParser::Mem_dcaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMem_dca(this);
}


antlrcpp::Any AsmParser::Mem_dcaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitMem_dca(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Mem_dcaContext* AsmParser::mem_dca() {
  Mem_dcaContext *_localctx = _tracker.createInstance<Mem_dcaContext>(_ctx, getState());
  enterRule(_localctx, 28, AsmParser::RuleMem_dca);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    match(AsmParser::DCA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mem_jmsContext ------------------------------------------------------------------

AsmParser::Mem_jmsContext::Mem_jmsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::Mem_jmsContext::JMS() {
  return getToken(AsmParser::JMS, 0);
}


size_t AsmParser::Mem_jmsContext::getRuleIndex() const {
  return AsmParser::RuleMem_jms;
}

void AsmParser::Mem_jmsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMem_jms(this);
}

void AsmParser::Mem_jmsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMem_jms(this);
}


antlrcpp::Any AsmParser::Mem_jmsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitMem_jms(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Mem_jmsContext* AsmParser::mem_jms() {
  Mem_jmsContext *_localctx = _tracker.createInstance<Mem_jmsContext>(_ctx, getState());
  enterRule(_localctx, 30, AsmParser::RuleMem_jms);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(AsmParser::JMS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Mem_jmpContext ------------------------------------------------------------------

AsmParser::Mem_jmpContext::Mem_jmpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::Mem_jmpContext::JMP() {
  return getToken(AsmParser::JMP, 0);
}


size_t AsmParser::Mem_jmpContext::getRuleIndex() const {
  return AsmParser::RuleMem_jmp;
}

void AsmParser::Mem_jmpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMem_jmp(this);
}

void AsmParser::Mem_jmpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMem_jmp(this);
}


antlrcpp::Any AsmParser::Mem_jmpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitMem_jmp(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Mem_jmpContext* AsmParser::mem_jmp() {
  Mem_jmpContext *_localctx = _tracker.createInstance<Mem_jmpContext>(_ctx, getState());
  enterRule(_localctx, 32, AsmParser::RuleMem_jmp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    match(AsmParser::JMP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ZeroContext ------------------------------------------------------------------

AsmParser::ZeroContext::ZeroContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AsmParser::ZeroContext::getRuleIndex() const {
  return AsmParser::RuleZero;
}

void AsmParser::ZeroContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterZero(this);
}

void AsmParser::ZeroContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitZero(this);
}


antlrcpp::Any AsmParser::ZeroContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitZero(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::ZeroContext* AsmParser::zero() {
  ZeroContext *_localctx = _tracker.createInstance<ZeroContext>(_ctx, getState());
  enterRule(_localctx, 34, AsmParser::RuleZero);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(AsmParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndContext ------------------------------------------------------------------

AsmParser::IndContext::IndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AsmParser::IndContext::getRuleIndex() const {
  return AsmParser::RuleInd;
}

void AsmParser::IndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInd(this);
}

void AsmParser::IndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInd(this);
}


antlrcpp::Any AsmParser::IndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitInd(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::IndContext* AsmParser::ind() {
  IndContext *_localctx = _tracker.createInstance<IndContext>(_ctx, getState());
  enterRule(_localctx, 36, AsmParser::RuleInd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(AsmParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddressContext ------------------------------------------------------------------

AsmParser::AddressContext::AddressContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::AddressContext::Octal() {
  return getToken(AsmParser::Octal, 0);
}

tree::TerminalNode* AsmParser::AddressContext::Decimal() {
  return getToken(AsmParser::Decimal, 0);
}


size_t AsmParser::AddressContext::getRuleIndex() const {
  return AsmParser::RuleAddress;
}

void AsmParser::AddressContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddress(this);
}

void AsmParser::AddressContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddress(this);
}


antlrcpp::Any AsmParser::AddressContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitAddress(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::AddressContext* AsmParser::address() {
  AddressContext *_localctx = _tracker.createInstance<AddressContext>(_ctx, getState());
  enterRule(_localctx, 38, AsmParser::RuleAddress);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    _la = _input->LA(1);
    if (!(_la == AsmParser::Octal

    || _la == AsmParser::Decimal)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Opr_insContext ------------------------------------------------------------------

AsmParser::Opr_insContext::Opr_insContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::Opr_op1Context* AsmParser::Opr_insContext::opr_op1() {
  return getRuleContext<AsmParser::Opr_op1Context>(0);
}

AsmParser::Opr_op2Context* AsmParser::Opr_insContext::opr_op2() {
  return getRuleContext<AsmParser::Opr_op2Context>(0);
}

AsmParser::Opr_op3Context* AsmParser::Opr_insContext::opr_op3() {
  return getRuleContext<AsmParser::Opr_op3Context>(0);
}


size_t AsmParser::Opr_insContext::getRuleIndex() const {
  return AsmParser::RuleOpr_ins;
}

void AsmParser::Opr_insContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpr_ins(this);
}

void AsmParser::Opr_insContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpr_ins(this);
}


antlrcpp::Any AsmParser::Opr_insContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitOpr_ins(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Opr_insContext* AsmParser::opr_ins() {
  Opr_insContext *_localctx = _tracker.createInstance<Opr_insContext>(_ctx, getState());
  enterRule(_localctx, 40, AsmParser::RuleOpr_ins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(222);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(219);
      opr_op1();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(220);
      opr_op2();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(221);
      opr_op3();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Opr_op1Context ------------------------------------------------------------------

AsmParser::Opr_op1Context::Opr_op1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AsmParser::Opr_op1_insContext *> AsmParser::Opr_op1Context::opr_op1_ins() {
  return getRuleContexts<AsmParser::Opr_op1_insContext>();
}

AsmParser::Opr_op1_insContext* AsmParser::Opr_op1Context::opr_op1_ins(size_t i) {
  return getRuleContext<AsmParser::Opr_op1_insContext>(i);
}


size_t AsmParser::Opr_op1Context::getRuleIndex() const {
  return AsmParser::RuleOpr_op1;
}

void AsmParser::Opr_op1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpr_op1(this);
}

void AsmParser::Opr_op1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpr_op1(this);
}


antlrcpp::Any AsmParser::Opr_op1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitOpr_op1(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Opr_op1Context* AsmParser::opr_op1() {
  Opr_op1Context *_localctx = _tracker.createInstance<Opr_op1Context>(_ctx, getState());
  enterRule(_localctx, 42, AsmParser::RuleOpr_op1);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(224);
      opr_op1_ins();
      setState(227); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AsmParser::NOP)
                        | (1ULL << AsmParser::IAC)
                        | (1ULL << AsmParser::RAL)
                        | (1ULL << AsmParser::RTL)
                        | (1ULL << AsmParser::RAR)
                        | (1ULL << AsmParser::RTR)
                        | (1ULL << AsmParser::BSW)
                        | (1ULL << AsmParser::CML)
                        | (1ULL << AsmParser::CMA)
                        | (1ULL << AsmParser::CIA)
                        | (1ULL << AsmParser::CLL)
                        | (1ULL << AsmParser::STL)
                        | (1ULL << AsmParser::CLA)
                        | (1ULL << AsmParser::STA))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Opr_op1_insContext ------------------------------------------------------------------

AsmParser::Opr_op1_insContext::Opr_op1_insContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::NopContext* AsmParser::Opr_op1_insContext::nop() {
  return getRuleContext<AsmParser::NopContext>(0);
}

AsmParser::IacContext* AsmParser::Opr_op1_insContext::iac() {
  return getRuleContext<AsmParser::IacContext>(0);
}

AsmParser::RalContext* AsmParser::Opr_op1_insContext::ral() {
  return getRuleContext<AsmParser::RalContext>(0);
}

AsmParser::RtlContext* AsmParser::Opr_op1_insContext::rtl() {
  return getRuleContext<AsmParser::RtlContext>(0);
}

AsmParser::RarContext* AsmParser::Opr_op1_insContext::rar() {
  return getRuleContext<AsmParser::RarContext>(0);
}

AsmParser::RtrContext* AsmParser::Opr_op1_insContext::rtr() {
  return getRuleContext<AsmParser::RtrContext>(0);
}

AsmParser::BswContext* AsmParser::Opr_op1_insContext::bsw() {
  return getRuleContext<AsmParser::BswContext>(0);
}

AsmParser::CmlContext* AsmParser::Opr_op1_insContext::cml() {
  return getRuleContext<AsmParser::CmlContext>(0);
}

AsmParser::CmaContext* AsmParser::Opr_op1_insContext::cma() {
  return getRuleContext<AsmParser::CmaContext>(0);
}

AsmParser::CiaContext* AsmParser::Opr_op1_insContext::cia() {
  return getRuleContext<AsmParser::CiaContext>(0);
}

AsmParser::CllContext* AsmParser::Opr_op1_insContext::cll() {
  return getRuleContext<AsmParser::CllContext>(0);
}

AsmParser::StlContext* AsmParser::Opr_op1_insContext::stl() {
  return getRuleContext<AsmParser::StlContext>(0);
}

AsmParser::ClaContext* AsmParser::Opr_op1_insContext::cla() {
  return getRuleContext<AsmParser::ClaContext>(0);
}

AsmParser::StaContext* AsmParser::Opr_op1_insContext::sta() {
  return getRuleContext<AsmParser::StaContext>(0);
}


size_t AsmParser::Opr_op1_insContext::getRuleIndex() const {
  return AsmParser::RuleOpr_op1_ins;
}

void AsmParser::Opr_op1_insContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpr_op1_ins(this);
}

void AsmParser::Opr_op1_insContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpr_op1_ins(this);
}


antlrcpp::Any AsmParser::Opr_op1_insContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitOpr_op1_ins(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Opr_op1_insContext* AsmParser::opr_op1_ins() {
  Opr_op1_insContext *_localctx = _tracker.createInstance<Opr_op1_insContext>(_ctx, getState());
  enterRule(_localctx, 44, AsmParser::RuleOpr_op1_ins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(243);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AsmParser::NOP: {
        enterOuterAlt(_localctx, 1);
        setState(229);
        nop();
        break;
      }

      case AsmParser::IAC: {
        enterOuterAlt(_localctx, 2);
        setState(230);
        iac();
        break;
      }

      case AsmParser::RAL: {
        enterOuterAlt(_localctx, 3);
        setState(231);
        ral();
        break;
      }

      case AsmParser::RTL: {
        enterOuterAlt(_localctx, 4);
        setState(232);
        rtl();
        break;
      }

      case AsmParser::RAR: {
        enterOuterAlt(_localctx, 5);
        setState(233);
        rar();
        break;
      }

      case AsmParser::RTR: {
        enterOuterAlt(_localctx, 6);
        setState(234);
        rtr();
        break;
      }

      case AsmParser::BSW: {
        enterOuterAlt(_localctx, 7);
        setState(235);
        bsw();
        break;
      }

      case AsmParser::CML: {
        enterOuterAlt(_localctx, 8);
        setState(236);
        cml();
        break;
      }

      case AsmParser::CMA: {
        enterOuterAlt(_localctx, 9);
        setState(237);
        cma();
        break;
      }

      case AsmParser::CIA: {
        enterOuterAlt(_localctx, 10);
        setState(238);
        cia();
        break;
      }

      case AsmParser::CLL: {
        enterOuterAlt(_localctx, 11);
        setState(239);
        cll();
        break;
      }

      case AsmParser::STL: {
        enterOuterAlt(_localctx, 12);
        setState(240);
        stl();
        break;
      }

      case AsmParser::CLA: {
        enterOuterAlt(_localctx, 13);
        setState(241);
        cla();
        break;
      }

      case AsmParser::STA: {
        enterOuterAlt(_localctx, 14);
        setState(242);
        sta();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NopContext ------------------------------------------------------------------

AsmParser::NopContext::NopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::NopContext::NOP() {
  return getToken(AsmParser::NOP, 0);
}


size_t AsmParser::NopContext::getRuleIndex() const {
  return AsmParser::RuleNop;
}

void AsmParser::NopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNop(this);
}

void AsmParser::NopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNop(this);
}


antlrcpp::Any AsmParser::NopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitNop(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::NopContext* AsmParser::nop() {
  NopContext *_localctx = _tracker.createInstance<NopContext>(_ctx, getState());
  enterRule(_localctx, 46, AsmParser::RuleNop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(AsmParser::NOP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IacContext ------------------------------------------------------------------

AsmParser::IacContext::IacContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::IacContext::IAC() {
  return getToken(AsmParser::IAC, 0);
}


size_t AsmParser::IacContext::getRuleIndex() const {
  return AsmParser::RuleIac;
}

void AsmParser::IacContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIac(this);
}

void AsmParser::IacContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIac(this);
}


antlrcpp::Any AsmParser::IacContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitIac(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::IacContext* AsmParser::iac() {
  IacContext *_localctx = _tracker.createInstance<IacContext>(_ctx, getState());
  enterRule(_localctx, 48, AsmParser::RuleIac);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(AsmParser::IAC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RalContext ------------------------------------------------------------------

AsmParser::RalContext::RalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode *AsmParser::RalContext::RAL() {
  return getToken(AsmParser::RAL, 0);
}


size_t AsmParser::RalContext::getRuleIndex() const {
  return AsmParser::RuleRal;
}

void AsmParser::RalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRal(this);
}

void AsmParser::RalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRal(this);
}


antlrcpp::Any AsmParser::RalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitRal(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::RalContext* AsmParser::ral() {
  RalContext *_localctx = _tracker.createInstance<RalContext>(_ctx, getState());
  enterRule(_localctx, 50, AsmParser::RuleRal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(AsmParser::RAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RtlContext ------------------------------------------------------------------

AsmParser::RtlContext::RtlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::RtlContext::RTL() {
  return getToken(AsmParser::RTL, 0);
}


size_t AsmParser::RtlContext::getRuleIndex() const {
  return AsmParser::RuleRtl;
}

void AsmParser::RtlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRtl(this);
}

void AsmParser::RtlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRtl(this);
}


antlrcpp::Any AsmParser::RtlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitRtl(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::RtlContext* AsmParser::rtl() {
  RtlContext *_localctx = _tracker.createInstance<RtlContext>(_ctx, getState());
  enterRule(_localctx, 52, AsmParser::RuleRtl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    match(AsmParser::RTL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RarContext ------------------------------------------------------------------

AsmParser::RarContext::RarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::RarContext::RAR() {
  return getToken(AsmParser::RAR, 0);
}


size_t AsmParser::RarContext::getRuleIndex() const {
  return AsmParser::RuleRar;
}

void AsmParser::RarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRar(this);
}

void AsmParser::RarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRar(this);
}


antlrcpp::Any AsmParser::RarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitRar(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::RarContext* AsmParser::rar() {
  RarContext *_localctx = _tracker.createInstance<RarContext>(_ctx, getState());
  enterRule(_localctx, 54, AsmParser::RuleRar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(AsmParser::RAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RtrContext ------------------------------------------------------------------

AsmParser::RtrContext::RtrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::RtrContext::RTR() {
  return getToken(AsmParser::RTR, 0);
}


size_t AsmParser::RtrContext::getRuleIndex() const {
  return AsmParser::RuleRtr;
}

void AsmParser::RtrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRtr(this);
}

void AsmParser::RtrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRtr(this);
}


antlrcpp::Any AsmParser::RtrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitRtr(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::RtrContext* AsmParser::rtr() {
  RtrContext *_localctx = _tracker.createInstance<RtrContext>(_ctx, getState());
  enterRule(_localctx, 56, AsmParser::RuleRtr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    match(AsmParser::RTR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BswContext ------------------------------------------------------------------

AsmParser::BswContext::BswContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::BswContext::BSW() {
  return getToken(AsmParser::BSW, 0);
}


size_t AsmParser::BswContext::getRuleIndex() const {
  return AsmParser::RuleBsw;
}

void AsmParser::BswContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBsw(this);
}

void AsmParser::BswContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBsw(this);
}


antlrcpp::Any AsmParser::BswContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitBsw(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::BswContext* AsmParser::bsw() {
  BswContext *_localctx = _tracker.createInstance<BswContext>(_ctx, getState());
  enterRule(_localctx, 58, AsmParser::RuleBsw);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    match(AsmParser::BSW);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CmlContext ------------------------------------------------------------------

AsmParser::CmlContext::CmlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::CmlContext::CML() {
  return getToken(AsmParser::CML, 0);
}


size_t AsmParser::CmlContext::getRuleIndex() const {
  return AsmParser::RuleCml;
}

void AsmParser::CmlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCml(this);
}

void AsmParser::CmlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCml(this);
}


antlrcpp::Any AsmParser::CmlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitCml(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::CmlContext* AsmParser::cml() {
  CmlContext *_localctx = _tracker.createInstance<CmlContext>(_ctx, getState());
  enterRule(_localctx, 60, AsmParser::RuleCml);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(259);
    match(AsmParser::CML);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CmaContext ------------------------------------------------------------------

AsmParser::CmaContext::CmaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::CmaContext::CMA() {
  return getToken(AsmParser::CMA, 0);
}


size_t AsmParser::CmaContext::getRuleIndex() const {
  return AsmParser::RuleCma;
}

void AsmParser::CmaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCma(this);
}

void AsmParser::CmaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCma(this);
}


antlrcpp::Any AsmParser::CmaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitCma(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::CmaContext* AsmParser::cma() {
  CmaContext *_localctx = _tracker.createInstance<CmaContext>(_ctx, getState());
  enterRule(_localctx, 62, AsmParser::RuleCma);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    match(AsmParser::CMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CiaContext ------------------------------------------------------------------

AsmParser::CiaContext::CiaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::CiaContext::CIA() {
  return getToken(AsmParser::CIA, 0);
}


size_t AsmParser::CiaContext::getRuleIndex() const {
  return AsmParser::RuleCia;
}

void AsmParser::CiaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCia(this);
}

void AsmParser::CiaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCia(this);
}


antlrcpp::Any AsmParser::CiaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitCia(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::CiaContext* AsmParser::cia() {
  CiaContext *_localctx = _tracker.createInstance<CiaContext>(_ctx, getState());
  enterRule(_localctx, 64, AsmParser::RuleCia);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(AsmParser::CIA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CllContext ------------------------------------------------------------------

AsmParser::CllContext::CllContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::CllContext::CLL() {
  return getToken(AsmParser::CLL, 0);
}


size_t AsmParser::CllContext::getRuleIndex() const {
  return AsmParser::RuleCll;
}

void AsmParser::CllContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCll(this);
}

void AsmParser::CllContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCll(this);
}


antlrcpp::Any AsmParser::CllContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitCll(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::CllContext* AsmParser::cll() {
  CllContext *_localctx = _tracker.createInstance<CllContext>(_ctx, getState());
  enterRule(_localctx, 66, AsmParser::RuleCll);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    match(AsmParser::CLL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StlContext ------------------------------------------------------------------

AsmParser::StlContext::StlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::StlContext::STL() {
  return getToken(AsmParser::STL, 0);
}


size_t AsmParser::StlContext::getRuleIndex() const {
  return AsmParser::RuleStl;
}

void AsmParser::StlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStl(this);
}

void AsmParser::StlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStl(this);
}


antlrcpp::Any AsmParser::StlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitStl(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::StlContext* AsmParser::stl() {
  StlContext *_localctx = _tracker.createInstance<StlContext>(_ctx, getState());
  enterRule(_localctx, 68, AsmParser::RuleStl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(AsmParser::STL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClaContext ------------------------------------------------------------------

AsmParser::ClaContext::ClaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::ClaContext::CLA() {
  return getToken(AsmParser::CLA, 0);
}


size_t AsmParser::ClaContext::getRuleIndex() const {
  return AsmParser::RuleCla;
}

void AsmParser::ClaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCla(this);
}

void AsmParser::ClaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCla(this);
}


antlrcpp::Any AsmParser::ClaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitCla(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::ClaContext* AsmParser::cla() {
  ClaContext *_localctx = _tracker.createInstance<ClaContext>(_ctx, getState());
  enterRule(_localctx, 70, AsmParser::RuleCla);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    match(AsmParser::CLA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StaContext ------------------------------------------------------------------

AsmParser::StaContext::StaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::StaContext::STA() {
  return getToken(AsmParser::STA, 0);
}


size_t AsmParser::StaContext::getRuleIndex() const {
  return AsmParser::RuleSta;
}

void AsmParser::StaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSta(this);
}

void AsmParser::StaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSta(this);
}


antlrcpp::Any AsmParser::StaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSta(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::StaContext* AsmParser::sta() {
  StaContext *_localctx = _tracker.createInstance<StaContext>(_ctx, getState());
  enterRule(_localctx, 72, AsmParser::RuleSta);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(AsmParser::STA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Opr_op2Context ------------------------------------------------------------------

AsmParser::Opr_op2Context::Opr_op2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AsmParser::Opr_op2_insContext *> AsmParser::Opr_op2Context::opr_op2_ins() {
  return getRuleContexts<AsmParser::Opr_op2_insContext>();
}

AsmParser::Opr_op2_insContext* AsmParser::Opr_op2Context::opr_op2_ins(size_t i) {
  return getRuleContext<AsmParser::Opr_op2_insContext>(i);
}


size_t AsmParser::Opr_op2Context::getRuleIndex() const {
  return AsmParser::RuleOpr_op2;
}

void AsmParser::Opr_op2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpr_op2(this);
}

void AsmParser::Opr_op2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpr_op2(this);
}


antlrcpp::Any AsmParser::Opr_op2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitOpr_op2(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Opr_op2Context* AsmParser::opr_op2() {
  Opr_op2Context *_localctx = _tracker.createInstance<Opr_op2Context>(_ctx, getState());
  enterRule(_localctx, 74, AsmParser::RuleOpr_op2);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(273);
      opr_op2_ins();
      setState(276); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AsmParser::CLA)
      | (1ULL << AsmParser::HLT)
      | (1ULL << AsmParser::OSR)
      | (1ULL << AsmParser::SKP)
      | (1ULL << AsmParser::SNL)
      | (1ULL << AsmParser::SZL)
      | (1ULL << AsmParser::SZA)
      | (1ULL << AsmParser::SNA)
      | (1ULL << AsmParser::SMA)
      | (1ULL << AsmParser::SPA))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Opr_op2_insContext ------------------------------------------------------------------

AsmParser::Opr_op2_insContext::Opr_op2_insContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::HltContext* AsmParser::Opr_op2_insContext::hlt() {
  return getRuleContext<AsmParser::HltContext>(0);
}

AsmParser::OsrContext* AsmParser::Opr_op2_insContext::osr() {
  return getRuleContext<AsmParser::OsrContext>(0);
}

AsmParser::SkpContext* AsmParser::Opr_op2_insContext::skp() {
  return getRuleContext<AsmParser::SkpContext>(0);
}

AsmParser::SnlContext* AsmParser::Opr_op2_insContext::snl() {
  return getRuleContext<AsmParser::SnlContext>(0);
}

AsmParser::SzlContext* AsmParser::Opr_op2_insContext::szl() {
  return getRuleContext<AsmParser::SzlContext>(0);
}

AsmParser::SzaContext* AsmParser::Opr_op2_insContext::sza() {
  return getRuleContext<AsmParser::SzaContext>(0);
}

AsmParser::SnaContext* AsmParser::Opr_op2_insContext::sna() {
  return getRuleContext<AsmParser::SnaContext>(0);
}

AsmParser::SmaContext* AsmParser::Opr_op2_insContext::sma() {
  return getRuleContext<AsmParser::SmaContext>(0);
}

AsmParser::SpaContext* AsmParser::Opr_op2_insContext::spa() {
  return getRuleContext<AsmParser::SpaContext>(0);
}

AsmParser::ClaContext* AsmParser::Opr_op2_insContext::cla() {
  return getRuleContext<AsmParser::ClaContext>(0);
}


size_t AsmParser::Opr_op2_insContext::getRuleIndex() const {
  return AsmParser::RuleOpr_op2_ins;
}

void AsmParser::Opr_op2_insContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpr_op2_ins(this);
}

void AsmParser::Opr_op2_insContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpr_op2_ins(this);
}


antlrcpp::Any AsmParser::Opr_op2_insContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitOpr_op2_ins(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Opr_op2_insContext* AsmParser::opr_op2_ins() {
  Opr_op2_insContext *_localctx = _tracker.createInstance<Opr_op2_insContext>(_ctx, getState());
  enterRule(_localctx, 76, AsmParser::RuleOpr_op2_ins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(288);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AsmParser::HLT: {
        enterOuterAlt(_localctx, 1);
        setState(278);
        hlt();
        break;
      }

      case AsmParser::OSR: {
        enterOuterAlt(_localctx, 2);
        setState(279);
        osr();
        break;
      }

      case AsmParser::SKP: {
        enterOuterAlt(_localctx, 3);
        setState(280);
        skp();
        break;
      }

      case AsmParser::SNL: {
        enterOuterAlt(_localctx, 4);
        setState(281);
        snl();
        break;
      }

      case AsmParser::SZL: {
        enterOuterAlt(_localctx, 5);
        setState(282);
        szl();
        break;
      }

      case AsmParser::SZA: {
        enterOuterAlt(_localctx, 6);
        setState(283);
        sza();
        break;
      }

      case AsmParser::SNA: {
        enterOuterAlt(_localctx, 7);
        setState(284);
        sna();
        break;
      }

      case AsmParser::SMA: {
        enterOuterAlt(_localctx, 8);
        setState(285);
        sma();
        break;
      }

      case AsmParser::SPA: {
        enterOuterAlt(_localctx, 9);
        setState(286);
        spa();
        break;
      }

      case AsmParser::CLA: {
        enterOuterAlt(_localctx, 10);
        setState(287);
        cla();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HltContext ------------------------------------------------------------------

AsmParser::HltContext::HltContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::HltContext::HLT() {
  return getToken(AsmParser::HLT, 0);
}


size_t AsmParser::HltContext::getRuleIndex() const {
  return AsmParser::RuleHlt;
}

void AsmParser::HltContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHlt(this);
}

void AsmParser::HltContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHlt(this);
}


antlrcpp::Any AsmParser::HltContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitHlt(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::HltContext* AsmParser::hlt() {
  HltContext *_localctx = _tracker.createInstance<HltContext>(_ctx, getState());
  enterRule(_localctx, 78, AsmParser::RuleHlt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    match(AsmParser::HLT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OsrContext ------------------------------------------------------------------

AsmParser::OsrContext::OsrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::OsrContext::OSR() {
  return getToken(AsmParser::OSR, 0);
}


size_t AsmParser::OsrContext::getRuleIndex() const {
  return AsmParser::RuleOsr;
}

void AsmParser::OsrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOsr(this);
}

void AsmParser::OsrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOsr(this);
}


antlrcpp::Any AsmParser::OsrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitOsr(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::OsrContext* AsmParser::osr() {
  OsrContext *_localctx = _tracker.createInstance<OsrContext>(_ctx, getState());
  enterRule(_localctx, 80, AsmParser::RuleOsr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    match(AsmParser::OSR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SkpContext ------------------------------------------------------------------

AsmParser::SkpContext::SkpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SkpContext::SKP() {
  return getToken(AsmParser::SKP, 0);
}


size_t AsmParser::SkpContext::getRuleIndex() const {
  return AsmParser::RuleSkp;
}

void AsmParser::SkpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSkp(this);
}

void AsmParser::SkpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSkp(this);
}


antlrcpp::Any AsmParser::SkpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSkp(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SkpContext* AsmParser::skp() {
  SkpContext *_localctx = _tracker.createInstance<SkpContext>(_ctx, getState());
  enterRule(_localctx, 82, AsmParser::RuleSkp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    match(AsmParser::SKP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SnlContext ------------------------------------------------------------------

AsmParser::SnlContext::SnlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SnlContext::SNL() {
  return getToken(AsmParser::SNL, 0);
}


size_t AsmParser::SnlContext::getRuleIndex() const {
  return AsmParser::RuleSnl;
}

void AsmParser::SnlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSnl(this);
}

void AsmParser::SnlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSnl(this);
}


antlrcpp::Any AsmParser::SnlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSnl(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SnlContext* AsmParser::snl() {
  SnlContext *_localctx = _tracker.createInstance<SnlContext>(_ctx, getState());
  enterRule(_localctx, 84, AsmParser::RuleSnl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    match(AsmParser::SNL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SzlContext ------------------------------------------------------------------

AsmParser::SzlContext::SzlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SzlContext::SZL() {
  return getToken(AsmParser::SZL, 0);
}


size_t AsmParser::SzlContext::getRuleIndex() const {
  return AsmParser::RuleSzl;
}

void AsmParser::SzlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSzl(this);
}

void AsmParser::SzlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSzl(this);
}


antlrcpp::Any AsmParser::SzlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSzl(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SzlContext* AsmParser::szl() {
  SzlContext *_localctx = _tracker.createInstance<SzlContext>(_ctx, getState());
  enterRule(_localctx, 86, AsmParser::RuleSzl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(298);
    match(AsmParser::SZL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SzaContext ------------------------------------------------------------------

AsmParser::SzaContext::SzaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SzaContext::SZA() {
  return getToken(AsmParser::SZA, 0);
}


size_t AsmParser::SzaContext::getRuleIndex() const {
  return AsmParser::RuleSza;
}

void AsmParser::SzaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSza(this);
}

void AsmParser::SzaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSza(this);
}


antlrcpp::Any AsmParser::SzaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSza(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SzaContext* AsmParser::sza() {
  SzaContext *_localctx = _tracker.createInstance<SzaContext>(_ctx, getState());
  enterRule(_localctx, 88, AsmParser::RuleSza);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(300);
    match(AsmParser::SZA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SnaContext ------------------------------------------------------------------

AsmParser::SnaContext::SnaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SnaContext::SNA() {
  return getToken(AsmParser::SNA, 0);
}


size_t AsmParser::SnaContext::getRuleIndex() const {
  return AsmParser::RuleSna;
}

void AsmParser::SnaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSna(this);
}

void AsmParser::SnaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSna(this);
}


antlrcpp::Any AsmParser::SnaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSna(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SnaContext* AsmParser::sna() {
  SnaContext *_localctx = _tracker.createInstance<SnaContext>(_ctx, getState());
  enterRule(_localctx, 90, AsmParser::RuleSna);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    match(AsmParser::SNA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SmaContext ------------------------------------------------------------------

AsmParser::SmaContext::SmaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SmaContext::SMA() {
  return getToken(AsmParser::SMA, 0);
}


size_t AsmParser::SmaContext::getRuleIndex() const {
  return AsmParser::RuleSma;
}

void AsmParser::SmaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSma(this);
}

void AsmParser::SmaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSma(this);
}


antlrcpp::Any AsmParser::SmaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSma(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SmaContext* AsmParser::sma() {
  SmaContext *_localctx = _tracker.createInstance<SmaContext>(_ctx, getState());
  enterRule(_localctx, 92, AsmParser::RuleSma);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    match(AsmParser::SMA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SpaContext ------------------------------------------------------------------

AsmParser::SpaContext::SpaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SpaContext::SPA() {
  return getToken(AsmParser::SPA, 0);
}


size_t AsmParser::SpaContext::getRuleIndex() const {
  return AsmParser::RuleSpa;
}

void AsmParser::SpaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpa(this);
}

void AsmParser::SpaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpa(this);
}


antlrcpp::Any AsmParser::SpaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSpa(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SpaContext* AsmParser::spa() {
  SpaContext *_localctx = _tracker.createInstance<SpaContext>(_ctx, getState());
  enterRule(_localctx, 94, AsmParser::RuleSpa);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(AsmParser::SPA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Opr_op3Context ------------------------------------------------------------------

AsmParser::Opr_op3Context::Opr_op3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AsmParser::Opr_op3_insContext *> AsmParser::Opr_op3Context::opr_op3_ins() {
  return getRuleContexts<AsmParser::Opr_op3_insContext>();
}

AsmParser::Opr_op3_insContext* AsmParser::Opr_op3Context::opr_op3_ins(size_t i) {
  return getRuleContext<AsmParser::Opr_op3_insContext>(i);
}


size_t AsmParser::Opr_op3Context::getRuleIndex() const {
  return AsmParser::RuleOpr_op3;
}

void AsmParser::Opr_op3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpr_op3(this);
}

void AsmParser::Opr_op3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpr_op3(this);
}


antlrcpp::Any AsmParser::Opr_op3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitOpr_op3(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Opr_op3Context* AsmParser::opr_op3() {
  Opr_op3Context *_localctx = _tracker.createInstance<Opr_op3Context>(_ctx, getState());
  enterRule(_localctx, 96, AsmParser::RuleOpr_op3);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(308);
      opr_op3_ins();
      setState(311); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AsmParser::CAM)
      | (1ULL << AsmParser::MQA)
      | (1ULL << AsmParser::MQL)
      | (1ULL << AsmParser::SWP))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Opr_op3_insContext ------------------------------------------------------------------

AsmParser::Opr_op3_insContext::Opr_op3_insContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::CamContext* AsmParser::Opr_op3_insContext::cam() {
  return getRuleContext<AsmParser::CamContext>(0);
}

AsmParser::MqaContext* AsmParser::Opr_op3_insContext::mqa() {
  return getRuleContext<AsmParser::MqaContext>(0);
}

AsmParser::MqlContext* AsmParser::Opr_op3_insContext::mql() {
  return getRuleContext<AsmParser::MqlContext>(0);
}

AsmParser::SwpContext* AsmParser::Opr_op3_insContext::swp() {
  return getRuleContext<AsmParser::SwpContext>(0);
}


size_t AsmParser::Opr_op3_insContext::getRuleIndex() const {
  return AsmParser::RuleOpr_op3_ins;
}

void AsmParser::Opr_op3_insContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpr_op3_ins(this);
}

void AsmParser::Opr_op3_insContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpr_op3_ins(this);
}


antlrcpp::Any AsmParser::Opr_op3_insContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitOpr_op3_ins(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Opr_op3_insContext* AsmParser::opr_op3_ins() {
  Opr_op3_insContext *_localctx = _tracker.createInstance<Opr_op3_insContext>(_ctx, getState());
  enterRule(_localctx, 98, AsmParser::RuleOpr_op3_ins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(317);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AsmParser::CAM: {
        enterOuterAlt(_localctx, 1);
        setState(313);
        cam();
        break;
      }

      case AsmParser::MQA: {
        enterOuterAlt(_localctx, 2);
        setState(314);
        mqa();
        break;
      }

      case AsmParser::MQL: {
        enterOuterAlt(_localctx, 3);
        setState(315);
        mql();
        break;
      }

      case AsmParser::SWP: {
        enterOuterAlt(_localctx, 4);
        setState(316);
        swp();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CamContext ------------------------------------------------------------------

AsmParser::CamContext::CamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::CamContext::CAM() {
  return getToken(AsmParser::CAM, 0);
}


size_t AsmParser::CamContext::getRuleIndex() const {
  return AsmParser::RuleCam;
}

void AsmParser::CamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCam(this);
}

void AsmParser::CamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCam(this);
}


antlrcpp::Any AsmParser::CamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitCam(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::CamContext* AsmParser::cam() {
  CamContext *_localctx = _tracker.createInstance<CamContext>(_ctx, getState());
  enterRule(_localctx, 100, AsmParser::RuleCam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    match(AsmParser::CAM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MqaContext ------------------------------------------------------------------

AsmParser::MqaContext::MqaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::MqaContext::MQA() {
  return getToken(AsmParser::MQA, 0);
}


size_t AsmParser::MqaContext::getRuleIndex() const {
  return AsmParser::RuleMqa;
}

void AsmParser::MqaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMqa(this);
}

void AsmParser::MqaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMqa(this);
}


antlrcpp::Any AsmParser::MqaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitMqa(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::MqaContext* AsmParser::mqa() {
  MqaContext *_localctx = _tracker.createInstance<MqaContext>(_ctx, getState());
  enterRule(_localctx, 102, AsmParser::RuleMqa);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(AsmParser::MQA);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MqlContext ------------------------------------------------------------------

AsmParser::MqlContext::MqlContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::MqlContext::MQL() {
  return getToken(AsmParser::MQL, 0);
}


size_t AsmParser::MqlContext::getRuleIndex() const {
  return AsmParser::RuleMql;
}

void AsmParser::MqlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMql(this);
}

void AsmParser::MqlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMql(this);
}


antlrcpp::Any AsmParser::MqlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitMql(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::MqlContext* AsmParser::mql() {
  MqlContext *_localctx = _tracker.createInstance<MqlContext>(_ctx, getState());
  enterRule(_localctx, 104, AsmParser::RuleMql);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    match(AsmParser::MQL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SwpContext ------------------------------------------------------------------

AsmParser::SwpContext::SwpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SwpContext::SWP() {
  return getToken(AsmParser::SWP, 0);
}


size_t AsmParser::SwpContext::getRuleIndex() const {
  return AsmParser::RuleSwp;
}

void AsmParser::SwpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwp(this);
}

void AsmParser::SwpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwp(this);
}


antlrcpp::Any AsmParser::SwpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSwp(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SwpContext* AsmParser::swp() {
  SwpContext *_localctx = _tracker.createInstance<SwpContext>(_ctx, getState());
  enterRule(_localctx, 106, AsmParser::RuleSwp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(325);
    match(AsmParser::SWP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Iot_insContext ------------------------------------------------------------------

AsmParser::Iot_insContext::Iot_insContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::IotContext* AsmParser::Iot_insContext::iot() {
  return getRuleContext<AsmParser::IotContext>(0);
}

AsmParser::IonContext* AsmParser::Iot_insContext::ion() {
  return getRuleContext<AsmParser::IonContext>(0);
}

AsmParser::SkonContext* AsmParser::Iot_insContext::skon() {
  return getRuleContext<AsmParser::SkonContext>(0);
}

AsmParser::IofContext* AsmParser::Iot_insContext::iof() {
  return getRuleContext<AsmParser::IofContext>(0);
}

AsmParser::SrqContext* AsmParser::Iot_insContext::srq() {
  return getRuleContext<AsmParser::SrqContext>(0);
}

AsmParser::GtfContext* AsmParser::Iot_insContext::gtf() {
  return getRuleContext<AsmParser::GtfContext>(0);
}

AsmParser::RtfContext* AsmParser::Iot_insContext::rtf() {
  return getRuleContext<AsmParser::RtfContext>(0);
}

AsmParser::SgtContext *AsmParser::Iot_insContext::sgt() {
  return getRuleContext<AsmParser::SgtContext>(0);
}

AsmParser::CafContext* AsmParser::Iot_insContext::caf() {
  return getRuleContext<AsmParser::CafContext>(0);
}


size_t AsmParser::Iot_insContext::getRuleIndex() const {
  return AsmParser::RuleIot_ins;
}

void AsmParser::Iot_insContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIot_ins(this);
}

void AsmParser::Iot_insContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIot_ins(this);
}


antlrcpp::Any AsmParser::Iot_insContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitIot_ins(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Iot_insContext* AsmParser::iot_ins() {
  Iot_insContext *_localctx = _tracker.createInstance<Iot_insContext>(_ctx, getState());
  enterRule(_localctx, 108, AsmParser::RuleIot_ins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(336);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AsmParser::IOT: {
        enterOuterAlt(_localctx, 1);
        setState(327);
        iot();
        break;
      }

      case AsmParser::ION: {
        enterOuterAlt(_localctx, 2);
        setState(328);
        ion();
        break;
      }

      case AsmParser::SKON: {
        enterOuterAlt(_localctx, 3);
        setState(329);
        skon();
        break;
      }

      case AsmParser::IOF: {
        enterOuterAlt(_localctx, 4);
        setState(330);
        iof();
        break;
      }

      case AsmParser::SRQ: {
        enterOuterAlt(_localctx, 5);
        setState(331);
        srq();
        break;
      }

      case AsmParser::GTF: {
        enterOuterAlt(_localctx, 6);
        setState(332);
        gtf();
        break;
      }

      case AsmParser::RTF: {
        enterOuterAlt(_localctx, 7);
        setState(333);
        rtf();
        break;
      }

      case AsmParser::SGT: {
        enterOuterAlt(_localctx, 8);
        setState(334);
        sgt();
        break;
      }

      case AsmParser::CAF: {
        enterOuterAlt(_localctx, 9);
        setState(335);
        caf();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IotContext ------------------------------------------------------------------

AsmParser::IotContext::IotContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::IotContext::IOT() {
  return getToken(AsmParser::IOT, 0);
}


size_t AsmParser::IotContext::getRuleIndex() const {
  return AsmParser::RuleIot;
}

void AsmParser::IotContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIot(this);
}

void AsmParser::IotContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIot(this);
}


antlrcpp::Any AsmParser::IotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitIot(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::IotContext* AsmParser::iot() {
  IotContext *_localctx = _tracker.createInstance<IotContext>(_ctx, getState());
  enterRule(_localctx, 110, AsmParser::RuleIot);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    match(AsmParser::IOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IonContext ------------------------------------------------------------------

AsmParser::IonContext::IonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::IonContext::ION() {
  return getToken(AsmParser::ION, 0);
}


size_t AsmParser::IonContext::getRuleIndex() const {
  return AsmParser::RuleIon;
}

void AsmParser::IonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIon(this);
}

void AsmParser::IonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIon(this);
}


antlrcpp::Any AsmParser::IonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitIon(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::IonContext* AsmParser::ion() {
  IonContext *_localctx = _tracker.createInstance<IonContext>(_ctx, getState());
  enterRule(_localctx, 112, AsmParser::RuleIon);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    match(AsmParser::ION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SkonContext ------------------------------------------------------------------

AsmParser::SkonContext::SkonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SkonContext::SKON() {
  return getToken(AsmParser::SKON, 0);
}


size_t AsmParser::SkonContext::getRuleIndex() const {
  return AsmParser::RuleSkon;
}

void AsmParser::SkonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSkon(this);
}

void AsmParser::SkonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSkon(this);
}


antlrcpp::Any AsmParser::SkonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSkon(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SkonContext* AsmParser::skon() {
  SkonContext *_localctx = _tracker.createInstance<SkonContext>(_ctx, getState());
  enterRule(_localctx, 114, AsmParser::RuleSkon);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(AsmParser::SKON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IofContext ------------------------------------------------------------------

AsmParser::IofContext::IofContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::IofContext::IOF() {
  return getToken(AsmParser::IOF, 0);
}


size_t AsmParser::IofContext::getRuleIndex() const {
  return AsmParser::RuleIof;
}

void AsmParser::IofContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIof(this);
}

void AsmParser::IofContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIof(this);
}


antlrcpp::Any AsmParser::IofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitIof(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::IofContext* AsmParser::iof() {
  IofContext *_localctx = _tracker.createInstance<IofContext>(_ctx, getState());
  enterRule(_localctx, 116, AsmParser::RuleIof);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(AsmParser::IOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SrqContext ------------------------------------------------------------------

AsmParser::SrqContext::SrqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::SrqContext::SRQ() {
  return getToken(AsmParser::SRQ, 0);
}


size_t AsmParser::SrqContext::getRuleIndex() const {
  return AsmParser::RuleSrq;
}

void AsmParser::SrqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSrq(this);
}

void AsmParser::SrqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSrq(this);
}


antlrcpp::Any AsmParser::SrqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitSrq(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SrqContext* AsmParser::srq() {
  SrqContext *_localctx = _tracker.createInstance<SrqContext>(_ctx, getState());
  enterRule(_localctx, 118, AsmParser::RuleSrq);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    match(AsmParser::SRQ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GtfContext ------------------------------------------------------------------

AsmParser::GtfContext::GtfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::GtfContext::GTF() {
  return getToken(AsmParser::GTF, 0);
}


size_t AsmParser::GtfContext::getRuleIndex() const {
  return AsmParser::RuleGtf;
}

void AsmParser::GtfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGtf(this);
}

void AsmParser::GtfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGtf(this);
}


antlrcpp::Any AsmParser::GtfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitGtf(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::GtfContext* AsmParser::gtf() {
  GtfContext *_localctx = _tracker.createInstance<GtfContext>(_ctx, getState());
  enterRule(_localctx, 120, AsmParser::RuleGtf);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    match(AsmParser::GTF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RtfContext ------------------------------------------------------------------

AsmParser::RtfContext::RtfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::RtfContext::RTF() {
  return getToken(AsmParser::RTF, 0);
}


size_t AsmParser::RtfContext::getRuleIndex() const {
  return AsmParser::RuleRtf;
}

void AsmParser::RtfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRtf(this);
}

void AsmParser::RtfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRtf(this);
}


antlrcpp::Any AsmParser::RtfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitRtf(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::RtfContext* AsmParser::rtf() {
  RtfContext *_localctx = _tracker.createInstance<RtfContext>(_ctx, getState());
  enterRule(_localctx, 122, AsmParser::RuleRtf);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    match(AsmParser::RTF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SgtContext ------------------------------------------------------------------

AsmParser::SgtContext::SgtContext(ParserRuleContext *parent, size_t invokingState)
        : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode *AsmParser::SgtContext::SGT() {
  return getToken(AsmParser::SGT, 0);
}


size_t AsmParser::SgtContext::getRuleIndex() const {
  return AsmParser::RuleSgt;
}

void AsmParser::SgtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSgt(this);
}

void AsmParser::SgtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSgt(this);
}


antlrcpp::Any AsmParser::SgtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor *>(visitor))
    return parserVisitor->visitSgt(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::SgtContext *AsmParser::sgt() {
  SgtContext *_localctx = _tracker.createInstance<SgtContext>(_ctx, getState());
  enterRule(_localctx, 124, AsmParser::RuleSgt);

  auto onExit = finally([=] {
      exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    match(AsmParser::SGT);

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CafContext ------------------------------------------------------------------

AsmParser::CafContext::CafContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::CafContext::CAF() {
  return getToken(AsmParser::CAF, 0);
}


size_t AsmParser::CafContext::getRuleIndex() const {
  return AsmParser::RuleCaf;
}

void AsmParser::CafContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaf(this);
}

void AsmParser::CafContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaf(this);
}


antlrcpp::Any AsmParser::CafContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitCaf(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::CafContext* AsmParser::caf() {
  CafContext *_localctx = _tracker.createInstance<CafContext>(_ctx, getState());
  enterRule(_localctx, 126, AsmParser::RuleCaf);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(354);
    match(AsmParser::CAF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Def_constContext ------------------------------------------------------------------

AsmParser::Def_constContext::Def_constContext(ParserRuleContext *parent, size_t invokingState)
        : ParserRuleContext(parent, invokingState) {
}

AsmParser::DwContext *AsmParser::Def_constContext::dw() {
  return getRuleContext<AsmParser::DwContext>(0);
}


size_t AsmParser::Def_constContext::getRuleIndex() const {
  return AsmParser::RuleDef_const;
}

void AsmParser::Def_constContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDef_const(this);
}

void AsmParser::Def_constContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDef_const(this);
}


antlrcpp::Any AsmParser::Def_constContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor *>(visitor))
    return parserVisitor->visitDef_const(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::Def_constContext *AsmParser::def_const() {
  Def_constContext *_localctx = _tracker.createInstance<Def_constContext>(_ctx, getState());
  enterRule(_localctx, 128, AsmParser::RuleDef_const);

  auto onExit = finally([=] {
      exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    dw();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DwContext ------------------------------------------------------------------

AsmParser::DwContext::DwContext(ParserRuleContext *parent, size_t invokingState)
        : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode *AsmParser::DwContext::DW() {
  return getToken(AsmParser::DW, 0);
}

AsmParser::AddressContext *AsmParser::DwContext::address() {
  return getRuleContext<AsmParser::AddressContext>(0);
}


size_t AsmParser::DwContext::getRuleIndex() const {
  return AsmParser::RuleDw;
}

void AsmParser::DwContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDw(this);
}

void AsmParser::DwContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDw(this);
}


antlrcpp::Any AsmParser::DwContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor *>(visitor))
    return parserVisitor->visitDw(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::DwContext *AsmParser::dw() {
  DwContext *_localctx = _tracker.createInstance<DwContext>(_ctx, getState());
  enterRule(_localctx, 130, AsmParser::RuleDw);

  auto onExit = finally([=] {
      exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(358);
    match(AsmParser::DW);
    setState(359);
    address();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EolContext ------------------------------------------------------------------

AsmParser::EolContext::EolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AsmParser::EolContext::getRuleIndex() const {
  return AsmParser::RuleEol;
}

void AsmParser::EolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEol(this);
}

void AsmParser::EolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AsmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEol(this);
}


antlrcpp::Any AsmParser::EolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AsmVisitor*>(visitor))
    return parserVisitor->visitEol(this);
  else
    return visitor->visitChildren(this);
}

AsmParser::EolContext* AsmParser::eol() {
  EolContext *_localctx = _tracker.createInstance<EolContext>(_ctx, getState());
  enterRule(_localctx, 132, AsmParser::RuleEol);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(365);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AsmParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(361);
        match(AsmParser::T__3);
        break;
      }

      case AsmParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(362);
        match(AsmParser::T__4);
        break;
      }

      case AsmParser::T__5: {
        enterOuterAlt(_localctx, 3);
        setState(363);
        match(AsmParser::T__5);
        setState(364);
        match(AsmParser::T__4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> AsmParser::_decisionToDFA;
atn::PredictionContextCache AsmParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AsmParser::_atn;
std::vector<uint16_t> AsmParser::_serializedATN;

std::vector<std::string> AsmParser::_ruleNames = {
        "code", "statements", "statement", "pragma", "instruction", "symbol",
        "cpu_ins", "ctl_ins", "start", "mem_ins", "mem_op", "mem_and", "mem_tad",
        "mem_isz", "mem_dca", "mem_jms", "mem_jmp", "zero", "ind", "address",
        "opr_ins", "opr_op1", "opr_op1_ins", "nop", "iac", "ral", "rtl", "rar",
        "rtr", "bsw", "cml", "cma", "cia", "cll", "stl", "cla", "sta", "opr_op2",
        "opr_op2_ins", "hlt", "osr", "skp", "snl", "szl", "sza", "sna", "sma",
        "spa", "opr_op3", "opr_op3_ins", "cam", "mqa", "mql", "swp", "iot_ins",
        "iot", "ion", "skon", "iof", "srq", "gtf", "rtf", "sgt", "caf", "def_const",
        "dw", "eol"
};

std::vector<std::string> AsmParser::_literalNames = {
  "", "'.'", "'!'", "'@'", "';'", "'\n'", "'\r'"
};

std::vector<std::string> AsmParser::_symbolicNames = {
        "", "", "", "", "", "", "", "DW", "AND", "TAD", "ISZ", "DCA", "JMS", "JMP",
        "NOP", "IAC", "RAL", "RTL", "RAR", "RTR", "BSW", "CML", "CMA", "CIA",
        "CLL", "STL", "CLA", "STA", "HLT", "OSR", "SKP", "SNL", "SZL", "SZA",
        "SNA", "SMA", "SPA", "CAM", "MQA", "MQL", "SWP", "IOT", "ION", "SKON",
        "IOF", "SRQ", "GTF", "RTF", "SGT", "CAF", "Octal", "Decimal", "ID", "WS"
};

dfa::Vocabulary AsmParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AsmParser::_tokenNames;

AsmParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
          0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964,
          0x3, 0x37, 0x172, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4,
          0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7,
          0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb,
          0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe,
          0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4,
          0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15,
          0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9,
          0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b,
          0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4,
          0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22,
          0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9,
          0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28,
          0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4,
          0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f,
          0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9,
          0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35,
          0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4,
          0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c,
          0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9,
          0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42,
          0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x3, 0x2, 0x3, 0x2, 0x3,
          0x2, 0x3, 0x3, 0x6, 0x3, 0x8d, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x8e, 0x3,
          0x4, 0x3, 0x4, 0x5, 0x4, 0x93, 0xa, 0x4, 0x3, 0x5, 0x5, 0x5, 0x96, 0xa,
          0x5, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0x9a, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5,
          0x9b, 0x3, 0x6, 0x5, 0x6, 0x9f, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6,
          0xa3, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0xa4, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8,
          0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xad, 0xa, 0x8, 0x3, 0x9, 0x5,
          0x9, 0xb0, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa,
          0x5, 0xa, 0xb7, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xbb, 0xa, 0xb,
          0x3, 0xb, 0x5, 0xb, 0xbe, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xc2,
          0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc,
          0x5, 0xc, 0xca, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3,
          0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12,
          0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3,
          0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xe1, 0xa, 0x16, 0x3,
          0x17, 0x6, 0x17, 0xe4, 0xa, 0x17, 0xd, 0x17, 0xe, 0x17, 0xe5, 0x3, 0x18,
          0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3,
          0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18,
          0x5, 0x18, 0xf6, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a,
          0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3,
          0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21,
          0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3,
          0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x6, 0x27,
          0x115, 0xa, 0x27, 0xd, 0x27, 0xe, 0x27, 0x116, 0x3, 0x28, 0x3, 0x28,
          0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3,
          0x28, 0x3, 0x28, 0x5, 0x28, 0x123, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29,
          0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3,
          0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30,
          0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x6, 0x32, 0x138, 0xa, 0x32,
          0xd, 0x32, 0xe, 0x32, 0x139, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33,
          0x5, 0x33, 0x140, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35,
          0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3,
          0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38,
          0x5, 0x38, 0x153, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x3a, 0x3, 0x3a,
          0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3,
          0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41,
          0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3,
          0x44, 0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x170, 0xa, 0x44,
          0x3, 0x44, 0x2, 0x2, 0x45, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10,
          0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28,
          0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40,
          0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58,
          0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70,
          0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x2,
          0x3, 0x3, 0x2, 0x34, 0x35, 0x2, 0x169, 0x2, 0x88, 0x3, 0x2, 0x2, 0x2,
          0x4, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x6, 0x92, 0x3, 0x2, 0x2, 0x2, 0x8, 0x95,
          0x3, 0x2, 0x2, 0x2, 0xa, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xc, 0xa6, 0x3, 0x2,
          0x2, 0x2, 0xe, 0xac, 0x3, 0x2, 0x2, 0x2, 0x10, 0xaf, 0x3, 0x2, 0x2,
          0x2, 0x12, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x14, 0xb8, 0x3, 0x2, 0x2, 0x2,
          0x16, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x18, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x1a,
          0xcd, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xd1,
          0x3, 0x2, 0x2, 0x2, 0x20, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x22, 0xd5, 0x3,
          0x2, 0x2, 0x2, 0x24, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x26, 0xd9, 0x3, 0x2,
          0x2, 0x2, 0x28, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xe0, 0x3, 0x2, 0x2,
          0x2, 0x2c, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xf5, 0x3, 0x2, 0x2, 0x2,
          0x30, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x32, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x34,
          0xfb, 0x3, 0x2, 0x2, 0x2, 0x36, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x38, 0xff,
          0x3, 0x2, 0x2, 0x2, 0x3a, 0x101, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x103, 0x3,
          0x2, 0x2, 0x2, 0x3e, 0x105, 0x3, 0x2, 0x2, 0x2, 0x40, 0x107, 0x3, 0x2,
          0x2, 0x2, 0x42, 0x109, 0x3, 0x2, 0x2, 0x2, 0x44, 0x10b, 0x3, 0x2, 0x2,
          0x2, 0x46, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x48, 0x10f, 0x3, 0x2, 0x2, 0x2,
          0x4a, 0x111, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x114, 0x3, 0x2, 0x2, 0x2, 0x4e,
          0x122, 0x3, 0x2, 0x2, 0x2, 0x50, 0x124, 0x3, 0x2, 0x2, 0x2, 0x52, 0x126,
          0x3, 0x2, 0x2, 0x2, 0x54, 0x128, 0x3, 0x2, 0x2, 0x2, 0x56, 0x12a, 0x3,
          0x2, 0x2, 0x2, 0x58, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x12e, 0x3, 0x2,
          0x2, 0x2, 0x5c, 0x130, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x132, 0x3, 0x2, 0x2,
          0x2, 0x60, 0x134, 0x3, 0x2, 0x2, 0x2, 0x62, 0x137, 0x3, 0x2, 0x2, 0x2,
          0x64, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x66, 0x141, 0x3, 0x2, 0x2, 0x2, 0x68,
          0x143, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x145, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x147,
          0x3, 0x2, 0x2, 0x2, 0x6e, 0x152, 0x3, 0x2, 0x2, 0x2, 0x70, 0x154, 0x3,
          0x2, 0x2, 0x2, 0x72, 0x156, 0x3, 0x2, 0x2, 0x2, 0x74, 0x158, 0x3, 0x2,
          0x2, 0x2, 0x76, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x78, 0x15c, 0x3, 0x2, 0x2,
          0x2, 0x7a, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x160, 0x3, 0x2, 0x2, 0x2,
          0x7e, 0x162, 0x3, 0x2, 0x2, 0x2, 0x80, 0x164, 0x3, 0x2, 0x2, 0x2, 0x82,
          0x166, 0x3, 0x2, 0x2, 0x2, 0x84, 0x168, 0x3, 0x2, 0x2, 0x2, 0x86, 0x16f,
          0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x5, 0x4, 0x3, 0x2, 0x89, 0x8a, 0x7,
          0x2, 0x2, 0x3, 0x8a, 0x3, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0x6,
          0x4, 0x2, 0x8c, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2,
          0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2,
          0x8f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x90, 0x93, 0x5, 0xa, 0x6, 0x2, 0x91,
          0x93, 0x5, 0x8, 0x5, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x91,
          0x3, 0x2, 0x2, 0x2, 0x93, 0x7, 0x3, 0x2, 0x2, 0x2, 0x94, 0x96, 0x5,
          0xc, 0x7, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2,
          0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x99, 0x5, 0x10, 0x9,
          0x2, 0x98, 0x9a, 0x5, 0x86, 0x44, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 0x2,
          0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9b,
          0x9c, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9f,
          0x5, 0xc, 0x7, 0x2, 0x9e, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3,
          0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa2, 0x5, 0xe,
          0x8, 0x2, 0xa1, 0xa3, 0x5, 0x86, 0x44, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2,
          0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2,
          0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xb, 0x3, 0x2, 0x2, 0x2, 0xa6,
          0xa7, 0x7, 0x36, 0x2, 0x2, 0xa7, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xad,
          0x5, 0x14, 0xb, 0x2, 0xa9, 0xad, 0x5, 0x2a, 0x16, 0x2, 0xaa, 0xad, 0x5,
          0x6e, 0x38, 0x2, 0xab, 0xad, 0x5, 0x82, 0x42, 0x2, 0xac, 0xa8, 0x3,
          0x2, 0x2, 0x2, 0xac, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2,
          0x2, 0x2, 0xac, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xf, 0x3, 0x2, 0x2,
          0x2, 0xae, 0xb0, 0x5, 0xc, 0x7, 0x2, 0xaf, 0xae, 0x3, 0x2, 0x2, 0x2,
          0xaf, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1,
          0xb2, 0x5, 0x12, 0xa, 0x2, 0xb2, 0x11, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb6,
          0x7, 0x3, 0x2, 0x2, 0xb4, 0xb7, 0x5, 0x28, 0x15, 0x2, 0xb5, 0xb7, 0x5,
          0xc, 0x7, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb5, 0x3, 0x2,
          0x2, 0x2, 0xb7, 0x13, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xba, 0x5, 0x16, 0xc,
          0x2, 0xb9, 0xbb, 0x5, 0x24, 0x13, 0x2, 0xba, 0xb9, 0x3, 0x2, 0x2, 0x2,
          0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbc,
          0xbe, 0x5, 0x26, 0x14, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe,
          0x3, 0x2, 0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc2, 0x5,
          0x28, 0x15, 0x2, 0xc0, 0xc2, 0x5, 0xc, 0x7, 0x2, 0xc1, 0xbf, 0x3, 0x2,
          0x2, 0x2, 0xc1, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x15, 0x3, 0x2, 0x2,
          0x2, 0xc3, 0xca, 0x5, 0x18, 0xd, 0x2, 0xc4, 0xca, 0x5, 0x1a, 0xe, 0x2,
          0xc5, 0xca, 0x5, 0x1c, 0xf, 0x2, 0xc6, 0xca, 0x5, 0x1e, 0x10, 0x2, 0xc7,
          0xca, 0x5, 0x20, 0x11, 0x2, 0xc8, 0xca, 0x5, 0x22, 0x12, 0x2, 0xc9,
          0xc3, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc5,
          0x3, 0x2, 0x2, 0x2, 0xc9, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xc7, 0x3,
          0x2, 0x2, 0x2, 0xc9, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xca, 0x17, 0x3, 0x2,
          0x2, 0x2, 0xcb, 0xcc, 0x7, 0xa, 0x2, 0x2, 0xcc, 0x19, 0x3, 0x2, 0x2,
          0x2, 0xcd, 0xce, 0x7, 0xb, 0x2, 0x2, 0xce, 0x1b, 0x3, 0x2, 0x2, 0x2,
          0xcf, 0xd0, 0x7, 0xc, 0x2, 0x2, 0xd0, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xd1,
          0xd2, 0x7, 0xd, 0x2, 0x2, 0xd2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4,
          0x7, 0xe, 0x2, 0x2, 0xd4, 0x21, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x7,
          0xf, 0x2, 0x2, 0xd6, 0x23, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x4,
          0x2, 0x2, 0xd8, 0x25, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x5, 0x2,
          0x2, 0xda, 0x27, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x9, 0x2, 0x2, 0x2,
          0xdc, 0x29, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xe1, 0x5, 0x2c, 0x17, 0x2, 0xde,
          0xe1, 0x5, 0x4c, 0x27, 0x2, 0xdf, 0xe1, 0x5, 0x62, 0x32, 0x2, 0xe0,
          0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xdf,
          0x3, 0x2, 0x2, 0x2, 0xe1, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe4, 0x5,
          0x2e, 0x18, 0x2, 0xe3, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2,
          0x2, 0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x3, 0x2, 0x2,
          0x2, 0xe6, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xf6, 0x5, 0x30, 0x19, 0x2,
          0xe8, 0xf6, 0x5, 0x32, 0x1a, 0x2, 0xe9, 0xf6, 0x5, 0x34, 0x1b, 0x2,
          0xea, 0xf6, 0x5, 0x36, 0x1c, 0x2, 0xeb, 0xf6, 0x5, 0x38, 0x1d, 0x2,
          0xec, 0xf6, 0x5, 0x3a, 0x1e, 0x2, 0xed, 0xf6, 0x5, 0x3c, 0x1f, 0x2,
          0xee, 0xf6, 0x5, 0x3e, 0x20, 0x2, 0xef, 0xf6, 0x5, 0x40, 0x21, 0x2,
          0xf0, 0xf6, 0x5, 0x42, 0x22, 0x2, 0xf1, 0xf6, 0x5, 0x44, 0x23, 0x2,
          0xf2, 0xf6, 0x5, 0x46, 0x24, 0x2, 0xf3, 0xf6, 0x5, 0x48, 0x25, 0x2,
          0xf4, 0xf6, 0x5, 0x4a, 0x26, 0x2, 0xf5, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xf5,
          0xe8, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xea,
          0x3, 0x2, 0x2, 0x2, 0xf5, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xec, 0x3,
          0x2, 0x2, 0x2, 0xf5, 0xed, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xee, 0x3, 0x2,
          0x2, 0x2, 0xf5, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf0, 0x3, 0x2, 0x2,
          0x2, 0xf5, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf2, 0x3, 0x2, 0x2, 0x2,
          0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6,
          0x2f, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0x10, 0x2, 0x2, 0xf8, 0x31,
          0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x11, 0x2, 0x2, 0xfa, 0x33, 0x3,
          0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x12, 0x2, 0x2, 0xfc, 0x35, 0x3, 0x2,
          0x2, 0x2, 0xfd, 0xfe, 0x7, 0x13, 0x2, 0x2, 0xfe, 0x37, 0x3, 0x2, 0x2,
          0x2, 0xff, 0x100, 0x7, 0x14, 0x2, 0x2, 0x100, 0x39, 0x3, 0x2, 0x2, 0x2,
          0x101, 0x102, 0x7, 0x15, 0x2, 0x2, 0x102, 0x3b, 0x3, 0x2, 0x2, 0x2,
          0x103, 0x104, 0x7, 0x16, 0x2, 0x2, 0x104, 0x3d, 0x3, 0x2, 0x2, 0x2,
          0x105, 0x106, 0x7, 0x17, 0x2, 0x2, 0x106, 0x3f, 0x3, 0x2, 0x2, 0x2,
          0x107, 0x108, 0x7, 0x18, 0x2, 0x2, 0x108, 0x41, 0x3, 0x2, 0x2, 0x2,
          0x109, 0x10a, 0x7, 0x19, 0x2, 0x2, 0x10a, 0x43, 0x3, 0x2, 0x2, 0x2,
          0x10b, 0x10c, 0x7, 0x1a, 0x2, 0x2, 0x10c, 0x45, 0x3, 0x2, 0x2, 0x2,
          0x10d, 0x10e, 0x7, 0x1b, 0x2, 0x2, 0x10e, 0x47, 0x3, 0x2, 0x2, 0x2,
          0x10f, 0x110, 0x7, 0x1c, 0x2, 0x2, 0x110, 0x49, 0x3, 0x2, 0x2, 0x2,
          0x111, 0x112, 0x7, 0x1d, 0x2, 0x2, 0x112, 0x4b, 0x3, 0x2, 0x2, 0x2,
          0x113, 0x115, 0x5, 0x4e, 0x28, 0x2, 0x114, 0x113, 0x3, 0x2, 0x2, 0x2,
          0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2,
          0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x118,
          0x123, 0x5, 0x50, 0x29, 0x2, 0x119, 0x123, 0x5, 0x52, 0x2a, 0x2, 0x11a,
          0x123, 0x5, 0x54, 0x2b, 0x2, 0x11b, 0x123, 0x5, 0x56, 0x2c, 0x2, 0x11c,
          0x123, 0x5, 0x58, 0x2d, 0x2, 0x11d, 0x123, 0x5, 0x5a, 0x2e, 0x2, 0x11e,
          0x123, 0x5, 0x5c, 0x2f, 0x2, 0x11f, 0x123, 0x5, 0x5e, 0x30, 0x2, 0x120,
          0x123, 0x5, 0x60, 0x31, 0x2, 0x121, 0x123, 0x5, 0x48, 0x25, 0x2, 0x122,
          0x118, 0x3, 0x2, 0x2, 0x2, 0x122, 0x119, 0x3, 0x2, 0x2, 0x2, 0x122,
          0x11a, 0x3, 0x2, 0x2, 0x2, 0x122, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x122,
          0x11c, 0x3, 0x2, 0x2, 0x2, 0x122, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x122,
          0x11e, 0x3, 0x2, 0x2, 0x2, 0x122, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x122,
          0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 0x121, 0x3, 0x2, 0x2, 0x2, 0x123,
          0x4f, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x7, 0x1e, 0x2, 0x2, 0x125,
          0x51, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x7, 0x1f, 0x2, 0x2, 0x127,
          0x53, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x7, 0x20, 0x2, 0x2, 0x129,
          0x55, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x21, 0x2, 0x2, 0x12b,
          0x57, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x7, 0x22, 0x2, 0x2, 0x12d,
          0x59, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x7, 0x23, 0x2, 0x2, 0x12f,
          0x5b, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x7, 0x24, 0x2, 0x2, 0x131,
          0x5d, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x7, 0x25, 0x2, 0x2, 0x133,
          0x5f, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x7, 0x26, 0x2, 0x2, 0x135,
          0x61, 0x3, 0x2, 0x2, 0x2, 0x136, 0x138, 0x5, 0x64, 0x33, 0x2, 0x137,
          0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139,
          0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a,
          0x63, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x140, 0x5, 0x66, 0x34, 0x2, 0x13c,
          0x140, 0x5, 0x68, 0x35, 0x2, 0x13d, 0x140, 0x5, 0x6a, 0x36, 0x2, 0x13e,
          0x140, 0x5, 0x6c, 0x37, 0x2, 0x13f, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13f,
          0x13c, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f,
          0x13e, 0x3, 0x2, 0x2, 0x2, 0x140, 0x65, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142,
          0x7, 0x27, 0x2, 0x2, 0x142, 0x67, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144,
          0x7, 0x28, 0x2, 0x2, 0x144, 0x69, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146,
          0x7, 0x29, 0x2, 0x2, 0x146, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148,
          0x7, 0x2a, 0x2, 0x2, 0x148, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x149, 0x153,
          0x5, 0x70, 0x39, 0x2, 0x14a, 0x153, 0x5, 0x72, 0x3a, 0x2, 0x14b, 0x153,
          0x5, 0x74, 0x3b, 0x2, 0x14c, 0x153, 0x5, 0x76, 0x3c, 0x2, 0x14d, 0x153,
          0x5, 0x78, 0x3d, 0x2, 0x14e, 0x153, 0x5, 0x7a, 0x3e, 0x2, 0x14f, 0x153,
          0x5, 0x7c, 0x3f, 0x2, 0x150, 0x153, 0x5, 0x7e, 0x40, 0x2, 0x151, 0x153,
          0x5, 0x80, 0x41, 0x2, 0x152, 0x149, 0x3, 0x2, 0x2, 0x2, 0x152, 0x14a,
          0x3, 0x2, 0x2, 0x2, 0x152, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x152, 0x14c,
          0x3, 0x2, 0x2, 0x2, 0x152, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x152, 0x14e,
          0x3, 0x2, 0x2, 0x2, 0x152, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x152, 0x150,
          0x3, 0x2, 0x2, 0x2, 0x152, 0x151, 0x3, 0x2, 0x2, 0x2, 0x153, 0x6f, 0x3,
          0x2, 0x2, 0x2, 0x154, 0x155, 0x7, 0x2b, 0x2, 0x2, 0x155, 0x71, 0x3,
          0x2, 0x2, 0x2, 0x156, 0x157, 0x7, 0x2c, 0x2, 0x2, 0x157, 0x73, 0x3,
          0x2, 0x2, 0x2, 0x158, 0x159, 0x7, 0x2d, 0x2, 0x2, 0x159, 0x75, 0x3,
          0x2, 0x2, 0x2, 0x15a, 0x15b, 0x7, 0x2e, 0x2, 0x2, 0x15b, 0x77, 0x3,
          0x2, 0x2, 0x2, 0x15c, 0x15d, 0x7, 0x2f, 0x2, 0x2, 0x15d, 0x79, 0x3,
          0x2, 0x2, 0x2, 0x15e, 0x15f, 0x7, 0x30, 0x2, 0x2, 0x15f, 0x7b, 0x3,
          0x2, 0x2, 0x2, 0x160, 0x161, 0x7, 0x31, 0x2, 0x2, 0x161, 0x7d, 0x3,
          0x2, 0x2, 0x2, 0x162, 0x163, 0x7, 0x32, 0x2, 0x2, 0x163, 0x7f, 0x3,
          0x2, 0x2, 0x2, 0x164, 0x165, 0x7, 0x33, 0x2, 0x2, 0x165, 0x81, 0x3,
          0x2, 0x2, 0x2, 0x166, 0x167, 0x5, 0x84, 0x43, 0x2, 0x167, 0x83, 0x3,
          0x2, 0x2, 0x2, 0x168, 0x169, 0x7, 0x9, 0x2, 0x2, 0x169, 0x16a, 0x5,
          0x28, 0x15, 0x2, 0x16a, 0x85, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x170, 0x7,
          0x6, 0x2, 0x2, 0x16c, 0x170, 0x7, 0x7, 0x2, 0x2, 0x16d, 0x16e, 0x7,
          0x8, 0x2, 0x2, 0x16e, 0x170, 0x7, 0x7, 0x2, 0x2, 0x16f, 0x16b, 0x3,
          0x2, 0x2, 0x2, 0x16f, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3,
          0x2, 0x2, 0x2, 0x170, 0x87, 0x3, 0x2, 0x2, 0x2, 0x18, 0x8e, 0x92, 0x95,
          0x9b, 0x9e, 0xa4, 0xac, 0xaf, 0xb6, 0xba, 0xbd, 0xc1, 0xc9, 0xe0, 0xe5,
          0xf5, 0x116, 0x122, 0x139, 0x13f, 0x152, 0x16f,
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AsmParser::Initializer AsmParser::_init;
