//
// Created by richard on 2018-08-12.
//

#include <vector>
#include <stdexcept>
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

    if (not results.empty()) {
        if (results.front().type() == typeid(std::string)) {
            set_symbol(std::any_cast<std::string>(results.front()), program_counter);
            results.erase(results.begin());
        }
    }

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


antlrcpp::Any pali8Visitor::visitIot_ins(AsmParser::Iot_insContext *ctx) {
    auto results = visitAllChildren(ctx);

    int ret_code = 0;
    for (auto const &op : results) {
        if (op.type() == typeid(pdp8_asm::InputOutputTransfer)) {
            auto opt_enum = std::any_cast<pdp8_asm::InputOutputTransfer>(op);
            switch (opt_enum) {
                case pdp8_asm::IOT:
                    ret_code |= 06000;
                    break;
                case pdp8_asm::ION:
                    ret_code |= 06001;
                    break;
                case pdp8_asm::SKON:
                    ret_code |= 06000;
                    break;
                case pdp8_asm::IOF:
                    ret_code |= 06002;
                    break;
                case pdp8_asm::SRQ:
                    ret_code |= 06003;
                    break;
                case pdp8_asm::GTF:
                    ret_code |= 06004;
                    break;
                case pdp8_asm::RTF:
                    ret_code |= 06005;
                    break;
                case pdp8_asm::SGT:
                    ret_code |= 06006;
                    break;
                case pdp8_asm::CAF:
                    ret_code |= 06007;
                    break;
            }
        }
    }

    return pdp8_asm::pdp8_instruction(ret_code);
}

antlrcpp::Any pali8Visitor::visitOpr_op1(AsmParser::Opr_op1Context *ctx) {
    auto results = visitAllChildren(ctx);

    int ret_code = 0;
    for (auto const &op : results) {
        if (op.type() == typeid(pdp8_asm::OperateCommon)) {
            auto opt_enum = std::any_cast<pdp8_asm::OperateCommon>(op);
            if (opt_enum == pdp8_asm::CLA)
                ret_code |= 07200;
        } else if (op.type() == typeid(pdp8_asm::OperateGroup1)) {
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
                case pdp8_asm::STA:
                    ret_code |= 07240;
                    break;
            }
        }
    }

    if ((ret_code & 07014) == 07014 || (ret_code & 07016) == 07016)
        throw std::logic_error("Micro-code not allowed.");

    return pdp8_asm::pdp8_instruction(ret_code);
}

antlrcpp::Any pali8Visitor::visitOpr_op2(AsmParser::Opr_op2Context *ctx) {
    auto results = visitAllChildren(ctx);

    int ret_code = 0;
    for (auto const &op : results) {
        if (op.type() == typeid(pdp8_asm::OperateCommon)) {
            auto opt_enum = std::any_cast<pdp8_asm::OperateCommon>(op);
            if (opt_enum == pdp8_asm::CLA)
                ret_code |= 07600;
        } else if (op.type() == typeid(pdp8_asm::OperateGroup2)) {
            auto opt_enum = std::any_cast<pdp8_asm::OperateGroup2>(op);
            switch (opt_enum) {
                case pdp8_asm::HLT:
                    ret_code |= 07402;
                    break;
                case pdp8_asm::OSR:
                    ret_code |= 07404;
                    break;
                case pdp8_asm::SKP:
                    ret_code |= 07410;
                    break;
                case pdp8_asm::SNL:
                    ret_code |= 07420;
                    break;
                case pdp8_asm::SZL:
                    ret_code |= 07430;
                    break;
                case pdp8_asm::SZA:
                    ret_code |= 07440;
                    break;
                case pdp8_asm::SNA:
                    ret_code |= 07450;
                    break;
                case pdp8_asm::SMA:
                    ret_code |= 07500;
                    break;
                case pdp8_asm::SPA:
                    ret_code |= 07510;
                    break;
            }
        }
    }

    return pdp8_asm::pdp8_instruction(ret_code);
}

antlrcpp::Any pali8Visitor::visitOpr_op3(AsmParser::Opr_op3Context *ctx) {
    auto results = visitAllChildren(ctx);

    int ret_code = 0;
    for (auto const &op : results) {
        if (op.type() == typeid(pdp8_asm::OperateGroup3)) {
            auto opt_enum = std::any_cast<pdp8_asm::OperateGroup3>(op);
            switch (opt_enum) {
                case pdp8_asm::CAM:
                    ret_code |= 07621;
                    break;
                case pdp8_asm::MQA:
                    ret_code |= 07501;
                    break;
                case pdp8_asm::MQL:
                    ret_code |= 07421;
                    break;
                case pdp8_asm::SWP:
                    ret_code |= 07521;
                    break;
            }
        }
    }

    return pdp8_asm::pdp8_instruction(ret_code);
}

antlrcpp::Any pali8Visitor::visitMem_ins(AsmParser::Mem_insContext *ctx) {
    auto results = visitAllChildren(ctx);

    pdp8_asm::pdp8_instruction instruction{};
    pdp8_asm::pdp8_address address{};

    for (auto const &part : results) {
        if (part.type() == typeid(pdp8_asm::pdp8_instruction))
            instruction = std::any_cast<pdp8_asm::pdp8_instruction>(part);
        else if (part.type() == typeid(unsigned long))
            address = std::any_cast<unsigned long>(part);
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

    if (instruction.instruction[pdp8_asm::pdp8_instruction::zero]) {
        auto p1 = address.memory_addr[pdp8_asm::pdp8_address::page];
        auto p2 = program_counter.memory_addr[pdp8_asm::pdp8_address::page];
        if (p1 != p2) {
            throw std::out_of_range("off page address"); // ToDo create parser aware error exceptions.
        }
    } else {
        if (address.memory_addr[pdp8_asm::pdp8_address::page]) {
            throw std::out_of_range("off page zero address"); // ToDo create parser aware error exceptions.
        }
    }

    instruction.instruction << address.memory_addr[pdp8_asm::pdp8_address::address];

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

    if (not results.empty()) {
        if (results.front().type() == typeid(unsigned long)) {
            program_counter.memory_addr = std::any_cast<unsigned long>(results.front());
            return pdp8_asm::pdp8_address{program_counter};
        } else if (results.front().type() == typeid(std::string)) {
            program_counter = symbol_table.at(std::any_cast<std::string>(results.front()));
            return pdp8_asm::pdp8_address{program_counter};
        }
    }

    return antlrcpp::Any();
}

antlrcpp::Any pali8Visitor::visitDef_const(AsmParser::Def_constContext *ctx) {
    auto results = visitAllChildren(ctx);

    if (results.front().type() == typeid(unsigned long)) {
        return std::any(pdp8_asm::pdp8_instruction{std::any_cast<unsigned long>(results.front())});
    }

    return returnVector(results);
}
