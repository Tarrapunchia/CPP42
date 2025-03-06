#include "Cure.hpp"

Cure::Cure( void ): AMateria("cure") {}

Cure::Cure( const Cure& other): AMateria(other) {}

Cure& Cure::operator=( const Cure& other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

AMateria* Cure::clone( void ) const { return (new Cure()); }

void Cure::use( ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure( void ) {}
