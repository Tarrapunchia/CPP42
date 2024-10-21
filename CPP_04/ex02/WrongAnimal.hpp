#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal( void );
    WrongAnimal( std::string type );
    WrongAnimal( const WrongAnimal& other );
    WrongAnimal &operator=( const WrongAnimal& e );
    ~WrongAnimal( void );

    void        makeSound( void ) const;
    std::string getType( void ) const;
};

#endif
