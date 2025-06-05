#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <stdexcept>

#include <algorithm>
template <typename C>
typename C::iterator easyfind(C& container, int value)
{
    typename C::iterator ret = std::find(container.begin(), container.end(), value);
    if (ret == container.end())
        throw std::invalid_argument("Value not found.");
    return ret;
}

#endif