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
    if (ctx->ID()) {
        auto symbol = ctx->getText();
        return symbol;
    }
    return antlrcpp::Any();
}

antlrcpp::Any pali8Visitor::visitStatements(AsmParser::StatementsContext *ctx) {
    auto results = visitAllChildren(ctx);

    return results;
}

antlrcpp::Any pali8Visitor::visitStatement(AsmParser::StatementContext *ctx) {
    auto results = visitAllChildren(ctx);

    return returnVector(results);
}


antlrcpp::Any pali8Visitor::visitPragma(AsmParser::PragmaContext *ctx) {
    auto results = visitAllChildren(ctx);

    return returnVector(results);
}

antlrcpp::Any pali8Visitor::visitInstruction(AsmParser::InstructionContext *ctx) {
    auto results = visitAllChildren(ctx);

    for (auto const &part : results) {
        if (part.type() == typeid(std::string)) {
            set_symbol(std::any_cast<std::string>(part), program_counter);
        } else if (part.type() == typeid(pdp8_asm::pdp8_instruction)) {
            ++program_counter;
            return part;
        }
    }

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

antlrcpp::Any pali8Visitor::visitMem_ins(AsmParser::Mem_insContext *ctx) {
    auto results = visitAllChildren(ctx);

    pdp8_asm::pdp8_instruction instruction{};
    for (auto const &part : results) {
        if (part.type() == typeid(pdp8_asm::pdp8_instruction))
            instruction = std::any_cast<pdp8_asm::pdp8_instruction>(part);
        else if (part.type() == typeid(unsigned long))
            instruction.set_address(std::any_cast<unsigned long>(part));
        else if (part.type() == typeid(pdp8_asm::MemoryInstructionFlags))
            switch (std::any_cast<pdp8_asm::MemoryInstructionFlags>(part)) {
            case pdp8_asm::ZERO:
                instruction.instruction << pdp8_asm::pdp8_instruction::zero.clear();
                break;
            case pdp8_asm::INDIRECT:
                instruction.instruction << pdp8_asm::pdp8_instruction::indirect.set();
                break;
        }
    }
    return instruction;
}

antlrcpp::Any pali8Visitor::visitAddress(AsmParser::AddressContext *ctx) {
    auto text = ctx->getText();
    char *end = nullptr;
    if (ctx->Decimal()) {
        return std::strtoul(text.c_str(), &end, 10);
    } else if (ctx->Octal()) {
        return std::strtoul(text.c_str(), &end, 8);
    }

    return antlrcpp::Any();
}

antlrcpp::Any pali8Visitor::visitMem_op(AsmParser::Mem_opContext *ctx) {
    auto results = visitAllChildren(ctx);

    int ret_code = 0;
    for (auto const &op : results) {
        if (op.type() == typeid(pdp8_asm::MemoryInstruction)) {
            auto opt_enum = std::any_cast<pdp8_asm::MemoryInstruction >(op);
            // Set the ZERO flag to be cleared by specification of zero page addressing.
            switch (opt_enum) {
                case pdp8_asm::AND:
                    ret_code |= 00200;
                    break;
                case pdp8_asm::TAD:
                    ret_code |= 01200;
                    break;
                case pdp8_asm::ISZ:
                    ret_code |= 02200;
                    break;
                case pdp8_asm::DCA:
                    ret_code |= 03200;
                    break;
                case pdp8_asm::JMS:
                    ret_code |= 04200;
                    break;
                case pdp8_asm::JMP:
                    ret_code |= 05200;
                    break;
            }
        }
    }

    return pdp8_asm::pdp8_instruction(ret_code);
}

antlrcpp::Any pali8Visitor::visitStart(AsmParser::StartContext *ctx) {
    auto results = visitAllChildren(ctx);

    auto start = returnVector(results);

    if (start.type() == typeid(unsigned long)) {
        program_counter.memory_addr = std::any_cast<unsigned long>(start);
        return pdp8_asm::pdp8_address{program_counter};
    } else {
        // ToDo: process symbol.
    }

    return antlrcpp::Any();
}
