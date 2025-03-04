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

// Logical op overload
bool Fixed::operator>(const Fixed e) const { return (this->_value > e._value); }
bool Fixed::operator<(const Fixed e) const { return (this->_value < e._value); }
bool Fixed::operator>=(const Fixed e) const { return (this->_value >= e._value); }
bool Fixed::operator<=(const Fixed e) const { return (this->_value <= e._value); }
bool Fixed::operator==(const Fixed e) const { return (this->_value == e._value); }
bool Fixed::operator!=(const Fixed e) const { return (this->_value != e._value); }

// Arithmetic op overload
Fixed Fixed::operator+( const Fixed e ) const { return Fixed(this->toFloat() + e.toFloat()); }
Fixed Fixed::operator-( const Fixed e ) const { return Fixed(this->toFloat() - e.toFloat()); }
Fixed Fixed::operator*( const Fixed e ) const { return Fixed(this->toFloat() * e.toFloat()); }
Fixed Fixed::operator/( const Fixed e ) const { return Fixed(this->toFloat() / e.toFloat()); }

// Increment/Decrement op overload
// preincremento
Fixed Fixed::operator++()
{
    _value++;
    return (*this);
}
// postincremento
Fixed Fixed::operator++( int )
{
    Fixed buf(*this);
    _value++;
    return buf;
}
// preincremento
Fixed Fixed::operator--()
{
    _value--;
    return (*this);
}
// postincremento
Fixed Fixed::operator--( int )
{
    Fixed buf(*this);
    _value--;
    return buf;
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

Fixed &Fixed::min ( Fixed& a, Fixed& b )
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}
const Fixed &Fixed::min ( const Fixed& a, const Fixed& b )
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed &Fixed::max ( Fixed& a, Fixed& b )
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed &Fixed::max ( const Fixed& a, const Fixed& b )
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
    os << fixed.toFloat();
    return (os);
}