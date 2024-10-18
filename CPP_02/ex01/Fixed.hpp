#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <math.h>

class Fixed
{
private:
    int                 _value;
    static const int    _fractional_bits = 8;
public:
    Fixed( void );
    Fixed( const Fixed& other );
    Fixed( const int value );
    Fixed( const float value );
    Fixed &operator=( const Fixed& e );
    ~Fixed( void );

    int     getRawBits ( void ) const;
    void    setRawBits ( int value );
    float   toFloat ( void ) const;
    int     toInt ( void ) const;
};
std::ostream &operator<<(std::ostream &os, Fixed const &fixed);


#endif