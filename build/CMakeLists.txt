cmake_minimum_required(VERSION 3.10)
project(HammingCode)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HammingCode
  ../src/main.cpp
  ../src/constants.cpp
  ../src/verification.cpp
  ../src/file.cpp
  ../src/hammingCode.cpp
)

target_include_directories(HammingCode PRIVATE
  ../src/include
)
