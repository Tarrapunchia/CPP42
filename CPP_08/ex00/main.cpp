#include "easyfind.hpp"
#include <algorithm>
#include <array>
#include <vector>
#include <iostream>

int main(int argc, const char** argv) {
    try
    {
        std::vector<int> vec(10, 7);
        std::cout << "Searching in vector with 10 elements of value 7 the nb 7" << std::endl;
        std::cout << *(::easyfind(vec, 7)) << std::endl;

        std::array<int, 10> arr;
        std::copy(vec.begin(), vec.end(), arr.begin());
        std::cout << "Searching in array with 10 elements of value 7 the nb 7" << std::endl;
        std::cout << *(::easyfind(arr, 7)) << std::endl;
        
        std::cout << "Searching in vector with 10 elements of value 7 the nb 3" << std::endl;
        std::cout << *(::easyfind(vec, 3)) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
        
    return 0;
}