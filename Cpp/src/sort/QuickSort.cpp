#include <iostream>
#include <vector>
#include "../../utils/Tools.h"

template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int Partition(std::vector<T>& array, int start, int end)
{
    T pivot = array[end];
    int i = start;
    for (int j = start; j < end; ++j) {
        if (array[j] < pivot) {
            Swap(array[i], array[j]);
            i += 1;
        }
    }
    Swap(array[i], array[end]);
    return i;
}

template <typename T>
void QuickSort(std::vector<T>& array, int start, int end)
{
    if (start >= end) {
        return;
    }

    int p = Partition(array, start, end);

    QuickSort(array, start, p-1);
    QuickSort(array, p + 1, end);
}

int main() {
    
    std::vector<int> array = {8, 4, 1, 5, 2, 9, 3, 7, 6};
    QuickSort(array, 0, array.size() - 1);
    PrintVector(array);
    
    return 0;
    
    return 0;
}