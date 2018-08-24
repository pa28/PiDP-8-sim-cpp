
// Generated from /mnt/v/CLionProjects/PiDP-8-sim-cpp/src/pdp8/asm_parser/Asm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  AsmLexer : public antlr4::Lexer {
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
    CLSF = 57, CLEI = 58, CLDI = 59, CLSK = 60, CLSI = 61, CLSM = 62, RAND = 63, 
    CLRF = 64, Octal = 65, Decimal = 66, ID = 67, WS = 68
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

