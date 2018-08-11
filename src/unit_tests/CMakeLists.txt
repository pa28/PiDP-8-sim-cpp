set(hw_registers_SOURCE hw_registers.cpp ../sim_r/hardware.h)

include_directories( ${PROJECT_SOURCE_DIR}/src/sim_r ${PROJECT_SOURCE_DIR}/src/pdp8 ${GTEST_INCLUDE_DIRS})

add_executable(hw_registers ${hw_registers_SOURCE})
target_link_libraries(hw_registers GTest::GTest GTest::Main)