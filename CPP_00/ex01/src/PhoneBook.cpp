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

    std::string s[5];

    for (int i = 0; i < 5; i++)
    {
        std::cout << "========================================" << std::endl;
        std::cout << contacts[0].fields[i];
        std::cin >> s[i];
        if (s[i].length() == 0)
        {
            std::cout << "None of the fields could be empty.\nExiting function."
                      << std::endl;
            return ;
        }
    }
    contacts[counter % 7].setContact(s);
    std::cout << "Contact Added." << std::endl;
    counter++;
}

void PhoneBook::search()
{
    std::string buf[4];
    t_details contact;

    std::cout << "=============================================" << std::endl;
    std::cout << "|                 PHONEBOOK                 |" << std::endl;
    std::cout << "=============================================" << std::endl;
    for (int i = 0; i < 7; i++)
    {
        contact = contacts[i].getContact();
        buf[0].assign(contact.first_name);
        buf[1].assign(contact.last_name);
        buf[2].assign(contact.nickname);
        buf[3].assign(contact.phone_number);
        for (int j = 0; j < 4; j++)
        {
            std::cout << "|";
            if (buf[j].length() > 10)
                buf[j] = buf[j].substr(0, 9) + '.';
            std::cout << std::setw(10) << buf[j];
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "=============================================" << std::endl;
}
