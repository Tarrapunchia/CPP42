#include "Dog.hpp"

Dog::Dog(): Animal(), _brain(new Brain)
{
    type = "Dog";
    std::cout << "\033[1;34m[DEBUG]: Dog default constructor called\033[0m" << std::endl;
}

Dog::Dog( const Dog& other ): Animal(other)
{
    std::cout << "\033[1;34m[DEBUG]: Dog copy constructor called\033[0m" << std::endl;
}

Dog &Dog::operator=( const Dog& e )
{
    std::cout << "\033[1;34m[DEBUG]: Dog op = overload called\033[0m" << std::endl;
    if (this != &e)
        type = e.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "\033[1;34m[DEBUG]: Dog destructor called\033[0m" << std::endl;
    delete _brain;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Arf" << std::endl;
}
