#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data {
    Data();
    Data(int _flag, const std::string & _str)
    :flag(_flag), name(_str) {}
    int flag;
    std::string name;
};

class Serializer
{
public:
    Serializer() = delete;
    Serializer(const Serializer &) = delete;
    Serializer &operator=(const Serializer &) = delete;
    ~Serializer() = delete;

    static uintptr_t serialize (Data *ptr);
    static Data* deserialize(uintptr_t raw);

private:
    
};
#endif