#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
    function_ptr function_ptrs[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[4] = {
        "debug",
        "info",
        "warning",
        "error"
    };
    
    for (size_t i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*function_ptrs[i])();
            return ;
        }
    }    

    std::cout << "Harl is actually fine i guess..." << std::endl;
}

void Harl::debug() const
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() const
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() const
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() const
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}