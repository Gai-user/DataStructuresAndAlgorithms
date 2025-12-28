#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap 
{
public:
    Heap() = default;
    Heap(int cap);
    ~Heap();
    void insert(int data);
    void remove(); // 删除堆顶元素
private:
    std::vector<int> array; // 存储堆的数组，使用数组表示完全二叉树
    int capacity;           // 数组容量
    int count;              // 当前数组中元素个数
    
};

#endif // HEAP_H