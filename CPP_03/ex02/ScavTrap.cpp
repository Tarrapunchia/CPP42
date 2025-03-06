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
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}
ScavTrap &ScavTrap::operator=( const ScavTrap& other )
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) { ClapTrap::operator=(other); }
    return (*this);
}

ScavTrap::~ScavTrap() = default;

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is in Gate keeper mode" << std::endl;
}
