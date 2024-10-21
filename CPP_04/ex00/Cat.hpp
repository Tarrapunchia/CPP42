#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
private:

public:
    Cat( void );
    Cat( const Cat& other );
    Cat &operator=( const Cat& e );
    ~Cat( void );

    void    makeSound( void ) const;
};

#endif
