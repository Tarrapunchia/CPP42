#include "Fixed.hpp"
#include "Point.hpp"
#include <string>

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main( int argc, char **argv ) {
    bool flag = false;

    if (argc < 9)
    {
        std::cout << "\033[1;31m[ERROR]\nUsage \"./FIXED_POINT a.x a.y b.x b.y c.x c.y point.x point.y\033[0m" << std::endl;
        std::cout << "Testing with default values a(0,0) b(10,0) c(0,10) point(2,2)" << std::endl;
        const Point a;
        const Point b(10, 0);
        const Point c(0, 10);
        const Point point(11, 1);
        flag = bsp(a, b, c, point);
    }
    else
    {
        const Point a(std::stof(argv[1]), std::stof(argv[2]));
        const Point b(std::stof(argv[3]), std::stof(argv[4]));
        const Point c(std::stof(argv[5]), std::stof(argv[6]));
        const Point point(std::stof(argv[7]), std::stof(argv[8]));
        flag = bsp(a, b, c, point);
    }

    if (flag)
        std::cout << "The point is in the triangle" << std::endl;
    else
        std::cout << "Nope" << std::endl;
    return 0;
}
