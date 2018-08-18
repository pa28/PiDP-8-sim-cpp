# PiDP-8 Simulator in C++17 [![Build Status](https://travis-ci.org/pa28/PiDP-8-sim-cpp.svg?branch=master)](https://travis-ci.org/pa28/PiDP-8-sim-cpp)

Definitely not ready for prime-time, this project is under heavy development
and may change or stop working without notice. Not much is working at the
moment anyway, but you are welcome to poke around and try things out if
you are brave and have lots of time.

## Prerequisites.

### Antlr4 and Antlr4 C++ Runtime for C++17 Google Test

```
sudo apt-get install pkg-config uuid-dev
```
  

Get antlr 4.7 complete JAR:
```
curl -O https://www.antlr.org/download/antlr-4.7-complete.jar
```

and move it to a standard location. I used `/usr/local/lib` but you can use
a different location and update the `CMakeLists.txt` file.
