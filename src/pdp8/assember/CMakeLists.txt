set(pali8_SOURCE ../asm_parser/asmBaseListener.h ../asm_parser/asmBaseListener.cpp
        ../asm_parser/asmLexer.h ../asm_parser/asmLexer.cpp ../asm_parser/asmListener.h ../asm_parser/asmListener.cpp
        )

add_executable(pali8 pali8.cpp)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/src/sim_r ${CMAKE_CURRENT_SOURCE_DIR}/src/pdp8
        ${CMAKE_CURRENT_SOURCE_DIR}/pdp8/asm_parser ${GTEST_INCLUDE_DIRS})