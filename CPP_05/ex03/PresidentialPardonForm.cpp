#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <ostream>

PresidentialPardonForm::PresidentialPardonForm()
:AForm("PresidentialPardonForm", 145, 137), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
:AForm("PresidentialPardonForm", 145, 137), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other)
:AForm("PresidentialPardonForm", 145, 137), _target(other._target) {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) {
    check_grade(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
    if (this == &other) return *this;
    _target = other._target;

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {};