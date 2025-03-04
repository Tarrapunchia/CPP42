#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
private:

public:
    ScavTrap( void );
    ScavTrap( std::string name );
    ScavTrap( const ScavTrap& other );
    ScavTrap &operator=( const ScavTrap& e );
    ~ScavTrap( void );

    void    guardGate();

    int getEnergy( void ) const { return _energyPoints; };
    int getDamage( void ) const { return _attackDamage; };
};

#endif