#!/bin/sh

g++ -std=c++17 menu_example.cpp  ../src/Menu/Menu.cpp $1 &&
    ./a.out
