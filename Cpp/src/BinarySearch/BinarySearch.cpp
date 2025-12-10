#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
int binary_search(std::vector<T>& array, T target)
{
    size_t left = 0;
    size_t right = array.size() - 1;


    while (left <= right)
    {
        size_t mid = left + (right - left) / 2;
        T value = array[mid];
        if (value < target) {
            left = mid + 1;
        } else if (value > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

template <typename T>
int binary_search_recursive(std::vector<T>& array, T target, int left, int right)
{
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    T value = array[mid];

    if (value > target) {
        return binary_search_recursive(array, target, left, mid - 1);
    } else if (value < target) {
        return binary_search_recursive(array, target, mid+1, right);
    } else {
        return mid;
    }
}

// 查找第一个值等于给定值的元素下标
template <typename T>
int binary_search_first_value(std::vector<T>& array, T target)
{
    int left = 0;
    int right = array.size() - 1;

    

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        T value = array[mid];
        if (value > target) {
            right = mid - 1;
        } else if (value < target) {
            left = mid + 1;
        } else {
            if (mid == 0 || array[mid - 1] != target) {
                return mid;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

// 查找最后一个值等于给定值的元素
template <typename T>
int binary_search_end_value(std::vector<T>& array, T target)
{
    int left = 0;
    int right = array.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        T value = array[mid];
        if (value < target)
        {
            left = mid + 1;
        } else if (value > target) {
            right = mid - 1;
        } else {
            if (mid == array.size() -1 || array[mid+1] != target)
            {
                return mid;
            }
            left = mid + 1;
            
        }
        
    }
    return -1;
}

// 查找第一个大于等于给定值的元素
template <typename T>
int binary_search_first_greater(std::vector<T>& array, T target)
{
    int left = 0;
    int right = array.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        T value = array[mid];
        if (value < target)
        {
            left = mid + 1;
        } else {
            if (mid == 0 || array[mid - 1] < target) {
                return mid;
            }
            right = mid + 1;
        }
    }
    return -1;
}

int main() {

    std::vector<double> array = {1.1, 3.4, 4.3, 4.5, 5.6, 7.0};
    auto result = binary_search<double>(array, 4.3);

    std::cout << "The value of result is " << result << std::endl;

    auto result2 = binary_search_recursive(array, 4.5, 0, array.size()-1);

    std::cout << "The value of result2 is " << result2 << std::endl;

    auto result3 = binary_search_recursive(array, 5.4, 0, array.size()-1);

    std::cout << "The value of result3 is " << result3 << std::endl;

    std::vector<int> array1 = {1, 3, 4, 5, 6, 8, 8, 8, 11, 18};
    auto result4 = binary_search_first_value(array1, 8);
    assert(result4 == 5);

    auto result5 = binary_search_end_value(array1, 8);
    assert(result5 == 7);
    
    std::vector<int> array2 = {1, 3, 4, 6, 7, 8, 9, 10};
    auto result6 = binary_search_first_greater(array2, 5);
    assert(result6 == 3);

    return 0;
}