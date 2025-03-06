#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class AAnimal
{
protected:
    std::string type;
public:
    AAnimal( void );
    AAnimal( const AAnimal& other );
    AAnimal &operator=( const AAnimal& e );
    virtual ~AAnimal( void );

    // methods
    virtual void    makeSound( void ) const = 0;
    std::string     getType( void ) const;
};

#endif
