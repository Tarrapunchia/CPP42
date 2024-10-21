#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
protected:
    std::string type;
public:
    Animal( void );
    Animal( std::string type );
    Animal( const Animal& other );
    Animal &operator=( const Animal& e );
    virtual ~Animal( void );

    // methods
    virtual void    makeSound( void ) const = 0;
    std::string     getType( void ) const;
};

#endif
