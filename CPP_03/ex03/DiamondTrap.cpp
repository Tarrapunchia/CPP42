#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Diamond_clap_name"), _name("Diamond")
{
    FragTrap tempFrag;
    
    _hitPoints = tempFrag.getHitPoints();
    _attackDamage = tempFrag.getDamage();      
    _energyPoints = ScavTrap::_energyPoints;
    std::cout << "HP: " << _hitPoints << std::endl;
    std::cout << "ENERGY: " << _energyPoints << std::endl;
    std::cout << "ATTACKDAMAGE: " << _attackDamage << std::endl;

    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), _name(name)
{
    FragTrap tempFrag("temp");
    
    _hitPoints = tempFrag.getHitPoints();
    _attackDamage = tempFrag.getDamage();      
    _energyPoints = ScavTrap::_energyPoints;
    std::cout << "HP: " << _hitPoints << std::endl;
    std::cout << "ENERGY: " << _energyPoints << std::endl;
    std::cout << "ATTACKDAMAGE: " << _attackDamage << std::endl;
    std::cout << "DiamondTrap named constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other._name + "_clap_name"),
      ScavTrap(other._name),
      _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        
        _name = other._name;
    }
    std::cout << "DiamondTrap assign operator called for " << _name << std::endl;
    return *this;
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