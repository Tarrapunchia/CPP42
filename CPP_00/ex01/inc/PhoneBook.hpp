#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int     counter;

public:
    PhoneBook();
    ~PhoneBook();
    void add();
    void search();

private:
};

#endif