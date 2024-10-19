#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP
# include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap( void );
    DiamondTrap( std::string name );
    DiamondTrap( const DiamondTrap& other );
    DiamondTrap &operator=( const DiamondTrap& e );
    ~DiamondTrap( void );

    void whoAmI( void );
    void attack( const std::string &target );
};



#endif