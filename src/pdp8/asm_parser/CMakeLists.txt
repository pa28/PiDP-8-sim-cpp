
set(ANTLR_PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(antlr_parser
        COMMAND java -jar /usr/local/lib/antlr-4.7-complete.jar -Dlanguage=Cpp -visitor -o ${ANTLR_PARSER_DIR} ${ANTLR_PARSER_DIR}/Asm.g4
        WORKING_DIRECTORY ${ANTLR_PARSER_DIR}
        COMMENT "Generate antlr4 parser."
        )
