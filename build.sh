#!/bin/bash

g++ main.cpp glad.c shader.cpp -Iinclude -lglfw -lGL -ldl -o sim
./sim
