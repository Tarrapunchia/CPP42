#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){};
Intern::~Intern(){};
Intern::Intern(const Intern & other) {
    if (this == &other) 
        return;
};
Intern &Intern::operator=(const Intern & other){ if (&other == this) return *this; return *this;};

int getForm(const std::string & form)
{
    int i = 0;
    std::string forms[] = {"robotomy request", "pardon request", "shrubbery request"};
    for (; i < 3 && form != forms[i]; i++){}

    return i;
}

AForm * Intern::makeForm(const std::string & form, const std::string & target)
{
    AForm *_form = NULL;
    switch (getForm(form))
    {
    case 0: _form = new RobotomyRequestForm(target); break;
    case 1: _form = new PresidentialPardonForm(target); break;
    case 2: _form = new ShrubberyCreationForm(target); break;    
    default: throw std::logic_error("\"" + form + "\"" + ": No such a form"); break;
    }

    return _form;
}