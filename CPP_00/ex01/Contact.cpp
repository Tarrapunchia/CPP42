#include "Contact.hpp"

Contact::Contact()
{
    fields[0].assign("First name: ");
    fields[1].assign("Last name: ");
    fields[2].assign("Nickname: ");
    fields[3].assign("Phone number: ");
    fields[4].assign("Darkest secret: ");
}

Contact::~Contact()
{
}
t_details Contact::getContact()
{
    return {
        first_name = this->first_name,
        last_name = this->last_name,
        nickname = this->nickname,
        phone_number = this->phone_number,
        darkest_secret = this->darkest_secret};
}
void Contact::setContact(std::string s[5])
{
    first_name.assign(s[0]);
    last_name.assign(s[1]);
    nickname.assign(s[2]);
    phone_number.assign(s[3]);
    darkest_secret.assign(s[4]);
}