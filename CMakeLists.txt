cmake_minimum_required(VERSION 3.9)
project(cpu_sim CXX)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

include(antlr4.cmake)
include(gtest.cmake)

find_package (Threads)

#add_executable(foo foo.cc)te
#target_link_libraries(foo GTest::GTest GTest::Main)

#add_test(AllTestsInFoo foo)

add_subdirectory(src/unit_tests)
add_subdirectory(src/pdp8/assembler)
add_subdirectory(src/pdp8/asm_parser)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/sim_r ${CMAKE_CURRENT_SOURCE_DIR}/src/pdp8
        ${CMAKE_CURRENT_SOURCE_DIR}/src/pdp8/asm_parser ${CMAKE_CURRENT_SOURCE_DIR}/src/pdp8/assembler)

set(sim_r_SOURCE src/sim_r/hardware.h src/sim_r/PerformanceClock.h
        src/sim_r/CpuThread.cpp src/sim_r/CpuThread.h)

set(pdp8_SOURCE src/pdp8/cpu.cpp src/pdp8/cpu.h src/pdp8/device.h src/pdp8/DK8EA.cpp src/pdp8/DK8EA.h
        src/pdp8/chassis.cpp src/pdp8/chassis.h src/pdp8/pdp8.h src/pdp8/device.cpp)

add_executable(cpu_sim main.cpp ${pdp8_SOURCE} ${sim_r_SOURCE})
target_link_libraries (cpu_sim ${CMAKE_THREAD_LIBS_INIT})

set(pali8_SOURCE
        src/pdp8/asm_parser/AsmBaseListener.h src/pdp8/asm_parser/AsmBaseListener.cpp
        src/pdp8/asm_parser/AsmLexer.h src/pdp8/asm_parser/AsmLexer.cpp src/pdp8/asm_parser/AsmListener.h src/pdp8/asm_parser/AsmListener.cpp
        src/pdp8/asm_parser/AsmBaseVisitor.h src/pdp8/asm_parser/AsmBaseVisitor.cpp
        src/pdp8/asm_parser/AsmVisitor.h src/pdp8/asm_parser/AsmVisitor.cpp
        src/pdp8/asm_parser/AsmParser.h src/pdp8/asm_parser/AsmParser.cpp
        src/pdp8/assembler/pdp8_instruction.h src/pdp8/assembler/pdp8_instruction.cpp
        src/pdp8/assembler/pali8Visitor.h src/pdp8/assembler/pali8Visitor.cpp
        )

add_executable(pali8 src/pdp8/assembler/pali8.cpp ${pali8_SOURCE})
#add_dependencies(pali8 antlr_parser)
target_link_libraries(pali8 antlr4_static)
