# C++ Snippets
Mini-Examples of C++ Syntax and its Standard Library

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
./configure --prefix=/usr/local/name-version
make
make install
```

To run an executable built against a third-party library:
```
LD_LIBRARY_PATH=/usr/local/name-version/lib/ exe-name
```

## Repository Setup

```
git submodule add git@github.com:google/googletest.git
git submodule init
git submodule update
```

