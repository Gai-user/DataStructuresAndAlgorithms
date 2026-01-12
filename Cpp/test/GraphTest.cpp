#include <gtest/gtest.h>
#include <vector>

#include "../src/Graph/Graph.h"


class GraphTest : public ::testing::Test
{
protected:
    void SetUp() override {
        g = Graph(5);
        g.AddEdge(0, 1);
        g.AddEdge(1, 2);
        g.AddEdge(0, 3);
        g.AddEdge(1, 4);
        g.AddEdge(3, 4);
    }

    Graph g;
};

TEST_F(GraphTest, BreadthFirstSearch)
{
    const auto& path = g.BreadthFirstSearch(0, 4);
    ASSERT_FALSE(path.empty());
    EXPECT_EQ(path, std::vector<int>({0, 1, 4}));
}

TEST_F(GraphTest, DepthFirstSearchTest)
{
    const auto& path = g.DepthFirstSearch(0, 4);
    ASSERT_FALSE(path.empty());
    EXPECT_EQ(path, std::vector<int>({0, 3, 4}));
}