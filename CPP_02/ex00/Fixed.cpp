#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other )
{
    std::cout << "Copy constructor called" << std::endl;
    _value = other._value;
}

Fixed &Fixed::operator=( const Fixed& e )
{
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed()
{
}

int     Fixed::getRawBits() const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value; 
};

void    Fixed::setRawBits( int value )
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = value;
}

