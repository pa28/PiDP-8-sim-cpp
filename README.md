# PiDP-8 Simulator in C++17 [![Build Status](https://travis-ci.org/pa28/PiDP-8-sim-cpp.svg?branch=master)](https://travis-ci.org/pa28/PiDP-8-sim-cpp)

Definitely not ready for prime-time, this project is under heavy development
and may change or stop working without notice. Not much is working at the
moment anyway, but you are welcome to poke around and try things out if
you are brave and have lots of time.

## Prerequisites.

### Antlr4 and Antlr4 C++ Runtime for C++17 Google Test

```
sudo apt-get install pkg-config uuid-dev libgtest-dev
```
  

Get antlr 4.7 complete JAR:
```
curl -O https://www.antlr.org/download/antlr-4.7-complete.jar
```

and move it to a standard location. I used `/usr/local/lib` but you can use
a different location and update the `CMakeLists.txt` file.

For now you will have to use my forked branch of the antlr4 repository to get
and compile the C++ runtime with C++17 support. Antlr4 C++ runtime 
currently only supports C++11.

  https://github.com/pa28/antlr4/tree/c++17-support

Make sure you check out the `c++17-support` branch. The C++ runtime is in `runtime/cpp`. Follow the instructions in the readme to
build it. Don't build the demo. If you want to see the demo, use the `master` branch.

