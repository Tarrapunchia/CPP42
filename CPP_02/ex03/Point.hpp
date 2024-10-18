#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;
public:
    Point( void );
    Point( const float x, const float y );
    Point( const Point& other );
    Point &operator=( const Point& e );
    ~Point( void );

    // getter
    const Fixed &getX() const;
    const Fixed &getY() const;

    // setter
    // void    setValues( const float x, const float y );
};



#endif