#include <vector>
#include <iostream>
#include "MergeSort.h"

template <typename T>
void Print(const std::vector<T> array) {
    for (const auto& number:array) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Merge(std::vector<T>& array, int start, int mid, int end)
{
    std::vector<T> tmp;
    tmp.reserve(end-start+1);

    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (array[i] <= array[j]) {
            tmp.push_back(array[i]);
            i += 1;
        } else {
            tmp.push_back(array[j]);
            j += 1;
        }
    }

    while (i <= mid)
    {
        tmp.push_back(array[i]);
        i += 1;
    }

    while (j <= end)
    {
        tmp.push_back(array[j]);
        j += 1;
    }

    for (int k = 0; k < tmp.size(); ++k) {
        array[start+k] = tmp[k];
    }
    
}


template <typename T>
void MergeSort(std::vector<T>& array, int start, int end)
{
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    MergeSort(array, start, mid);
    MergeSort(array, mid + 1, end);
    // 这里我一开始用的是原地交换，大致思路如下：
    // 1. i = start, j = mid+1
    // 2. array[i] > array[j], swap(array[i], array[j])
    // 这里有个问题，交换后的两部分之间，可能就无序了
    // 1， 2， 5 与 3， 4， 6  交换后
    // 1， 2， 3 与 5， 4， 6
    Merge(array, start, mid, end);
    Print(array);
}

int main() {
    
    std::vector<int> array = {8, 4, 1, 5, 2, 9, 3, 7, 6};
    MergeSort(array, 0, array.size() - 1);
    Print(array);
    
    return 0;
}