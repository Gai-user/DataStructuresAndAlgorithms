#include <iostream>
#include "Heap.h"
#include "../../utils/Tools.h"

Heap::Heap(int cap) {
    capacity = cap;
    count = 0;
    array.reserve(capacity);
}

Heap::~Heap() {}

// 这里创建一个大顶堆
void Heap::insert(int data) {
    if (count >= capacity) {
        std::cout << "The heap has reached its capacity and cannot accept additional elements" << std::endl;
    }
    ++count;
    array[count] = data;
    int i = count
    while (i / 2 > 0 && array[i] > array[i / 2])
    {
        Swap(array[i], array[i / 2]);
    }
}

void Heap::remove()
{
    if (count == 0) {
        return;
    }
    array[1] == array[count];
    --count;
    
    int i = 1;
    while (true)
    {
        int maxPos = i;
        if (i*2 <= capacity && array[i] < array[i*2]) {
            maxPos = i*2;
        }

        if (i*2+1 <= capacity && array[i] < array[i*2+1]) {
            maxPos = i*2+1; 
        }

        if (i == maxPos) {
            break;
        }

        Swap(array[i], array[maxPos]);
        i = maxPos;
    }
    
}