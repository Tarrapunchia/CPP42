#include "Data.hpp"

Data::Data()
: flag(0), name(""){};

Data::Data(int _flag, const std::string & _str)
:flag(_flag), name(_str) {};

Data::Data(const Data &other) {
    if (&other == this) return ;

    flag = other.flag;
    name = other.name;
};

Data &Data::operator=(const Data & other)
{
    if (&other == this) return *this;

    flag = other.flag;
    name = other.name;

    return *this;
}

Data::~Data()
{
};
