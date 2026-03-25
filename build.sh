#!/bin/bash

g++ main.cpp glad.c shader.cpp stb_image_impl.cpp -Iinclude -lglfw -lGL -ldl -o sim
./sim
