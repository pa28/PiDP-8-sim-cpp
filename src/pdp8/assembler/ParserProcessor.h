//
// Created by richard on 2018-08-22.
//

#pragma once

#include <iostream>
#include <memory>
#include "antlr4-runtime.h"


namespace pdp8_asm {

    template<class RuleClass, class LexerClass, class ParserClass>
    class ParserRule {
    protected:
        std::unique_ptr<antlr4::ANTLRInputStream> input;
        std::unique_ptr<LexerClass> lexer;
        std::unique_ptr<antlr4::CommonTokenStream> tokenStream;

    public:
        std::unique_ptr<ParserClass> parser;
        RuleClass *rule;

        using rule_class_t = RuleClass;
        using lexer_class_t = LexerClass;
        using parser_class_t = ParserClass;

        ParserRule()
                : input{},
                  lexer{},
                  tokenStream{},
                  parser{},
                  rule{nullptr} {}

        void load(std::istream &istream) {
            input = std::make_unique<antlr4::ANTLRInputStream>(istream);
            lexer = std::make_unique<LexerClass>(&*input);
            tokenStream = std::make_unique<antlr4::CommonTokenStream>(&*lexer);
            parser = std::make_unique<ParserClass>(&*tokenStream);
/* ToDo: Implement error listener.
            lexer->removeErrorListeners();
            lexer->addErrorListener(&antlr4::AsmErrorListener::INSTANCE);
            parser->removeErrorListeners();
            parser->addErrorListener(&antlr4::AsmErrorListener::INSTANCE);
*/
        }

        void set_rule(RuleClass *parserRuleContext) {
            rule = parserRuleContext;
        }
    };

    template<class ParserContext, class LexerClass, class ParserClass>
    class ParserProcessor {
    public:
        ParserRule<ParserContext, LexerClass, ParserClass> parserRule{};

        ParserProcessor() = default;

        template<class RuleSelectorFunction, class ProcessVisitorFunction>
        std::any process(std::istream &istream, RuleSelectorFunction ruleSelectorFunction,
                         ProcessVisitorFunction processVisitorFunction) {
            try {
                parserRule.load(istream);
                parserRule.set_rule(ruleSelectorFunction(parserRule));
                return processVisitorFunction(parserRule);
            } catch (...) {
                throw;
            }
        }
    };

} // namespace pdp8_asm
