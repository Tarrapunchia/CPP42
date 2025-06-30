#pragma once
#include <iostream>

class AForm;
class Intern
{
public:
    Intern();
    Intern(const Intern & other);
    Intern &operator=(const Intern & other);
    ~Intern();

    AForm * makeForm(const std::string & form, const std::string & target);

private:
    
};
