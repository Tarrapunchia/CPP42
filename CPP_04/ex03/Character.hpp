#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
private:
    std::string _name;
    AMateria*   _inventory[4];
public:
    Character( void );
    Character( std::string &name );
    Character( const Character& other );
    Character &operator=( const Character& e );
    ~Character( void );

    std::string const & getName() const;
};

#endif
