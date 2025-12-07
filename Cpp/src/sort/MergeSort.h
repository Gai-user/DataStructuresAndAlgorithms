#include <vector>

template <typename T>
void Print(const std::vector<T> array);

template <typename T>
void Merge(std::vector<T>& array, int start, int mid, int end);

template <typename T>
void MergeSort(std::vector<T>& array, int start, int end);