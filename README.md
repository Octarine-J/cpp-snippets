# C++ Snippets
This repository contains reusable snippets of C++ code to implement various
tasks such as generating random numbers or working with dates.

The repository also serves as a quick reminder for one who has not been working
with C++ for a while.

The most important directory (for now) is `shorts`. The most convenient way to work
with it is to use Visual Studio Code. Each mini-app or a test case there 
can easily be run with the "Code Runner" plugin with the following configuration.

On Windows, using VC++:
```
"code-runner.executorMap": {
  "cpp": "\"C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat\" && cd $dir && cl $fileName /std:c++20 /nologo /EHsc /W4 /Fe:$fileNameWithoutExt.exe && $dir$fileNameWithoutExt.exe && DEL $dir$fileNameWithoutExt.exe && DEL $dir$fileNameWithoutExt.obj"
}
```

On Windows, using mingw:
```
"code-runner.executorMap": {
  "cpp": "g++ -std=c++20 $fullFileName -o $fileNameWithoutExt && $fileNameWithoutExt.exe && DEL $fileNameWithoutExt.exe"
}
```

On Linux, using GCC:
```
"code-runner.executorMap": {
  "cpp": "g++ -lstdc++ --std=c++17 $fullFileName && ./a.out && rm ./a.out"
}
```

# Learning Resources

## Conferences

- [CppCon](https://www.youtube.com/user/CppCon/playlists)
- [C++Now](https://www.youtube.com/user/BoostCon/playlists)
- [ACCU Conference](https://www.youtube.com/channel/UCJhay24LTpO1s4bIZxuIqKw/featured)
- [Microsoft Build *](https://www.youtube.com/channel/UCsMica-v34Irf9KVTh6xx-g/playlists?view=50&sort=dd&shelf_id=16)

## References

- [C++ Reference](https://en.cppreference.com/w/)
- [C++ Standard Draft (Web)](https://eel.is/c++draft/)

## Podcasts

- [C++ Cast](http://cppcast.com/)

## Guidelines

- [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)

## Game Engines
- [Godot](https://godotengine.org/download)
- [LibGDX](https://libgdx.badlogicgames.com/)


# HOWTOs

## How to build a third-party library
```
./configure --prefix=/usr/local/libname-version
make
make install
```

To run an executable built against a third-party library:
```
LD_LIBRARY_PATH=/usr/local/name-version/lib/ exe-name
```

## How to link against a library

Linking against a static `.a` library:
```
g++ source.cpp /path/to/libmy.a
```

Linking against a shared library in a standard location:
```
# against libm.so
g++ source.cpp -lm
```

Linking against a custom shared library:
```
# against libX11.so
g++ source.cpp -L/path/to/libs/ -lX11
```

## New Repository Setup

```
git submodule add https://github.com/google/googletest.git
git submodule init
git submodule update
```
