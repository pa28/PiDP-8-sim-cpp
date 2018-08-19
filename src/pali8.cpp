//
// Created by richard on 2018-08-12.
//

#include <iostream>
#include <sstream>
#include "antlr4-runtime.h"
#include "AsmLexer.h"
#include "AsmParser.h"
#include "pali8Visitor.h"

using namespace std;
using namespace sim;
using namespace pdp8_asm;

int main(int argc, char **argv) {
    std::stringstream strm{". 0200;start rar cia;cia;. 0400;tad !@ 010;"};

    // ToDo: find out what is being linked in here not satisfied by the cross compiler. Probable causes are
    // the pkg-config and uuid-dev libraries.
    antlr4::ANTLRInputStream input(strm);
    AsmLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    AsmParser parser(&tokens);

    auto tree = parser.code();
    pali8Visitor visitor;

    auto code_list = std::any_cast<std::vector<std::any>>(visitor.visitCode(tree));

    ++visitor.assembler_pass;
    visitor.program_counter.memory_addr = 0;

    code_list = std::any_cast<std::vector<std::any>>(visitor.visitCode(tree));

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
