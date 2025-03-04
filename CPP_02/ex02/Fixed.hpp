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
    // Constructors
    Fixed( void );
    Fixed( const Fixed& other );
    Fixed( const int value );
    Fixed( const float value );
    ~Fixed( void );

    // Overload
    Fixed &operator=( const Fixed& e );
    bool  operator>( const Fixed e ) const;
    bool  operator<( const Fixed e ) const;
    bool  operator>=( const Fixed e ) const;
    bool  operator<=( const Fixed e ) const;
    bool  operator==( const Fixed e ) const;
    bool  operator!=( const Fixed e ) const;
    Fixed operator+( const Fixed e ) const;
    Fixed operator-( const Fixed e ) const;
    Fixed operator*( const Fixed e ) const;
    Fixed operator/( const Fixed e ) const;
    Fixed operator++();
    Fixed operator--();
    Fixed operator++( int );
    Fixed operator--( int );

    // Setters
    void    setRawBits ( int value );

    // Getters
    int     getRawBits ( void ) const;
    float   toFloat ( void ) const;
    int     toInt ( void ) const;

    // Static
    static Fixed &min ( Fixed& a, Fixed& b );
    static Fixed &max ( Fixed& a, Fixed& b );
    static const Fixed &min ( const Fixed& a, const Fixed& b );
    static const Fixed &max ( const Fixed& a, const Fixed& b );
};
std::ostream &operator<<(std::ostream &os, Fixed const &fixed);


#endif