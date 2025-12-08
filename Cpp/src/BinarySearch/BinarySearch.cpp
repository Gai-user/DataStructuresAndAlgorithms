#include <iostream>
#include <vector>

template <typename T>
int binary_search(std::vector<T>& array, T target)
{
    size_t left = 0;
    size_t right = array.size() - 1;

    size_t mid = left + (right - left) / 2;

    while (left <= right)
    {
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


int main() {

    std::vector<double> array = {1.1, 3.4, 4.3, 4.5, 5.6, 7.0};
    auto result = binary_search<double>(array, 4.3);

    std::cout << "The value of result is " << result << std::endl;

    auto result2 = binary_search_recursive(array, 4.5, 0, array.size()-1);

    std::cout << "The value of result2 is " << result2 << std::endl;

    auto result3 = binary_search_recursive(array, 5.4, 0, array.size()-1);

    std::cout << "The value of result3 is " << result3 << std::endl;

    return 0;
}