#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Diamond_clap_name"), _name("Diamond")
{
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;

    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap named constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other )
{
//	values = other.values;
}
DiamondTrap &DiamondTrap::operator=( const DiamondTrap& e )
{
    return (*this);
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "Diamond destructor called" << std::endl;
}

void DiamondTrap::whoAmI( void )
{
    std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
    std::cout << "Diamond name: " << _name << std::endl;
}

void DiamondTrap::attack( const std::string &target ) { ClapTrap::attack(target); }