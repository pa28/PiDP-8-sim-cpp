set(ANTLR4CPP_ROOT antlr4/runtime/Cpp)

include_directories(
        ${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src
        ${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/atn
        ${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/dfa
        ${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/misc
        ${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/support
        ${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/tree
        ${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/tree/pattern
        ${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/tree/xpath
)

file(GLOB ANTLR4CPP_SOURCES
        "${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/atn/*.cpp"
        "${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/dfa/*.cpp"
        "${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/misc/*.cpp"
        "${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/support/*.cpp"
        "${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/tree/*.cpp"
        "${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/tree/pattern/*.cpp"
        "${PROJECT_SOURCE_DIR}/${ANTLR4CPP_ROOT}/runtime/src/tree/xpath/*.cpp"
        )

foreach (_source ${ANTLR4CPP_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1})
endforeach ()

#add_library(antlr4_shared SHARED ${ANTLR4CPP_SOURCES})
add_library(antlr4_static STATIC ${ANTLR4CPP_SOURCES})
