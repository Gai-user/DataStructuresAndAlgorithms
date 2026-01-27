#include <gtest/gtest.h>
#include <vector>

#include "../src/BackTrack/BackTrack.h"

TEST(BackTrackTest, EightQueensTest) 
{
    std::vector<std::vector<int>> result;
    BackTrack bt;
    bt.EightQueens(0, result);
    EXPECT_EQ(result.size(), 92);
}

TEST(BackTrackTest, LevenshteinDistanceTest)
{
    BackTrack bt;
    int result = bt.LevenshteinDistance("mitcmu", "mtacnu");
    EXPECT_EQ(result, 3);
}