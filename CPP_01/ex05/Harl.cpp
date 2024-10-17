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
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
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
    std::cout << "\033[1;37m[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\033[0m" << std::endl;
}

void Harl::info() const
{
    std::cout << "\033[1;34m[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\033[0m" << std::endl;
}

void Harl::warning() const
{
    std::cout << "\033[1;33m[WARNING]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\033[0m" << std::endl;
}

void Harl::error() const
{
    std::cout << "\033[1;31m[ERROR]\nThis is unacceptable! I want to speak to the manager now.\033[0m" << std::endl;
}