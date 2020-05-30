# C++ Snippets
Mini-Examples of C++ Syntax and its Standard Library


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

## Game Engines
- Godot: https://godotengine.org/download
- LibGDX: https://libgdx.badlogicgames.com/
