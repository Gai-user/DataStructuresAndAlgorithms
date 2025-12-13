# 指定 CMake 最低版本
cmake_minimum_required(VERSION 3.30)

# 项目名称和语言
project(CppDataStructure LANGUAGES  CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/sort)
add_subdirectory(src/BinarySearch)
add_subdirectory(src/BinaryTree)
