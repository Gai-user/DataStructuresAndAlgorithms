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