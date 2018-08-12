
// Generated from Asm.g4 by ANTLR 4.7


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

std::vector<AsmParser::StatementContext *> AsmParser::CodeContext::statement() {
  return getRuleContexts<AsmParser::StatementContext>();
}

AsmParser::StatementContext* AsmParser::CodeContext::statement(size_t i) {
  return getRuleContext<AsmParser::StatementContext>(i);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    statement();

    setState(38);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AsmParser::T__0)
      | (1ULL << AsmParser::ID)
      | (1ULL << AsmParser::A)
      | (1ULL << AsmParser::N)
      | (1ULL << AsmParser::D)
      | (1ULL << AsmParser::T)
      | (1ULL << AsmParser::I)
      | (1ULL << AsmParser::S)
      | (1ULL << AsmParser::C)
      | (1ULL << AsmParser::J)
      | (1ULL << AsmParser::M)
      | (1ULL << AsmParser::O)
      | (1ULL << AsmParser::R)
      | (1ULL << AsmParser::B)
      | (1ULL << AsmParser::H)
      | (1ULL << AsmParser::G))) != 0)) {
      setState(35);
      statement();
      setState(40);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
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

AsmParser::SymbolContext* AsmParser::StatementContext::symbol() {
  return getRuleContext<AsmParser::SymbolContext>(0);
}

std::vector<AsmParser::EolContext *> AsmParser::StatementContext::eol() {
  return getRuleContexts<AsmParser::EolContext>();
}

AsmParser::EolContext* AsmParser::StatementContext::eol(size_t i) {
  return getRuleContext<AsmParser::EolContext>(i);
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
  enterRule(_localctx, 2, AsmParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AsmParser::ID) {
      setState(41);
      symbol();
    }
    setState(44);
    instruction();

    setState(46); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(45);
      eol();
      setState(48); 
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
  enterRule(_localctx, 4, AsmParser::RuleSymbol);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    match(AsmParser::ID);
   
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

AsmParser::Mem_insContext* AsmParser::InstructionContext::mem_ins() {
  return getRuleContext<AsmParser::Mem_insContext>(0);
}

AsmParser::Opr_insContext* AsmParser::InstructionContext::opr_ins() {
  return getRuleContext<AsmParser::Opr_insContext>(0);
}

AsmParser::Iot_insContext* AsmParser::InstructionContext::iot_ins() {
  return getRuleContext<AsmParser::Iot_insContext>(0);
}

AsmParser::Ctl_insContext* AsmParser::InstructionContext::ctl_ins() {
  return getRuleContext<AsmParser::Ctl_insContext>(0);
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
  enterRule(_localctx, 6, AsmParser::RuleInstruction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(52);
      mem_ins();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(53);
      opr_ins();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(54);
      iot_ins();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(55);
      ctl_ins();
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

//----------------- Ctl_insContext ------------------------------------------------------------------

AsmParser::Ctl_insContext::Ctl_insContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AsmParser::StartContext* AsmParser::Ctl_insContext::start() {
  return getRuleContext<AsmParser::StartContext>(0);
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
  enterRule(_localctx, 8, AsmParser::RuleCtl_ins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
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
  enterRule(_localctx, 10, AsmParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(AsmParser::T__0);
    setState(61);
    address();
   
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
  enterRule(_localctx, 12, AsmParser::RuleMem_ins);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    mem_op();
    setState(65);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AsmParser::T__1) {
      setState(64);
      zero();
    }
    setState(68);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AsmParser::T__2) {
      setState(67);
      ind();
    }
    setState(70);
    address();
   
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

tree::TerminalNode* AsmParser::Mem_opContext::A() {
  return getToken(AsmParser::A, 0);
}

tree::TerminalNode* AsmParser::Mem_opContext::N() {
  return getToken(AsmParser::N, 0);
}

tree::TerminalNode* AsmParser::Mem_opContext::D() {
  return getToken(AsmParser::D, 0);
}

tree::TerminalNode* AsmParser::Mem_opContext::T() {
  return getToken(AsmParser::T, 0);
}

tree::TerminalNode* AsmParser::Mem_opContext::I() {
  return getToken(AsmParser::I, 0);
}

tree::TerminalNode* AsmParser::Mem_opContext::S() {
  return getToken(AsmParser::S, 0);
}

tree::TerminalNode* AsmParser::Mem_opContext::Z() {
  return getToken(AsmParser::Z, 0);
}

tree::TerminalNode* AsmParser::Mem_opContext::C() {
  return getToken(AsmParser::C, 0);
}

tree::TerminalNode* AsmParser::Mem_opContext::J() {
  return getToken(AsmParser::J, 0);
}

tree::TerminalNode* AsmParser::Mem_opContext::M() {
  return getToken(AsmParser::M, 0);
}

tree::TerminalNode* AsmParser::Mem_opContext::P() {
  return getToken(AsmParser::P, 0);
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
  enterRule(_localctx, 14, AsmParser::RuleMem_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(72);
      match(AsmParser::A);
      setState(73);
      match(AsmParser::N);
      setState(74);
      match(AsmParser::D);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(75);
      match(AsmParser::T);
      setState(76);
      match(AsmParser::A);
      setState(77);
      match(AsmParser::D);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(78);
      match(AsmParser::I);
      setState(79);
      match(AsmParser::S);
      setState(80);
      match(AsmParser::Z);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(81);
      match(AsmParser::D);
      setState(82);
      match(AsmParser::C);
      setState(83);
      match(AsmParser::A);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(84);
      match(AsmParser::J);
      setState(85);
      match(AsmParser::M);
      setState(86);
      match(AsmParser::S);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(87);
      match(AsmParser::J);
      setState(88);
      match(AsmParser::M);
      setState(89);
      match(AsmParser::P);
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
  enterRule(_localctx, 16, AsmParser::RuleZero);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
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
  enterRule(_localctx, 18, AsmParser::RuleInd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
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
  enterRule(_localctx, 20, AsmParser::RuleAddress);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
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

std::vector<AsmParser::Opr_op1Context *> AsmParser::Opr_insContext::opr_op1() {
  return getRuleContexts<AsmParser::Opr_op1Context>();
}

AsmParser::Opr_op1Context* AsmParser::Opr_insContext::opr_op1(size_t i) {
  return getRuleContext<AsmParser::Opr_op1Context>(i);
}

std::vector<AsmParser::Opr_op2Context *> AsmParser::Opr_insContext::opr_op2() {
  return getRuleContexts<AsmParser::Opr_op2Context>();
}

AsmParser::Opr_op2Context* AsmParser::Opr_insContext::opr_op2(size_t i) {
  return getRuleContext<AsmParser::Opr_op2Context>(i);
}

std::vector<AsmParser::Opr_op3Context *> AsmParser::Opr_insContext::opr_op3() {
  return getRuleContexts<AsmParser::Opr_op3Context>();
}

AsmParser::Opr_op3Context* AsmParser::Opr_insContext::opr_op3(size_t i) {
  return getRuleContext<AsmParser::Opr_op3Context>(i);
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
  enterRule(_localctx, 22, AsmParser::RuleOpr_ins);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(113);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(99); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(98);
        opr_op1();
        setState(101); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AsmParser::N)
        | (1ULL << AsmParser::I)
        | (1ULL << AsmParser::S)
        | (1ULL << AsmParser::C)
        | (1ULL << AsmParser::R)
        | (1ULL << AsmParser::B))) != 0));
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(104); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(103);
        opr_op2();
        setState(106); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AsmParser::S)
        | (1ULL << AsmParser::C)
        | (1ULL << AsmParser::O)
        | (1ULL << AsmParser::H))) != 0));
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(109); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(108);
        opr_op3();
        setState(111); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AsmParser::S)
        | (1ULL << AsmParser::C)
        | (1ULL << AsmParser::M))) != 0));
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

