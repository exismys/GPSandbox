# Specify the minimum CMake version required for this project
cmake_minimum_required(VERSION 3.10)

# Define the project name and set the C++ standard
project(GPSandbox)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build output directories to keep build artifacts organized
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find required system packages using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW glfw3)
pkg_check_modules(GL gl)

# Add the include directory to the search path for headers
include_directories(include)

# List all source files that need to be compiled into the executable
set(SOURCES
    main.cpp
    glad.c
    shader.cpp
    stb_image_impl.cpp
)

# Create the executable target named "sim" from the specified source files
add_executable(sim ${SOURCES})

# Link the required system libraries to the executable
target_link_libraries(sim
    ${GLFW_LIBRARIES}
    ${GL_LIBRARIES}
    dl
)

# Include the directories that contain headers for the linked libraries
target_include_directories(sim PRIVATE
    ${GLFW_INCLUDE_DIRS}
    ${GL_INCLUDE_DIRS}
)
