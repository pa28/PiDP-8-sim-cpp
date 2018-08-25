#! /bin/bash
# Bash Script that builds project

RED='\033[0;31m' # Red
BB='\033[0;34m'  # Blue
NC='\033[0m' # No Color
BG='\033[0;32m' # Green

error() { >&2 echo -e "${RED}$1${NC}"; }
showinfo() { echo -e "${BG}$1${NC}"; }
workingprocess() { echo -e "${BB}$1${NC}"; }
allert () { echo -e "${RED}$1${NC}"; }

# Building project
mkdir -p cmake-build-ci
cd cmake-build-ci
cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-7 -DCMAKE_C_COMPILER=/usr/bin/gcc-7 -DCMAKE_BUILD_TYPE=Debug ..
make -j8
# Checks if last comand didn't output 0
# $? checks what last command outputed
# If output is 0 then command is succesfuly executed
# If command fails it outputs number between 0 to 255
if [ $? -ne 0 ]; then
    error "Error: there are compile errors!"
	# Terminate script and outputs 3
    exit 3
fi

showinfo "Running tests ..."
chmod u+x run_all_unit_tests
make -j8 cpu_sim_coverage
if [ $? -ne 0 ]; then
    error "Error: there are failed tests!"
    exit 4
fi

workingprocess "All tests compile and pass."
