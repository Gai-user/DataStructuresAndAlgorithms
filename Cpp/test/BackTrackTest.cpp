#include <gtest/gtest.h>
#include <vector>

#include "../src/BackTrack/BackTrack.h"

TEST(BackTrackTest, EightQueensTest) {
    std::vector<std::vector<int>> result;
    BackTrack bt;
    bt.EightQueens(0, result);
    EXPECT_EQ(result.size(), 92);
}