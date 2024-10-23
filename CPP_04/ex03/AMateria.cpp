#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "\033[1;34m[DEBUG]: AMateria default constructor called\033[0m" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
    std::cout << "\033[1;34m[DEBUG]: AMateria type constructor called\033[0m" << std::endl;
    _type = type;
}

AMateria::AMateria( const AMateria& other )//: PARENT(other)
{
    std::cout << "\033[1;34m[DEBUG]: AMateria default constructor called\033[0m" << std::endl;
}

AMateria &AMateria::operator=( const AMateria& e )
{
    std::cout << "\033[1;34m[DEBUG]: AMateria op = overload called\033[0m" << std::endl;
    if (this != &e)
        _type = e.type;
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "\033[1;34m[DEBUG]: AMateria destructor called\033[0m" << std::endl;
}

void AMateria::use(ICharacter &target)
{
}
