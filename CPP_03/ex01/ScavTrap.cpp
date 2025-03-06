#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}
ScavTrap::ScavTrap( std::string name ): ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& other )
{
//	values = other.values;
}
ScavTrap &ScavTrap::operator=( const ScavTrap& e )
{
    return (*this);
}
ScavTrap::~ScavTrap() = default;

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is in Gate keeper mode" << std::endl;
}
