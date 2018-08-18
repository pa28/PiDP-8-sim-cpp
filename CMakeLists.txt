cmake_minimum_required(VERSION 3.9)
project(cpu_sim CXX)
enable_testing()

set(COMPILER_WARNING_FLAGS -Wreturn-type)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_WARNING_FLAGS}")

include(antlr4.cmake)
include(gtest.cmake)
include(assembler.cmake)

find_package (Threads)

add_subdirectory(src/unit_tests)
add_subdirectory(src/pdp8/asm_parser)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src/sim_r
        ${CMAKE_CURRENT_SOURCE_DIR}/src/pdp8
)

add_executable(pali8 src/pali8.cpp ${pali8_SOURCE})
target_link_libraries(pali8 assembler antlr4_static)

set(sim_r_SOURCE src/sim_r/hardware.h src/sim_r/PerformanceClock.h
        src/sim_r/CpuThread.cpp src/sim_r/CpuThread.h)

set(pdp8_SOURCE src/pdp8/cpu.cpp src/pdp8/cpu.h src/pdp8/device.h src/pdp8/DK8EA.cpp src/pdp8/DK8EA.h
        src/pdp8/chassis.cpp src/pdp8/chassis.h src/pdp8/pdp8.h src/pdp8/device.cpp)

add_executable(cpu_sim src/main.cpp ${pdp8_SOURCE} ${sim_r_SOURCE})
target_link_libraries (cpu_sim ${CMAKE_THREAD_LIBS_INIT})
