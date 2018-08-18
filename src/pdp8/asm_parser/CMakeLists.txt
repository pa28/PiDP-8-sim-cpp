
set(ANTLR_PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(OUTPUT AsmParser.cpp AsmParser.h AsmVisitor.cpp AsmVisitor.h AsmBaseVisitor.cpp AsmBaseVisitor.h
        AsmBaseListener.cpp AsmBaseListener.h AsmLexer.cpp AsmLexer.h AsmListener.cpp Asm.tokens AsmLexer.tokens
        COMMAND java -jar /usr/local/lib/antlr-4.7-complete.jar -Dlanguage=Cpp -visitor -o ${ANTLR_PARSER_DIR} ${ANTLR_PARSER_DIR}/Asm.g4
        WORKING_DIRECTORY ${ANTLR_PARSER_DIR}
        DEPENDS ${ANTLR_PARSER_DIR}/Asm.g4
        COMMENT "Generate antlr4 parser."
        )

add_custom_target(antlr_parser DEPENDS AsmBaseVisitor.cpp AsmBaseVisitor.h)
