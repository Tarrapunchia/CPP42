#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:

public:
    ScavTrap( void );
    ScavTrap( std::string name );
    ScavTrap( const ScavTrap& other );
    ScavTrap &operator=( const ScavTrap& e );
    ~ScavTrap( void );

    void    guardGate();
};

#endif