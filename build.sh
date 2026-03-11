#!/bin/bash

g++ main.cpp -o sim -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./sim
