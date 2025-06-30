#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <iostream>

class PmergeMe
{
public:
    PmergeMe() = delete;
    PmergeMe(const std::vector<int> values);
    PmergeMe(const PmergeMe &) = default;
    PmergeMe &operator=(const PmergeMe &) = default;
    ~PmergeMe();

    std::vector<int> mergeInsertion(const std::vector<int> & _unorderedValues);

private:
    std::vector<int>            _unorderedValues;
    std::vector<int>            _orderedValues;
};


#endif