#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <stdexcept>
template <typename T>
class Array
{
public:
    Array()
    : _array(NULL), _size(0) {}

    Array(unsigned int n)
    : _array(new T[n]), _size(n) {}

    Array(const Array & other)
    : _array(NULL), _size(other.size()) {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }

    Array &operator=(const Array & other) {
        if (this == &other) return *this;
        delete[] _array;

        _size = other.size();
        _array = new T[_size];

        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
        return *this;
    }

    ~Array() {
        delete[] _array;
    }

    unsigned int size() const {
        return _size;
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Out of range operation");
        return _array[index];
    }

    T& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(_size))
            throw std::out_of_range("Out of range operation");
        return _array[index];
    }

    private:
    T* _array;
    unsigned int _size;

};

#endif