#!/bin/sh

g++ -std=c++17 $1.cpp -o $1.o && ./$1.o
