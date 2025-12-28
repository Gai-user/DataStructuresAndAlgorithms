#include <vector>
#include <iostream>

template <typename T>
void PrintVector(const std::vector<T> array);

template <typename T>
void PrintVector(const std::vector<T> array) 
{
    for (const auto& number:array) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}