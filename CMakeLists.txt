cmake_minimum_required(VERSION 3.10)
project(MyHammingProject)

add_executable(HammingCode src/main.cpp src/Verification/Verification.cpp)
target_include_directories(HammingCode PRIVATE src/Verification)
