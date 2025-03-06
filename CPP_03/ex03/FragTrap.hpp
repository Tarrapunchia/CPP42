#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
private:

public:
    FragTrap( void );
    FragTrap( const std::string name );
    FragTrap( const FragTrap& other );
    FragTrap &operator=( const FragTrap& e );
    ~FragTrap( void );

    void highFiveGuys( void ) const;
    int  getHitPoints() const;
    int  getDamage() const;
};

#endif