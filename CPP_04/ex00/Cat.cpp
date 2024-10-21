#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << "\033[1;34m[DEBUG]: Cat default constructor called\033[0m" << std::endl;
}

Cat::Cat( const Cat& other ): Animal(other)
{
    std::cout << "\033[1;34m[DEBUG]: Cat copy constructor called\033[0m" << std::endl;
}

Cat &Cat::operator=( const Cat& e )
{
    std::cout << "\033[1;34m[DEBUG]: Cat op = overload called\033[0m" << std::endl;
    if (this != &e)
        type = e.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "\033[1;34m[DEBUG]: Cat destructor called\033[0m" << std::endl;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Meow" << std::endl;
}
