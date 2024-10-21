#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
    std::cout << "\033[1;34m[DEBUG]: WrongCat default constructor called\033[0m" << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ): WrongAnimal(other)
{
    std::cout << "\033[1;34m[DEBUG]: WrongCat copy constructor called\033[0m" << std::endl;
}

WrongCat &WrongCat::operator=( const WrongCat& e )
{
    std::cout << "\033[1;34m[DEBUG]: WrongCat op = overload called\033[0m" << std::endl;
    if (this != &e)
        type = e.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "\033[1;34m[DEBUG]: WrongCat destructor called\033[0m" << std::endl;
}

