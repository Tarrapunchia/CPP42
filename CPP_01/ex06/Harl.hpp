#include <iostream>

class Harl
{
private:
    
public:
    Harl();
    ~Harl();
    void    complain( std::string level );
private:
    void    debug() const;
    void    info() const;
    void    warning() const;
    void    error() const;
};

typedef void (Harl::*function_ptr)(void) const;

