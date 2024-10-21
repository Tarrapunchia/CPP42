#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:

public:
    WrongCat( void );
    WrongCat( const WrongCat& other );
    WrongCat &operator=( const WrongCat& e );
    ~WrongCat( void );
};

#endif
