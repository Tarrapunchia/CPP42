#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    _name = "FragTrap";
}

FragTrap::FragTrap( const FragTrap& other )
{
//	values = other.values;
}
FragTrap &FragTrap::operator=( const FragTrap& e )
{
    return (*this);
}
FragTrap::~FragTrap()
{
    std::cout << "Frag trap " << _name << " destructor called" << std::endl;
}

void FragTrap::highFiveGuys( void ) const { std::cout << "High five?" << std::endl; }