# PiDP-8 Simulator in C++17 [![Build Status](https://travis-ci.org/pa28/PiDP-8-sim-cpp.svg?branch=master)](https://travis-ci.org/pa28/PiDP-8-sim-cpp) [![codecov](https://codecov.io/gh/pa28/PiDP-8-sim-cpp/branch/master/graph/badge.svg)](https://codecov.io/gh/pa28/PiDP-8-sim-cpp)

Definitely not ready for prime-time, this project is under heavy development
and may change or stop working without notice. Not much is working at the
moment anyway, but you are welcome to poke around and try things out if
you are brave and have lots of time.

## Prerequisites.

### Antlr4 and Antlr4 C++ Runtime for C++17 Google Test

```
sudo apt-get install pkg-config uuid-dev
```
  

Since the git repository contains the source code for the parser, you 
don't need to build it. But if you want to experiment with the
assembler syntax you will need the antlr 4.7 complete JAR to compile
Asm.g4 into the parser source files. Get if from here:
```
curl -O https://www.antlr.org/download/antlr-4.7-complete.jar
```

and move it to a standard location. I used `/usr/local/lib` but you can use
a different location and update the `CMakeLists.txt` file.

## Building on a Raspberry Pi

You will need a modern build environment. First you will need a C++
compiler conformant with C++17. I recommend `gcc-8.1.0`. Follow the
instructions found at [Raspberry Pi - Install GCC 8 and compile C++17 programs](https://solarianprogrammer.com/2017/12/08/raspberry-pi-raspbian-install-gcc-compile-cpp-17-programs/)

Then you will need an up-to-date version of `cmake`. I suggest you follow
the instructions at [Installing CMake](https://cmake.org/install) and get version 3.12.0