# A simple demo of Google Test.

To compile googletest without CMake:
```
cd /pathto/googletest/googletest
mkdir build && cd build
g++ -I /pathto/googletest/googletest/include/ -I /pathto/googletest/googletest/ -pthread -c /pathto/googletest/googletest/src/gtest-all.cc
ar -rv libgtest.a gtest-all.o
mkdir ../lib && mv libgtest.a ../lib
```
