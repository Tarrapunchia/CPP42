#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice( const Ice& other ): AMateria(other) {}

Ice& Ice::operator=( const Ice& other )
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

AMateria* Ice::clone() const { return (new Ice()); }

void Ice::use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice( void ) {}