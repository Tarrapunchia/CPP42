#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap( std::string name ): ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor with name called" << std::endl;

}

ScavTrap::ScavTrap( const ScavTrap& other )
{
//	values = other.values;
}
ScavTrap &ScavTrap::operator=( const ScavTrap& e )
{
    return (*this);
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is in Gate keeper mode" << std::endl;
}
