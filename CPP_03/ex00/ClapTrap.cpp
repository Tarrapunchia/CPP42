#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Desichado"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
}

ClapTrap::ClapTrap( std::string name ): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
}

ClapTrap::ClapTrap( const ClapTrap& other ): _name(other._name)
{
	_hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}
ClapTrap &ClapTrap::operator=( const ClapTrap& e )
{
    if (this != &e)
    {
        this->_name = e._name;
        this->_hitPoints = e._hitPoints;
        this->_energyPoints = e._energyPoints;
        this->_attackDamage = e._attackDamage;
    }
    return (*this);
}
ClapTrap::~ClapTrap()
{
}

void    ClapTrap::attack( const std::string& target )
{
    if (_energyPoints <= 0)
    {
        std::cout << "No energy points left." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target
            << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap is defeated! Stop hitting it =(!" << std::endl;
        return ;
    }
    _hitPoints -= amount;
    if (_hitPoints <= 0)
        std::cout << "ClapTrap has been defeated!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0)
    {
        std::cout << "No energy points left." << std::endl;
        return ;
    }
    _hitPoints += amount;
    _energyPoints--;
}