tree::TerminalNode* AsmParser::Opr_op1Context::N() {
  return getToken(AsmParser::N, 0);
}

tree::TerminalNode* AsmParser::Opr_op1Context::O() {
  return getToken(AsmParser::O, 0);
}

tree::TerminalNode* AsmParser::Opr_op1Context::P() {
  return getToken(AsmParser::P, 0);
}

tree::TerminalNode* AsmParser::Opr_op1Context::I() {
  return getToken(AsmParser::I, 0);
}

tree::TerminalNode* AsmParser::Opr_op1Context::A() {
  return getToken(AsmParser::A, 0);
}

tree::TerminalNode* AsmParser::Opr_op1Context::C() {
  return getToken(AsmParser::C, 0);
}

std::vector<tree::TerminalNode *> AsmParser::Opr_op1Context::R() {
  return getTokens(AsmParser::R);
}

tree::TerminalNode* AsmParser::Opr_op1Context::R(size_t i) {
  return getToken(AsmParser::R, i);
}

std::vector<tree::TerminalNode *> AsmParser::Opr_op1Context::L() {
  return getTokens(AsmParser::L);
}

tree::TerminalNode* AsmParser::Opr_op1Context::L(size_t i) {
  return getToken(AsmParser::L, i);
}

tree::TerminalNode* AsmParser::Opr_op1Context::T() {
  return getToken(AsmParser::T, 0);
}

