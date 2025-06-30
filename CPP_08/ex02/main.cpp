#include "MutantStack.hpp"
#include <deque>
#include <iostream>

int main()
{
	std::cout << "\033[33m" << "[Test Mutant Stack]\n"<< "\033[0m";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\033[33m" << "[Test Deque]\n"<< "\033[0m";
    std::deque<int> deq;
    deq.push_back(5);
    deq.push_back(17);
    std::cout << deq.back() << std::endl;
    deq.pop_back();
    std::cout << deq.size() << std::endl;
    deq.push_back(3);
    deq.push_back(5);
    deq.push_back(737);
    deq.push_back(0);
    std::deque<int>::iterator itd = mstack.begin();
    std::deque<int>::iterator ited = mstack.end();
    ++itd;
    --itd;
    while (itd != ited)
    {
        std::cout << *itd << std::endl;
        ++itd;
    }
    return 0;
}