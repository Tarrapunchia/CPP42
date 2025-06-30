#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>

bool is_less_than_zero(const std::string & value) {return ((std::atoi(value.c_str())) < 0);}

PmergeMe::PmergeMe(const std::vector<int> values)
: _unorderedValues(values)
{
}

std::vector<int> PmergeMe::mergeInsertion(const std::vector<int> & _unorderedValues)
{
    size_t size = _unorderedValues.size();
    if (size < 2) _orderedValues.push_back(_unorderedValues[0]); return _orderedValues;

    std::vector<int> maxVec;
    std::vector<int> minVec;
    maxVec.reserve(size / 2);
    minVec.reserve(size / 2);
    std::vector<int> mainChain;

for (std::size_t i = 0; i + 1 < size; i += 2) {
        int a = _unorderedValues[i];
        int b = _unorderedValues[i + 1];
        if (a < b) {
            minVec.push_back(a);
            maxVec.push_back(b);
        } else {
            minVec.push_back(b);
            maxVec.push_back(a);
        }
    }

    mainChain = mergeInsertion(maxVec);

    // Jacobsthal index
    // per i min
    int m = static_cast<int>(minVec.size());  // numero di "losers"
    std::vector<int> J;
    J.reserve(10);
    J.push_back(0);
    J.push_back(1);
    // Genera J(k) finché < m
    while (true) {
        int sz = static_cast<int>(J.size());
        int next = J[sz-1] + 2 * J[sz-2];
        if (next >= m) break;
        J.push_back(next);
    }

    // Raccogliamo in jIdx tutti i J(k) a partire da k=2
    std::vector<int> jIdx;
    for (std::size_t k = 2; k < J.size(); ++k) {
        jIdx.push_back(J[k]);
    }
    // Assicuriamoci che l'ultimo indice sia m
    if (jIdx.empty() || jIdx.back() != m) {
        jIdx.push_back(m);
    }

    // --- 4) Reinserisci i "losers" uno a uno nell'ordine jIdx ---
    for (std::size_t t = 0; t < jIdx.size(); ++t) {
        int idx = jIdx[t];           // indice 1-based
        int value = minVec[idx-1];   // prendo il "loser" corrispondente
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(it, value);
    }

    // --- 5) Reinserisci l'elemento _unorderedValues[size - 1] se presente ---
    if (size % 2 != 0) {
        std::vector<int>::iterator it =
            std::lower_bound(mainChain.begin(), mainChain.end(), _unorderedValues[size - 1]);
        mainChain.insert(it, _unorderedValues[size - 1]);
    }

    return mainChain;
}

PmergeMe::~PmergeMe()
{
}