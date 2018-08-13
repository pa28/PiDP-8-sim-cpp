include_directories( /usr/local/include/antlr4-runtime ${PROJECT_SOURCE_DIR}/src/sim_r ${PROJECT_SOURCE_DIR}/src/pdp8
        ${PROJECT_SOURCE_DIR}/src/pdp8/asm_parser ${GTEST_INCLUDE_DIRS})

set(pali8_SOURCE
        ../asm_parser/AsmBaseListener.h ../asm_parser/AsmBaseListener.cpp
        ../asm_parser/AsmLexer.h ../asm_parser/AsmLexer.cpp ../asm_parser/AsmListener.h ../asm_parser/AsmListener.cpp
        ../asm_parser/AsmBaseVisitor.h ../asm_parser/AsmBaseVisitor.cpp
        ../asm_parser/AsmVisitor.h ../asm_parser/AsmVisitor.cpp
        ../asm_parser/AsmParser.h ../asm_parser/AsmParser.cpp
        pdp8_instruction.h pdp8_instruction.cpp
        pali8Visitor.h pali8Visitor.cpp
        )

add_executable(pali8 pali8.cpp ${pali8_SOURCE})
target_link_libraries(pali8 /usr/local/lib/libantlr4-runtime.a)
