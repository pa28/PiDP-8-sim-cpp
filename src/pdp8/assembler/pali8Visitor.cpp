//
// Created by richard on 2018-08-12.
//

#include <vector>
#include "pali8Visitor.h"


antlrcpp::Any pali8Visitor::returnVector(std::vector<std::any> vector) {
    if (vector.empty())
        return antlrcpp::Any();
    else if (vector.size() == 1)
        return vector.front();
    return std::any(vector);
}

antlrcpp::Any pali8Visitor::visitCode(AsmParser::CodeContext *ctx) {
    auto results = visitAllChildren(ctx);

    return returnVector(results);
}

antlrcpp::Any pali8Visitor::visitSymbol(AsmParser::SymbolContext *ctx) {
    auto results = visitAllChildren(ctx);

    return returnVector(results);
}

antlrcpp::Any pali8Visitor::visitStatements(AsmParser::StatementsContext *ctx) {
    auto results = visitAllChildren(ctx);

    return results;
}

antlrcpp::Any pali8Visitor::visitStatement(AsmParser::StatementContext *ctx) {
    auto results = visitAllChildren(ctx);

    return returnVector(results);
}

antlrcpp::Any pali8Visitor::visitInstruction(AsmParser::InstructionContext *ctx) {
    auto results = visitAllChildren(ctx);

    return returnVector(results);
}

antlrcpp::Any pali8Visitor::visitOpr_ins(AsmParser::Opr_insContext *ctx) {
    auto results = visitAllChildren(ctx);

    return returnVector(results);
}

antlrcpp::Any pali8Visitor::visitOpr_op1(AsmParser::Opr_op1Context *ctx) {
    auto results = visitAllChildren(ctx);

    int ret_code = 0;
    for (auto const &op : results) {
        if (op.type() == typeid(pdp8_asm::OperateGroup1)) {
            auto opt_enum = std::any_cast<pdp8_asm::OperateGroup1>(op);
            switch (opt_enum) {
                case pdp8_asm::NOP:
                    ret_code |= 07000;
                    break;
                case pdp8_asm::IAC:
                    ret_code |= 07001;
                    break;
                case pdp8_asm::RAL:
                    ret_code |= 07004;
                    break;
                case pdp8_asm::RTL:
                    ret_code |= 07006;
                    break;
                case pdp8_asm::RAR:
                    ret_code |= 07010;
                    break;
                case pdp8_asm::RTR:
                    ret_code |= 07012;
                    break;
                case pdp8_asm::BSW:
                    ret_code |= 07002;
                    break;
                case pdp8_asm::CML:
                    ret_code |= 07020;
                    break;
                case pdp8_asm::CMA:
                    ret_code |= 07040;
                    break;
                case pdp8_asm::CIA:
                    ret_code |= 07041;
                    break;
                case pdp8_asm::CLL:
                    ret_code |= 07100;
                    break;
                case pdp8_asm::STL:
                    ret_code |= 07120;
                    break;
                case pdp8_asm::CLA:
                    ret_code |= 07200;
                    break;
                case pdp8_asm::STA:
                    ret_code |= 07240;
                    break;
            }
        }
    }

    return pdp8_asm::pdp8_instruction(ret_code);
}

antlrcpp::Any pali8Visitor::visitMem_op(AsmParser::Mem_opContext *ctx) {
    auto results = visitAllChildren(ctx);

    return returnVector(results);
}

antlrcpp::Any pali8Visitor::visitMem_ins(AsmParser::Mem_insContext *ctx) {
    return AsmBaseVisitor::visitMem_ins(ctx);
}
