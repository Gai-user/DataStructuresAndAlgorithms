#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "../src/DynamicProgramming/Dynamic.h"

TEST(DynamicTest, LevenshteinDistanceTest)
{
    Dynamic DP;

    int result = DP.LevenshteinDistance("horse", "ros");
    EXPECT_EQ(result, 3);
}

TEST(DynamicTest, LongestCommonSubStringLengthTest)
{
    Dynamic DP;

    int result1 = DP.LongestCommonSubStringLength("ace", "abcde");
    EXPECT_EQ(result1, 3);

    int result2 = DP.LongestCommonSubStringLength("abc", "abc");
    EXPECT_EQ(result2, 3);

    int result3 = DP.LongestCommonSubStringLength("abc", "def");
    EXPECT_EQ(result3, 0);
}