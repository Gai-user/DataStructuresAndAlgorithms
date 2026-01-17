set(SRC_FILE Graph/Graph.cpp
             BackTrack/BackTrack.cpp)

add_library(DataAndAlgorithm STATIC ${SRC_FILE})

install(TARGETS DataAndAlgorithm
        ARCHIVE DESTINATION lib) 