#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
private:

public:
    Cure( void );
    Cure( const Cure& other );
    Cure &operator=( const Cure& e );
    ~Cure( void );

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
