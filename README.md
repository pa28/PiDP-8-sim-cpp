# PiDP-8 Simulator in C++17 [![Build Status](https://travis-ci.org/pa28/PiDP-8-sim-cpp.svg?branch=master)](https://travis-ci.org/pa28/PiDP-8-sim-cpp) [![codecov](https://codecov.io/gh/pa28/PiDP-8-sim-cpp/branch/master/graph/badge.svg)](https://codecov.io/gh/pa28/PiDP-8-sim-cpp)

Definitely not ready for prime-time, this project is under heavy development
and may change or stop working without notice. Not much is working at the
moment anyway, but you are welcome to poke around and try things out if
you are brave and have lots of time.

## Prerequisites.

### Antlr4 and Antlr4 C++ Runtime for C++17 Google Test

Most of the prerequisites are included as submodules of this repository,
but you will need `pthreads` installed for Google Test and the multi-threaded
parts of the program.

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

## Continuous Integration

I'm not a fan of continuous integration (CI) per-se. But there is one feature of CI
that I believe is essential for any project that may be used by more than one person;
that is building from scratch -- and testing -- on a previously unconfigured system.
This helps prevent problems that arise when the prerequisites are not fully documented.
For this project I am using [Travis CI](https://travis-ci.org). Travis CI integrates
nicely with GitHub.

## Code Coverage

I am using a test driven design methodology on this project. This methodology suffers
without a clear understanding of the code coverage those tests are achieving. For code
coverage analysis I am using [Codecov.io](https://codecov.io) which also integrates
nicely with GitHub and Travis CI.

## Change Log

See the [change log](CHANGELOG.md).

## Resources

* [The Digital Equipment Corporation PDP-8](https://homepage.divms.uiowa.edu/~jones/pdp8/) by [Douglas W. Jones](https://homepage.divms.uiowa.edu/~jones/)
    * [A Programmer's Reference Manual](https://homepage.divms.uiowa.edu/~jones/pdp8/man/)
* [Highgate's PDP-8 Page](http://highgate.comm.sfu.ca/pdp8/)
    