//
// Created by richard on 2018-08-12.
//

#include <iostream>
#include <strstream>
#include "antlr4-runtime.h"
#include "AsmLexer.h"
#include "AsmParser.h"
#include "pali8Visitor.h"

int main(int argc, char **argv) {
    std::stringstream strm{"start rar cia;cia;tad !@ 010;"};

    antlr4::ANTLRInputStream input(strm);
    AsmLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    AsmParser parser(&tokens);

    auto tree = parser.code();
    pali8Visitor visitor;
    auto code_list = std::any_cast<std::vector<std::any>>(visitor.visitCode(tree));
    for (auto const &code : code_list) {
        if (code.type() == typeid(pdp8_asm::pdp8_instruction) ) {
            auto instruction = std::any_cast<pdp8_asm::pdp8_instruction>(code);
            instruction.instruction.print_on(std::cout) << std::endl;
        }
    }

    return 0;
}
