set(ASSEMBLER_ROOT src/pdp8/assembler)
set(PARSER_ROOT src/pdp8/asm_parser)

include_directories(
        ${PROJECT_SOURCE_DIR}/${ASSEMBLER_ROOT}
        ${PROJECT_SOURCE_DIR}/${PARSER_ROOT}
)

file(GLOB ASSEMBLER_SOURCES
        ${PROJECT_SOURCE_DIR}/${ASSEMBLER_ROOT}/*.cpp
        ${PROJECT_SOURCE_DIR}/${PARSER_ROOT}/*.cpp
        )

foreach (_source ${ASSEMBLER_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach ()

add_library(assembler ${ASSEMBLER_SOURCES})
