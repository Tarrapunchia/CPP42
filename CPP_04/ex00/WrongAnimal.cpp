#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "\033[1;34m[DEBUG]: WrongAnimal default constructor called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ): type(type)
{
    std::cout << "\033[1;34m[DEBUG]: WrongAnimal constructor called with type\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ): type(other.type)
{
    std::cout << "\033[1;34m[DEBUG]: WrongAnimal copy constructor called\033[0m" << std::endl;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal& e )
{
    std::cout << "\033[1;34m[DEBUG]: WrongAnimal op = override\033[0m" << std::endl;
    if (this != &e)
        type = e.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\033[1;34m[DEBUG]: WrongAnimal destructor called\033[0m" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Generic WrongAnimal Sound, like \"Blirgh\"" << std::endl;
}

std::string WrongAnimal::getType( void ) const { return type; }