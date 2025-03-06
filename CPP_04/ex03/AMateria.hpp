#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
    protected:
    std::string _type;

    public:
    AMateria( std::string const& type );
    AMateria( const AMateria& other );
    AMateria &operator=( const AMateria& other );
    std::string const& getType() const;
    
    
    virtual ~AMateria( void ) {};
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};

#endif