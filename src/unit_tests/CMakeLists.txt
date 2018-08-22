file(GLOB pdp8_SOURCE ../pdp8/*.cpp)

set(hw_registers_SOURCE hw_registers.cpp)
set(asm_cpu_tests_SOURCE asm_cpu_tests.cpp ${pdp8_SOURCE})

include_directories( ${PROJECT_SOURCE_DIR}/src/sim_r ${PROJECT_SOURCE_DIR}/src/pdp8 ${GTEST_INCLUDE_DIRS})

add_executable(hw_registers ${hw_registers_SOURCE})
target_link_libraries(hw_registers gtest ${CMAKE_THREAD_LIBS_INIT})
add_test(hw_registers hw_registers)

add_executable(asm_cpu_tests ${asm_cpu_tests_SOURCE})
target_link_libraries(asm_cpu_tests gtest ${CMAKE_THREAD_LIBS_INIT} assembler antlr4_static)
add_test(asm_cpu_tests asm_cpu_tests)
