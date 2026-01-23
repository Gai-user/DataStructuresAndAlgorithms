#include <vector>
#include <algorithm>
#include <stdexcept> 
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