#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

#include <vector>

class Dynamic
{
public:
    Dynamic();
    ~Dynamic();

    int Knapsack(const std::vector<int>& weight, const std::vector<int>& value, int capacity);

private:
    std::vector<int> maxValue; // 背包问题，不同容量背包的最大价值
};




#endif // DYNAMIC_PROGRAMMING_H