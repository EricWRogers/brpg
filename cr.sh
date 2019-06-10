#!/bin/bash

mkdir bin
g++ src/*.cpp -llua5.3 -o bin/run
./bin/run
