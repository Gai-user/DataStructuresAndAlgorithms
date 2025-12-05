# CMake

## cmake 中的路径

1. CMAKE_SOURCE_DIR

包含最顶层的CMakeLists.txt 的目录，在本代码仓中为：E:/DataStructuresAndAlgorithms/DataStructuresAndAlgorithms/Cpp

2. CMAKE_CURRENT_SOURCE_DIR

当前正在处理的 CMakeLists.txt 所在的源码目录

3. CMAKE_CURRENT_BINARY_DIR

当前正在处理的 CMakeLists.txt 对应的构建目录 (通常与 CMAKE_BINARY_DIR 不同，当有子目录)

4. PROJECT_SOURCE_DIR

当前 project() 命令所在项目的源码根目录（多数情况下等于 CMAKE_SOURCE_DIR，除非有嵌套项目）

5. PROJECT_BINARY_DIR

当前项目的构建目录（多数情况下等于 CMAKE_BINARY_DIR）

6. CMAKE_BINARY_DIR

在项目外创建 build/ 目录并运行 cmake ..，那么 CMAKE_BINARY_DIR 就是这个 build/ 的绝对路径