tree::TerminalNode* AsmParser::Opr_op1Context::B() {
  return getToken(AsmParser::B, 0);
}

tree::TerminalNode* AsmParser::Opr_op1Context::S() {
  return getToken(AsmParser::S, 0);
}

tree::TerminalNode* AsmParser::Opr_op1Context::W() {
  return getToken(AsmParser::W, 0);
}

tree::TerminalNode* AsmParser::Opr_op1Context::M() {
  return getToken(AsmParser::M, 0);
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
  enterRule(_localctx, 24, AsmParser::RuleOpr_op1);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(157);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(115);
      match(AsmParser::N);
      setState(116);
      match(AsmParser::O);
      setState(117);
      match(AsmParser::P);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(118);
      match(AsmParser::I);
      setState(119);
      match(AsmParser::A);
      setState(120);
      match(AsmParser::C);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(121);
      match(AsmParser::R);
      setState(122);
      match(AsmParser::A);
      setState(123);
      match(AsmParser::L);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(124);
      match(AsmParser::R);
      setState(125);
      match(AsmParser::T);
      setState(126);
      match(AsmParser::L);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(127);
      match(AsmParser::R);
      setState(128);
      match(AsmParser::A);
      setState(129);
      match(AsmParser::R);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(130);
      match(AsmParser::R);
      setState(131);
      match(AsmParser::T);
      setState(132);
      match(AsmParser::R);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(133);
      match(AsmParser::B);
      setState(134);
      match(AsmParser::S);
      setState(135);
      match(AsmParser::W);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(136);
      match(AsmParser::C);
      setState(137);
      match(AsmParser::M);
      setState(138);
      match(AsmParser::L);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(139);
      match(AsmParser::C);
      setState(140);
      match(AsmParser::M);
      setState(141);
      match(AsmParser::A);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(142);
      match(AsmParser::C);
      setState(143);
      match(AsmParser::I);
      setState(144);
      match(AsmParser::A);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(145);
      match(AsmParser::C);
      setState(146);
      match(AsmParser::L);
      setState(147);
      match(AsmParser::L);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(148);
      match(AsmParser::S);
      setState(149);
      match(AsmParser::T);
      setState(150);
      match(AsmParser::L);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(151);
      match(AsmParser::C);
      setState(152);
      match(AsmParser::L);
      setState(153);
      match(AsmParser::A);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(154);
      match(AsmParser::S);
      setState(155);
      match(AsmParser::T);
      setState(156);
      match(AsmParser::A);
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

//----------------- Opr_op2Context ------------------------------------------------------------------

AsmParser::Opr_op2Context::Opr_op2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::Opr_op2Context::H() {
  return getToken(AsmParser::H, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::L() {
  return getToken(AsmParser::L, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::T() {
  return getToken(AsmParser::T, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::O() {
  return getToken(AsmParser::O, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::S() {
  return getToken(AsmParser::S, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::R() {
  return getToken(AsmParser::R, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::K() {
  return getToken(AsmParser::K, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::P() {
  return getToken(AsmParser::P, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::N() {
  return getToken(AsmParser::N, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::Z() {
  return getToken(AsmParser::Z, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::A() {
  return getToken(AsmParser::A, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::M() {
  return getToken(AsmParser::M, 0);
}

tree::TerminalNode* AsmParser::Opr_op2Context::C() {
  return getToken(AsmParser::C, 0);
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
  enterRule(_localctx, 26, AsmParser::RuleOpr_op2);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(159);
      match(AsmParser::H);
      setState(160);
      match(AsmParser::L);
      setState(161);
      match(AsmParser::T);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(162);
      match(AsmParser::O);
      setState(163);
      match(AsmParser::S);
      setState(164);
      match(AsmParser::R);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(165);
      match(AsmParser::S);
      setState(166);
      match(AsmParser::K);
      setState(167);
      match(AsmParser::P);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(168);
      match(AsmParser::S);
      setState(169);
      match(AsmParser::N);
      setState(170);
      match(AsmParser::L);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(171);
      match(AsmParser::S);
      setState(172);
      match(AsmParser::Z);
      setState(173);
      match(AsmParser::L);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(174);
      match(AsmParser::S);
      setState(175);
      match(AsmParser::Z);
      setState(176);
      match(AsmParser::A);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(177);
      match(AsmParser::S);
      setState(178);
      match(AsmParser::N);
      setState(179);
      match(AsmParser::A);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(180);
      match(AsmParser::S);
      setState(181);
      match(AsmParser::M);
      setState(182);
      match(AsmParser::A);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(183);
      match(AsmParser::S);
      setState(184);
      match(AsmParser::P);
      setState(185);
      match(AsmParser::A);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(186);
      match(AsmParser::C);
      setState(187);
      match(AsmParser::L);
      setState(188);
      match(AsmParser::A);
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

//----------------- Opr_op3Context ------------------------------------------------------------------

AsmParser::Opr_op3Context::Opr_op3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::Opr_op3Context::C() {
  return getToken(AsmParser::C, 0);
}

tree::TerminalNode* AsmParser::Opr_op3Context::M() {
  return getToken(AsmParser::M, 0);
}

tree::TerminalNode* AsmParser::Opr_op3Context::A() {
  return getToken(AsmParser::A, 0);
}

tree::TerminalNode* AsmParser::Opr_op3Context::Q() {
  return getToken(AsmParser::Q, 0);
}

tree::TerminalNode* AsmParser::Opr_op3Context::L() {
  return getToken(AsmParser::L, 0);
}

tree::TerminalNode* AsmParser::Opr_op3Context::S() {
  return getToken(AsmParser::S, 0);
}

tree::TerminalNode* AsmParser::Opr_op3Context::W() {
  return getToken(AsmParser::W, 0);
}

tree::TerminalNode* AsmParser::Opr_op3Context::P() {
  return getToken(AsmParser::P, 0);
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
  enterRule(_localctx, 28, AsmParser::RuleOpr_op3);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(203);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(191);
      match(AsmParser::C);
      setState(192);
      match(AsmParser::M);
      setState(193);
      match(AsmParser::A);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(194);
      match(AsmParser::M);
      setState(195);
      match(AsmParser::Q);
      setState(196);
      match(AsmParser::A);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(197);
      match(AsmParser::M);
      setState(198);
      match(AsmParser::Q);
      setState(199);
      match(AsmParser::L);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(200);
      match(AsmParser::S);
      setState(201);
      match(AsmParser::W);
      setState(202);
      match(AsmParser::P);
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

//----------------- Iot_insContext ------------------------------------------------------------------

AsmParser::Iot_insContext::Iot_insContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AsmParser::Iot_insContext::I() {
  return getToken(AsmParser::I, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::O() {
  return getToken(AsmParser::O, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::T() {
  return getToken(AsmParser::T, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::N() {
  return getToken(AsmParser::N, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::S() {
  return getToken(AsmParser::S, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::K() {
  return getToken(AsmParser::K, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::F() {
  return getToken(AsmParser::F, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::R() {
  return getToken(AsmParser::R, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::Q() {
  return getToken(AsmParser::Q, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::G() {
  return getToken(AsmParser::G, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::C() {
  return getToken(AsmParser::C, 0);
}

tree::TerminalNode* AsmParser::Iot_insContext::A() {
  return getToken(AsmParser::A, 0);
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
  enterRule(_localctx, 30, AsmParser::RuleIot_ins);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(233);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(205);
      match(AsmParser::I);
      setState(206);
      match(AsmParser::O);
      setState(207);
      match(AsmParser::T);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(208);
      match(AsmParser::I);
      setState(209);
      match(AsmParser::O);
      setState(210);
      match(AsmParser::N);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(211);
      match(AsmParser::S);
      setState(212);
      match(AsmParser::K);
      setState(213);
      match(AsmParser::O);
      setState(214);
      match(AsmParser::N);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(215);
      match(AsmParser::I);
      setState(216);
      match(AsmParser::O);
      setState(217);
      match(AsmParser::F);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(218);
      match(AsmParser::S);
      setState(219);
      match(AsmParser::R);
      setState(220);
      match(AsmParser::Q);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(221);
      match(AsmParser::G);
      setState(222);
      match(AsmParser::T);
      setState(223);
      match(AsmParser::F);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(224);
      match(AsmParser::R);
      setState(225);
      match(AsmParser::T);
      setState(226);
      match(AsmParser::F);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(227);
      match(AsmParser::S);
      setState(228);
      match(AsmParser::G);
      setState(229);
      match(AsmParser::T);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(230);
      match(AsmParser::C);
      setState(231);
      match(AsmParser::A);
      setState(232);
      match(AsmParser::F);
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
  enterRule(_localctx, 32, AsmParser::RuleEol);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AsmParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(235);
        match(AsmParser::T__3);
        break;
      }

      case AsmParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(236);
        match(AsmParser::T__4);
        break;
      }

      case AsmParser::T__5: {
        enterOuterAlt(_localctx, 3);
        setState(237);
        match(AsmParser::T__5);
        setState(238);
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
  "code", "statement", "symbol", "instruction", "ctl_ins", "start", "mem_ins", 
  "mem_op", "zero", "ind", "address", "opr_ins", "opr_op1", "opr_op2", "opr_op3", 
  "iot_ins", "eol"
};

std::vector<std::string> AsmParser::_literalNames = {
  "", "'.'", "'!'", "'@'", "';'", "'\n'", "'\r'"
};

std::vector<std::string> AsmParser::_symbolicNames = {
  "", "", "", "", "", "", "", "Octal", "Decimal", "ID", "WS", "A", "N", 
  "D", "T", "I", "S", "Z", "C", "J", "M", "P", "O", "R", "L", "B", "W", 
  "H", "K", "Q", "F", "G"
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
    0x3, 0x21, 0xf4, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x27, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x2a, 0xb, 0x2, 0x3, 0x3, 0x5, 0x3, 0x2d, 0xa, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x6, 0x3, 0x31, 0xa, 0x3, 0xd, 0x3, 0xe, 0x3, 0x32, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3b, 0xa, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x44, 0xa, 0x8, 0x3, 0x8, 0x5, 0x8, 0x47, 0xa, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x5d, 0xa, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x6, 0xd, 0x66, 0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0x67, 0x3, 0xd, 0x6, 
    0xd, 0x6b, 0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0x6c, 0x3, 0xd, 0x6, 0xd, 0x70, 
    0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0x71, 0x5, 0xd, 0x74, 0xa, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0xa0, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xc0, 0xa, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xce, 0xa, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xec, 0xa, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xf2, 0xa, 0x12, 0x3, 0x12, 0x2, 
    0x2, 0x13, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x2, 0x3, 0x3, 0x2, 0x9, 0xa, 0x2, 
    0x117, 0x2, 0x24, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2c, 0x3, 0x2, 0x2, 0x2, 
    0x6, 0x34, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3a, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x3e, 0x3, 0x2, 0x2, 0x2, 0xe, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x12, 0x5e, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x60, 0x3, 0x2, 0x2, 0x2, 0x16, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x18, 0x73, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x1c, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x20, 0xeb, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x24, 0x28, 0x5, 
    0x4, 0x3, 0x2, 0x25, 0x27, 0x5, 0x4, 0x3, 0x2, 0x26, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x27, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2d, 0x5, 0x6, 0x4, 0x2, 0x2c, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x30, 0x5, 0x8, 0x5, 0x2, 0x2f, 0x31, 0x5, 
    0x22, 0x12, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x5, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x7, 0xb, 0x2, 0x2, 
    0x35, 0x7, 0x3, 0x2, 0x2, 0x2, 0x36, 0x3b, 0x5, 0xe, 0x8, 0x2, 0x37, 
    0x3b, 0x5, 0x18, 0xd, 0x2, 0x38, 0x3b, 0x5, 0x20, 0x11, 0x2, 0x39, 0x3b, 
    0x5, 0xa, 0x6, 0x2, 0x3a, 0x36, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0xc, 0x7, 
    0x2, 0x3d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x3, 0x2, 0x2, 
    0x3f, 0x40, 0x5, 0x16, 0xc, 0x2, 0x40, 0xd, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x43, 0x5, 0x10, 0x9, 0x2, 0x42, 0x44, 0x5, 0x12, 0xa, 0x2, 0x43, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x46, 0x3, 
    0x2, 0x2, 0x2, 0x45, 0x47, 0x5, 0x14, 0xb, 0x2, 0x46, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x49, 0x5, 0x16, 0xc, 0x2, 0x49, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x4b, 0x7, 0xd, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0xe, 0x2, 0x2, 0x4c, 
    0x5d, 0x7, 0xf, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x10, 0x2, 0x2, 0x4e, 0x4f, 
    0x7, 0xd, 0x2, 0x2, 0x4f, 0x5d, 0x7, 0xf, 0x2, 0x2, 0x50, 0x51, 0x7, 
    0x11, 0x2, 0x2, 0x51, 0x52, 0x7, 0x12, 0x2, 0x2, 0x52, 0x5d, 0x7, 0x13, 
    0x2, 0x2, 0x53, 0x54, 0x7, 0xf, 0x2, 0x2, 0x54, 0x55, 0x7, 0x14, 0x2, 
    0x2, 0x55, 0x5d, 0x7, 0xd, 0x2, 0x2, 0x56, 0x57, 0x7, 0x15, 0x2, 0x2, 
    0x57, 0x58, 0x7, 0x16, 0x2, 0x2, 0x58, 0x5d, 0x7, 0x12, 0x2, 0x2, 0x59, 
    0x5a, 0x7, 0x15, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x16, 0x2, 0x2, 0x5b, 0x5d, 
    0x7, 0x17, 0x2, 0x2, 0x5c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x50, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x56, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x5d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x4, 0x2, 0x2, 
    0x5f, 0x13, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x5, 0x2, 0x2, 0x61, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x9, 0x2, 0x2, 0x2, 0x63, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x66, 0x5, 0x1a, 0xe, 0x2, 0x65, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x6b, 0x5, 0x1c, 0xf, 0x2, 0x6a, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x74, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x70, 
    0x5, 0x1e, 0x10, 0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x74, 0x3, 0x2, 0x2, 0x2, 0x73, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x73, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x19, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0xe, 0x2, 0x2, 0x76, 
    0x77, 0x7, 0x18, 0x2, 0x2, 0x77, 0xa0, 0x7, 0x17, 0x2, 0x2, 0x78, 0x79, 
    0x7, 0x11, 0x2, 0x2, 0x79, 0x7a, 0x7, 0xd, 0x2, 0x2, 0x7a, 0xa0, 0x7, 
    0x14, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x19, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0xd, 
    0x2, 0x2, 0x7d, 0xa0, 0x7, 0x1a, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x19, 0x2, 
    0x2, 0x7f, 0x80, 0x7, 0x10, 0x2, 0x2, 0x80, 0xa0, 0x7, 0x1a, 0x2, 0x2, 
    0x81, 0x82, 0x7, 0x19, 0x2, 0x2, 0x82, 0x83, 0x7, 0xd, 0x2, 0x2, 0x83, 
    0xa0, 0x7, 0x19, 0x2, 0x2, 0x84, 0x85, 0x7, 0x19, 0x2, 0x2, 0x85, 0x86, 
    0x7, 0x10, 0x2, 0x2, 0x86, 0xa0, 0x7, 0x19, 0x2, 0x2, 0x87, 0x88, 0x7, 
    0x1b, 0x2, 0x2, 0x88, 0x89, 0x7, 0x12, 0x2, 0x2, 0x89, 0xa0, 0x7, 0x1c, 
    0x2, 0x2, 0x8a, 0x8b, 0x7, 0x14, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x16, 0x2, 
    0x2, 0x8c, 0xa0, 0x7, 0x1a, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x14, 0x2, 0x2, 
    0x8e, 0x8f, 0x7, 0x16, 0x2, 0x2, 0x8f, 0xa0, 0x7, 0xd, 0x2, 0x2, 0x90, 
    0x91, 0x7, 0x14, 0x2, 0x2, 0x91, 0x92, 0x7, 0x11, 0x2, 0x2, 0x92, 0xa0, 
    0x7, 0xd, 0x2, 0x2, 0x93, 0x94, 0x7, 0x14, 0x2, 0x2, 0x94, 0x95, 0x7, 
    0x1a, 0x2, 0x2, 0x95, 0xa0, 0x7, 0x1a, 0x2, 0x2, 0x96, 0x97, 0x7, 0x12, 
    0x2, 0x2, 0x97, 0x98, 0x7, 0x10, 0x2, 0x2, 0x98, 0xa0, 0x7, 0x1a, 0x2, 
    0x2, 0x99, 0x9a, 0x7, 0x14, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x1a, 0x2, 0x2, 
    0x9b, 0xa0, 0x7, 0xd, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x12, 0x2, 0x2, 0x9d, 
    0x9e, 0x7, 0x10, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0xd, 0x2, 0x2, 0x9f, 0x75, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0x78, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x9f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0x84, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x9f, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x93, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0x96, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9c, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 
    0x1d, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x1a, 0x2, 0x2, 0xa3, 0xc0, 0x7, 0x10, 
    0x2, 0x2, 0xa4, 0xa5, 0x7, 0x18, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x12, 0x2, 
    0x2, 0xa6, 0xc0, 0x7, 0x19, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x12, 0x2, 0x2, 
    0xa8, 0xa9, 0x7, 0x1e, 0x2, 0x2, 0xa9, 0xc0, 0x7, 0x17, 0x2, 0x2, 0xaa, 
    0xab, 0x7, 0x12, 0x2, 0x2, 0xab, 0xac, 0x7, 0xe, 0x2, 0x2, 0xac, 0xc0, 
    0x7, 0x1a, 0x2, 0x2, 0xad, 0xae, 0x7, 0x12, 0x2, 0x2, 0xae, 0xaf, 0x7, 
    0x13, 0x2, 0x2, 0xaf, 0xc0, 0x7, 0x1a, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x12, 
    0x2, 0x2, 0xb1, 0xb2, 0x7, 0x13, 0x2, 0x2, 0xb2, 0xc0, 0x7, 0xd, 0x2, 
    0x2, 0xb3, 0xb4, 0x7, 0x12, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0xe, 0x2, 0x2, 
    0xb5, 0xc0, 0x7, 0xd, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x12, 0x2, 0x2, 0xb7, 
    0xb8, 0x7, 0x16, 0x2, 0x2, 0xb8, 0xc0, 0x7, 0xd, 0x2, 0x2, 0xb9, 0xba, 
    0x7, 0x12, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x17, 0x2, 0x2, 0xbb, 0xc0, 0x7, 
    0xd, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x14, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x1a, 
    0x2, 0x2, 0xbe, 0xc0, 0x7, 0xd, 0x2, 0x2, 0xbf, 0xa1, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbc, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0x14, 
    0x2, 0x2, 0xc2, 0xc3, 0x7, 0x16, 0x2, 0x2, 0xc3, 0xce, 0x7, 0xd, 0x2, 
    0x2, 0xc4, 0xc5, 0x7, 0x16, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x1f, 0x2, 0x2, 
    0xc6, 0xce, 0x7, 0xd, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x16, 0x2, 0x2, 0xc8, 
    0xc9, 0x7, 0x1f, 0x2, 0x2, 0xc9, 0xce, 0x7, 0x1a, 0x2, 0x2, 0xca, 0xcb, 
    0x7, 0x12, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x1c, 0x2, 0x2, 0xcc, 0xce, 0x7, 
    0x17, 0x2, 0x2, 0xcd, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xc4, 0x3, 0x2, 
    0x2, 0x2, 0xcd, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xca, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x11, 0x2, 0x2, 
    0xd0, 0xd1, 0x7, 0x18, 0x2, 0x2, 0xd1, 0xec, 0x7, 0x10, 0x2, 0x2, 0xd2, 
    0xd3, 0x7, 0x11, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x18, 0x2, 0x2, 0xd4, 0xec, 
    0x7, 0xe, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x12, 0x2, 0x2, 0xd6, 0xd7, 0x7, 
    0x1e, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x18, 0x2, 0x2, 0xd8, 0xec, 0x7, 0xe, 
    0x2, 0x2, 0xd9, 0xda, 0x7, 0x11, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x18, 0x2, 
    0x2, 0xdb, 0xec, 0x7, 0x20, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x12, 0x2, 0x2, 
    0xdd, 0xde, 0x7, 0x19, 0x2, 0x2, 0xde, 0xec, 0x7, 0x1f, 0x2, 0x2, 0xdf, 
    0xe0, 0x7, 0x21, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x10, 0x2, 0x2, 0xe1, 0xec, 
    0x7, 0x20, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x19, 0x2, 0x2, 0xe3, 0xe4, 0x7, 
    0x10, 0x2, 0x2, 0xe4, 0xec, 0x7, 0x20, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x12, 
    0x2, 0x2, 0xe6, 0xe7, 0x7, 0x21, 0x2, 0x2, 0xe7, 0xec, 0x7, 0x10, 0x2, 
    0x2, 0xe8, 0xe9, 0x7, 0x14, 0x2, 0x2, 0xe9, 0xea, 0x7, 0xd, 0x2, 0x2, 
    0xea, 0xec, 0x7, 0x20, 0x2, 0x2, 0xeb, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xeb, 
    0xd2, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xd9, 
    0x3, 0x2, 0x2, 0x2, 0xeb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xeb, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xeb, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xec, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0xed, 0xf2, 0x7, 0x6, 0x2, 0x2, 0xee, 0xf2, 0x7, 0x7, 0x2, 0x2, 
    0xef, 0xf0, 0x7, 0x8, 0x2, 0x2, 0xf0, 0xf2, 0x7, 0x7, 0x2, 0x2, 0xf1, 
    0xed, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0x23, 0x3, 0x2, 0x2, 0x2, 0x12, 0x28, 0x2c, 
    0x32, 0x3a, 0x43, 0x46, 0x5c, 0x67, 0x6c, 0x71, 0x73, 0x9f, 0xbf, 0xcd, 
    0xeb, 0xf1, 
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
