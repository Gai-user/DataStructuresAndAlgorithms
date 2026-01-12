include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

set(TEST_SOURCES GraphTest.cpp)
add_executable(dataStructure ${TEST_SOURCES})

target_link_libraries(dataStructure
                      DataAndAlgorithm
                      GTest::gtest_main)
gtest_discover_tests(dataStructure)