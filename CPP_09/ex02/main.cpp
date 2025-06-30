#include "PmergeMe.hpp"
#include <vector>

int main(int argc, const char** argv) {

    std::vector<int> unorderedValues;
    if (argc < 2) throw std::logic_error("No values submitted.");
    for (size_t i = 1; i < argc; i++)
    {
        unorderedValues.push_back(std::atoi(argv[i]));
        if (unorderedValues.back() < 0)
            throw std::out_of_range("No values less than 0 are allowed");
    }
    PmergeMe pmerge(unorderedValues);
    for (auto el : unorderedValues) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    for (auto el : pmerge.mergeInsertion(unorderedValues)) {
        std::cout << el << " ";
    }
    std::cout << std::endl;


    return 0;
}