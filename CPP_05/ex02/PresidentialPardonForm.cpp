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
    if (!get_is_signed())
        std::cout << "Error: Form is not signed yet." << std::endl;
    if (get_exec_grade() < executor.getGrade())
    {
        std::cout << executor << "couldn't execute " << *this
        << "because: grade too low" << std::endl;
        throw AForm::GradeTooLowException();
    }
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n" << std::endl;
}
