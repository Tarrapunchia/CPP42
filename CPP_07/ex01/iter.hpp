#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename A, typename F>
void iter(A arr, unsigned len, F fn)
{
    for (unsigned i = 0; i < len; i++) {
        fn(arr[i]);
    }
}

template <typename T>
void print(const T& elem)
{
    std::cout << elem << " " ;
}

#endif