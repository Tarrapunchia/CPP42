#include "Ice.hpp"

Ice::Ice() : AMateria("ice");
{
    std::cout << "\033[1;34m[DEBUG]: Ice default constructor called\033[0m" << std::endl;
}

Ice::Ice( const Ice& other )//: PARENT(other)
{
    std::cout << "\033[1;34m[DEBUG]: Ice copy constructor called\033[0m" << std::endl;
}

Ice &Ice::operator=( const Ice& e )
{
    std::cout << "\033[1;34m[DEBUG]: Ice op = overload called\033[0m" << std::endl;
    if (this != &e)
       type = e.type;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "\033[1;34m[DEBUG]: Ice destructor called\033[0m" << std::endl;
}

AMateria* Ice::clone() const { return (new Ice()); }

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
