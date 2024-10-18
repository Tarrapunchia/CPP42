#include "Point.hpp"

float   getArea( Point const a, Point const b, Point const point)
{
    return (abs(a.getX() * (b.getY() - point.getY()) +
            b.getX() * (point.getY() - a.getY()) +
            point.getX() * (a.getY() - b.getY())) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float         area  = getArea(a, b, c);
    const float   area1 = getArea(a, b, point);
    const float   area2 = getArea(b, c, point);
    const float   area3 = getArea(c, a, point);

    if (area == (area1 + area2 + area3))
        return true;
    return false;
}