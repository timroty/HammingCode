cmake_minimum_required(VERSION 3.10)
project(HammingCodeTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HammingCodeTests
  ../main.cpp
  ../../src/verification.cpp
  ../../src/constants.cpp
  ../../src/hammingCode.cpp
)

target_include_directories(HammingCodeTests PRIVATE
  ../../src/include
)
