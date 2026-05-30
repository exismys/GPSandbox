#!/bin/bash

# Create a build directory to keep source files clean
mkdir -p build

# Navigate into the build directory
cd build

# Run CMake to generate build files (Makefiles) from CMakeLists.txt
cmake ..

# Compile the project using make with parallel jobs for faster builds
make -j$(nproc)

# Navigate back to project root and run the executable
cd ..
./build/bin/sim
