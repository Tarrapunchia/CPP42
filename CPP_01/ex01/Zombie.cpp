#include "Zombie.hpp"
Zombie::Zombie() : _name("A Common Zombie") { return; }
Zombie::Zombie(std::string name) : _name(name) { return; }

Zombie::~Zombie()
{
    std::cout << "Destroying " << _name << "." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName( std::string name ) { _name = name; }
