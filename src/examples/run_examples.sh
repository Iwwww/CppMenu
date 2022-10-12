#!/bin/sh

g++ -std=c++17 menu_example.cpp  ../Menu/Menu.cpp $1 &&
    ./a.out
