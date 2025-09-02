cmake_minimum_required(VERSION 3.28) # Maximum CMake version

project(MathLibProject VERSION 1.0 LANGUAGES CXX) # Project name and version

set(CMAKE_CXX_STANDARD 11) # Use C++11
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(MathApp src/main.cpp src/math_functions.cpp)

# Include directories
target_include_directories(MathApp PUBLIC include)