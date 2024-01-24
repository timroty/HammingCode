cmake_minimum_required(VERSION 3.10)
project(HammingCode)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the main executable
add_executable(HammingCode
  src/main.cpp
  src/constants.cpp
  src/verification.cpp
  src/file.cpp
)

# Include directories for headers
target_include_directories(HammingCode PRIVATE
  src/include
)
