#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "\033[1;34m[DEBUG]: Brain default constructor called\033[0m" << std::endl;
}

Brain::Brain( const Brain& other )
{
    std::cout << "\033[1;34m[DEBUG]: Brain copy constructor called\033[0m" << std::endl;
    *this = other;
}

Brain &Brain::operator=( const Brain& e )
{
    std::cout << "\033[1;34m[DEBUG]: Brain op = overload called\033[0m" << std::endl;
    if (this != &e) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = e.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "\033[1;34m[DEBUG]: Brain destructor called\033[0m" << std::endl;
}
