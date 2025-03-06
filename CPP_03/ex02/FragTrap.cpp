#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(): ClapTrap("FragTrap")
{
    std::cout << "FragTrap default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap( const std::string name ): ClapTrap(name)
{
    std::cout << "FragTrap named constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap& other ): ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=( const FragTrap& other )
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other) { ClapTrap::operator=(other); }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "Frag trap " << _name << " destructor called" << std::endl;
}

void FragTrap::highFiveGuys( void ) const { std::cout << "High five?" << std::endl; }