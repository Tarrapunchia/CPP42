#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook   phoneBook;
    std::string command;

    while (1)
    {
        std::cout << "Enter one of the commands [ADD, SEARCH, EXIT]: ";
        std::cin >> command;
        if (command == "ADD")
            phoneBook.add();
        else if (command == "EXIT")
            break ;
    }

    return 0;
}
