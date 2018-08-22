cmake_minimum_required(VERSION 3.9)
project(cpu_sim CXX)
enable_testing()

# Setting default folders
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# In CMakeModules I include code coverage for c++
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

configure_file(run_all_unit_tests.in run_all_unit_tests)

if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage ${CMAKE_BINARY_DIR}/run_all_unit_tests coverage)
endif()

set(COMPILER_WARNING_FLAGS "-Wreturn-type -Wall -Werror -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")
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
