#!/bin/bash

g++ main.cpp glad.c -Iinclude -lglfw -lGL -ldl -o sim
./sim
