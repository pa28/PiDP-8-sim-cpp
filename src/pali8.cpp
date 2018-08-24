//
// Created by richard on 2018-08-12.
//

#include <iostream>
#include <sstream>
#include "antlr4-runtime.h"
#include "AsmLexer.h"
#include "AsmParser.h"
#include "pali8Visitor.h"
#include "ParserProcessor.h"

using namespace std;
using namespace sim;
using namespace pdp8_asm;


int main(int argc, char **argv) {
    std::stringstream strm{". 0200;start rar cia;cia;. 0400;tad !@ 010;"};

    ParserProcessor<AsmParser::CodeContext, AsmLexer, AsmParser> asmProcessor;

    pali8Visitor visitor{};

    auto parserRuleFunction =
            [](ParserRule<AsmParser::CodeContext, AsmLexer, AsmParser> &rule) -> auto {
                return rule.parser->code();
            };

    auto parserVisitorFunction =
            [&visitor](ParserRule<AsmParser::CodeContext, AsmLexer, AsmParser> &rule) -> auto {
                return visitor.visitCode(rule.rule);
            };

    auto anyResult = asmProcessor.process(strm, parserRuleFunction, parserVisitorFunction);

    auto code_list = std::any_cast<std::vector<std::any>>(anyResult);

    ++visitor.assembler_pass;
    visitor.program_counter.memory_addr = 0;

    code_list = std::any_cast<std::vector<std::any>>(visitor.visitCode(asmProcessor.parserRule.rule));

    for (auto const &symbol : visitor.symbol_table) {
        cout << symbol.first << ' ' << symbol.second.memory_addr << endl;
    }

    pdp8_address pc{};

    for (auto const &code : code_list) {
        if (code.type() == typeid(pdp8_instruction)) {
            auto instruction = std::any_cast<pdp8_instruction>(code);
            cout << pc.memory_addr << "   " << instruction.instruction << endl;
            ++pc;
        } else if (code.type() == typeid(pdp8_address)) {
            pc = std::any_cast<pdp8_address>(code);
        }
    }

    return 0;
}
