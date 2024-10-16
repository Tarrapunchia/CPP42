#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType( void ) const
{
    const std::string &reference = _type;
    return reference;
}

void Weapon::setType( std::string type ) { _type = type; }
