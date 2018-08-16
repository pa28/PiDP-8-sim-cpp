include_directories(
        src/pdp8/assembler
        src/pdp8/asm_parser
)

file(GLOB ASSEMBLER_SOURCES
        src/pdp8/assembler/*.cpp
        src/pdp8/asm_parser/*.cpp
        )

add_library(assembler ${ASSEMBLER_SOURCES})
