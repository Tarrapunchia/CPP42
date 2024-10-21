#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "\033[1;34m[DEBUG]: Animal default constructor called\033[0m" << std::endl;
}

Animal::Animal( std::string type ): type(type)
{
    std::cout << "\033[1;34m[DEBUG]: Animal constructor called with type\033[0m" << std::endl;
}

Animal::Animal( const Animal& other ): type(other.type)
{
    std::cout << "\033[1;34m[DEBUG]: Animal copy constructor called\033[0m" << std::endl;
}

Animal &Animal::operator=( const Animal& e )
{
    std::cout << "\033[1;34m[DEBUG]: Animal op = override\033[0m" << std::endl;
    if (this != &e)
        type = e.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "\033[1;34m[DEBUG]: Animal destructor called\033[0m" << std::endl;
}

void Animal::makeSound(void) const
{
    std::cout << "Generic Animal Sound, like \"Blargh\"" << std::endl;
}

std::string Animal::getType( void ) const { return type; }