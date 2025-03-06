#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat: public AAnimal
{
private:
    Brain * _brain;
public:
    Cat( void );
    Cat( const Cat& other );
    Cat &operator=( const Cat& e );
    ~Cat( void );

    void    makeSound( void ) const;
};

#endif
