#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class Dog: public AAnimal
{
private:
    Brain * _brain;
public:
    Dog( void );
    Dog( const Dog& other );
    Dog &operator=( const Dog& e );
    ~Dog( void );

    void makeSound( void ) const;
};

#endif
