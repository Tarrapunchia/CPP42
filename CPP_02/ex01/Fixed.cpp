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

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _value = value  << _fractional_bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(std::roundf(value * (1 << _fractional_bits)));

}

Fixed &Fixed::operator=( const Fixed& e )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &e)
        _value = e._value;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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

float   Fixed::toFloat ( void ) const
{
    return (static_cast<float>(_value) / (1 << _fractional_bits));
}

int     Fixed::toInt ( void ) const
{
    return (_value >> _fractional_bits);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
    os << fixed.toFloat();
    return (os);
}