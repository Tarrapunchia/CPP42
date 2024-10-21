#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
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
