set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/output/BinarySearch)
file(MAKE_DIRECTORY ${OUTPUT_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
add_executable(BinarySearch BinarySearch.cpp)