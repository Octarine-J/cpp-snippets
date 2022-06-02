#!/bin/bash

# -c to skip linking phase (it would fail as there is no main)
g++ -c foo.cpp bar.cpp

# create a library from object files
ar crv libmy.a foo.o bar.o
# create table of contents
ranlib libmy.a

# build the app and link it against the library 
g++ -o app app.cpp -L. -lmy

# option 2:
# g++ -o app app.cpp libmy.a
