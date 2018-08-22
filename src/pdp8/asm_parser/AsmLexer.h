
// Generated from /mnt/v/CLionProjects/PiDP-8-sim-cpp/src/pdp8/asm_parser/Asm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  AsmLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, AND = 7, 
    TAD = 8, ISZ = 9, DCA = 10, JMS = 11, JMP = 12, NOP = 13, IAC = 14,
      RAL = 15, RTL = 16, RAR = 17, RTR = 18, BSW = 19, CML = 20, CMA = 21,
    CIA = 22, CLL = 23, STL = 24, CLA = 25, STA = 26, HLT = 27, OSR = 28, 
    SKP = 29, SNL = 30, SZL = 31, SZA = 32, SNA = 33, SMA = 34, SPA = 35, 
    CAM = 36, MQA = 37, MQL = 38, SWP = 39, IOT = 40, ION = 41, SKON = 42,
      IOF = 43, SRQ = 44, GTF = 45, RTF = 46, SGT = 47, CAF = 48, Octal = 49,
      Decimal = 50, ID = 51, WS = 52
  };

  AsmLexer(antlr4::CharStream *input);
  ~AsmLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

