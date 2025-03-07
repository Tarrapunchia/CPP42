#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
    public:
    Cure( void );
    Cure( const Cure& other);
    Cure &operator=( const Cure& other );

    ~Cure( void );

    void use( ICharacter& target );
    AMateria* clone() const;
};

#endif
