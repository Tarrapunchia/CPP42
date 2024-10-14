#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

typedef struct s_details {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
}   t_details;

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    std::string fields[5];
private:


public:
    Contact();
    ~Contact();
    t_details getContact();
    void setContact(std::string s[5]);


};

#endif