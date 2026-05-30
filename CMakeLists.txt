# Specify the minimum CMake version required for this project
cmake_minimum_required(VERSION 3.14)

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

# Fetch third-party header-only libraries
include(FetchContent)

FetchContent_Declare(glm
  URL https://github.com/g-truc/glm/releases/download/0.9.9.8/glm-0.9.9.8.zip
  SOURCE_DIR ${CMAKE_BINARY_DIR}/_deps/glm-src
)

FetchContent_Declare(stb_image
  URL https://github.com/nothings/stb/archive/refs/heads/master.zip
  SOURCE_DIR ${CMAKE_BINARY_DIR}/_deps/stb-src
)

FetchContent_Declare(khronos_headers
  URL https://github.com/KhronosGroup/EGL-Registry/archive/refs/heads/main.zip
  SOURCE_DIR ${CMAKE_BINARY_DIR}/_deps/khronos-src
)

FetchContent_MakeAvailable(glm stb_image khronos_headers)

# List all source files that need to be compiled into the executable
set(SOURCES
    src/main.cpp
    src/glad.c
    src/shader.cpp
    src/stb_image_impl.cpp
)

# Create the executable target named "sim" from the specified source files
add_executable(sim ${SOURCES})

# Link the required system libraries to the executable
target_link_libraries(sim
    ${GLFW_LIBRARIES}
    ${GL_LIBRARIES}
    dl
)

# Include the directories that contain headers for the linked libraries and fetched dependencies
target_include_directories(sim PRIVATE
    include
    ${GLFW_INCLUDE_DIRS}
    ${GL_INCLUDE_DIRS}
    ${CMAKE_BINARY_DIR}/_deps/glm-src
    ${CMAKE_BINARY_DIR}/_deps/stb-src
    ${CMAKE_BINARY_DIR}/_deps/khronos-src/api/EGL
)
