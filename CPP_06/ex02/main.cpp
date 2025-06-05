#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <iostream>

Base * generate(void)
{
    int randomNum = rand() % 3;
    switch (randomNum) {
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "Type A" << std::endl;
    if (dynamic_cast<B *>(p) != NULL)
        std::cout << "Type B" << std::endl;
    if (dynamic_cast<C *>(p) != NULL)
        std::cout << "Type C" << std::endl;
}

void identify(Base& p)
{
    try { dynamic_cast<A &>(p); std::cout << "Type A" << std::endl; }
    catch (const std::exception &e) { }
    try { dynamic_cast<B &>(p); std::cout << "Type B" << std::endl; }
    catch (const std::exception &e) { }
    try { dynamic_cast<C &>(p); std::cout << "Type C" << std::endl; }
    catch (const std::exception &e) { }        
}

int main()
{
    srand(time(0));

    Base *a = generate();
    Base *b = generate();
    Base *c = generate();

    identify(a);
    identify(b);
    identify(c);

    delete(a);
    delete(b);
    delete(c);
    return 0;
}