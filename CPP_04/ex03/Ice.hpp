#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
private:

public:
    Ice( void );
    Ice( const Ice& other );
    Ice &operator=( const Ice& e );
    ~Ice( void );

    Ice* clone() const;
    void use(ICharacter& target);
};

#endif
