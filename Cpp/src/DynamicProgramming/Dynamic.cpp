#include <vector>
#include <algorithm>
#include <stdexcept> 
#include <string>
#include <algorithm>
#include "Dynamic.h"

Dynamic::Dynamic() {}

Dynamic::~Dynamic() {}

/**
 * 一组不同重量、不可分割的物品, 在满足背包最大重量限制的前提下，背包中物品总重量的最大值
 * @param weight     物品重量
 * @param value      物品价值
 * @param capacity   背包容量
 */

int Dynamic::Knapsack(const std::vector<int>& weight, const std::vector<int>& value, int capacity)
{
    if (weight.size() != value.size()) {
        throw std::invalid_argument("The lengths of these two vectors are not the same.");
    }

    if (capacity < 0) {
        throw std::invalid_argument("The capacity of the bag must be positive!");
    }

    maxValue.reserve(capacity + 1);

    for (size_t j = 0; j < weight.size(); ++j) {
        for (size_t cap = capacity; cap > 0; --cap) {
            if (cap >= weight[j]) {
                maxValue[cap] = std::max(maxValue[cap], maxValue[cap - weight[j]] + value[j]);
            }
        }
    }
    return maxValue[capacity];
}

/**
 * 使用动态规划求解最小编辑距离问题
 * 最小编辑距离：给定两个单词，经过删除、添加、替换单词中的元素，使得两个单词相同，求最小的操作次数。
 * @param word1 
 * @param word2
 */
int Dynamic::LevenshteinDistance(const std::string& word1, const std::string& word2)
{
    int lengthWord1 = word1.size();
    int lengthWord2 = word2.size();
    
    // minDist[i][j] 代表以word1[i - 1], word2[j - 1]结尾的单词的最小编辑距离
    // 其中 minDist[0][0] 表示两个空字符串的最小编辑距离 -> 0
    // 这样设置的目的，是为了初始化minDist方便，更容易理解
    std::vector<std::vector<int>> minDist(lengthWord1 + 1, std::vector<int>(lengthWord2 + 1, 0));

    // 初始化minDist
    // minDist[0][j] -> 将以word[j]结尾的单词，转换为空字符串的最小编辑距离，删除j个单词，所以 minDist[0][j] = j
    for (int j = 0; j <= lengthWord2; ++j) { minDist[0][j] = j; }
    // 同理， minDist[i][0] = i
    for (int i = 0; i <= lengthWord1; ++i) { minDist[i][0] = i; }

    // 状态转移方程
    // word1[i - 1] == word2[j - 1], 不需要操作，minDist[i][j] = minDist[i - 1][j - 1]
    // word1[i - 1] != word2[j - 1], minDist[i][j] = min(minDist[i - 1][j - 1], minDist[i][j - 1], minDist[i - 1][j]) + 1
    // word1[i - 1] != word2[j - 1]时，minDist[i - 1][j - 1] -> 替换单词， 
    // minDist[i][j - 1] -> 在 word1 末尾插入 word2[j-1]（使 word1 匹配到 j）
    //                                                             
    for (int i = 1; i <= lengthWord1; i++) {
        for (int j = 1; j <= lengthWord2; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                minDist[i][j] = minDist[i - 1][j - 1];
            } else {
                minDist[i][j] = std::min({minDist[i - 1][j - 1], minDist[i][j - 1], minDist[i - 1][j]}) + 1;
            }
        }
    }
    return minDist[lengthWord1][lengthWord2];
}