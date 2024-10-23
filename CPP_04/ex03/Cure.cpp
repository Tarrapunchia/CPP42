#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "\033[1;34m[DEBUG]: Cure default constructor called\033[0m" << std::endl;
}

Cure::Cure( const Cure& other )//: PARENT(other)
{
    std::cout << "\033[1;34m[DEBUG]: Cure default constructor called\033[0m" << std::endl;
}

Cure &Cure::operator=( const Cure& e )
{
    std::cout << "\033[1;34m[DEBUG]: Cure op = overload called\033[0m" << std::endl;
    //if (this != &e)
    //    type = e.type;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "\033[1;34m[DEBUG]: Cure destructor called\033[0m" << std::endl;
}

AMateria* Cure::clone() const { return (new Cure()); }

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
