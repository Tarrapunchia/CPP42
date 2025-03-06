#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    type = "default";
    std::cout << "\033[1;34m[DEBUG]: Animal default constructor called\033[0m" << std::endl;
}

AAnimal::AAnimal( const AAnimal& other ): type(other.type)
{
    std::cout << "\033[1;34m[DEBUG]: Animal copy constructor called\033[0m" << std::endl;
}

AAnimal &AAnimal::operator=( const AAnimal& e )
{
    std::cout << "\033[1;34m[DEBUG]: Animal op = override\033[0m" << std::endl;
    if (this != &e)
        type = e.type;
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "\033[1;34m[DEBUG]: Animal destructor called\033[0m" << std::endl;
}

void AAnimal::makeSound(void) const
{
    std::cout << "Generic Animal Sound, like \"Blargh\"" << std::endl;
}

std::string AAnimal::getType( void ) const { return type; }