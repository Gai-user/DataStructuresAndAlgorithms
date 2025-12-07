set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/output/sorts)
# 检查 OUTPUT_DIR 这个目录在不在，不在的话，创建这个目录
# cmake不会自动创建目录
file(MAKE_DIRECTORY ${OUTPUT_DIR})
message(STATUS "SOURCE DIR ${CMAKE_SOURCE_DIR}")
message(STATUS "CURRENT SOURCE DIR ${CMAKE_CURRENT_SOURCE_DIR}")

# file() 是CMake中用于操作文件和目录的命令
# GLOB 是 file 的一个子命令，用来匹配符合模式的文件路径
# SORT_SOURCES 找到的文件会存在这个变量中
# LIST_DIRECTORIES false 只返回文件，不返回目录。
# RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 指定返回的路径是相对于哪个目录的相对路径
# *.cpp 表示匹配当前目录下所有以 .cpp 结尾的文件。
file(GLOB SORT_SOURCES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")
foreach(source_file IN LISTS SORT_SOURCES)
    get_filename_component(targe_name ${source_file} NAME_WE)
    add_executable(${targe_name} ${source_file})
    set_target_properties(${targe_name} PROPERTIES
                          RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
endforeach()