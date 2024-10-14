#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    counter = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add()
{
    if (counter >= 7)
    {
        t_details contact_info = contacts[counter % 7].getContact();
        std::cout << "You are overwriting the contact informations of "
                  << contact_info.first_name
                  << " "
                  << contact_info.last_name
                  << std::endl;
    }

    counter++;
    std::string s[5];

    for (int i = 0; i < 5; i++)
    {
        std::cout << "==========================================" << std::endl;
        std::cout << contacts[0].fields[i];
        std::cin >> s[i];
        if (s[i].length() == 0)
        {
            std::cout << "None of the fields could be empty.\nExiting function." << std::endl;
            return ;
        }
    }
    contacts[counter % 7].setContact(s);
    std::cout << "Contact Added." << std::endl;
}
