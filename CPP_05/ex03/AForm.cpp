#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm()
: _NAME("No Form"), _is_signed(false), _SIGN_GRADE(150), _EXEC_GRADE(150) {}

AForm::AForm(const std::string & name, int sign_grade, int exec_grade)
: _NAME(name), _is_signed(false), _SIGN_GRADE(sign_grade), _EXEC_GRADE(exec_grade) {
    if (_SIGN_GRADE > 150 || _EXEC_GRADE > 150)
        throw AForm::GradeTooLowException();
    if (_SIGN_GRADE < 1 || _EXEC_GRADE < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm & other)
: _NAME(other._NAME), _is_signed(other._is_signed), _SIGN_GRADE(other._SIGN_GRADE), _EXEC_GRADE(other._EXEC_GRADE) {}

std::string AForm::get_name() const { return (_NAME); };
bool        AForm::get_is_signed() const { return (_is_signed); };
int         AForm::get_sign_grade() const { return (_SIGN_GRADE); };
int         AForm::get_exec_grade() const { return (_EXEC_GRADE); };

const char* AForm::GradeTooHighException::what() const throw() { return ("GradeTooHighException"); }
const char* AForm::GradeTooLowException::what() const throw() { return ("GradeTooLowException"); }

void    AForm::beSigned(const Bureaucrat & bur) {
    if (_is_signed == true)
    {
        std::cout << "Form is already signed." << std::endl;
        return ;
    }
    if (bur.getGrade() <= _SIGN_GRADE)
    {
        _is_signed = true;
        std::cout << bur << "signed\n" << *this << std::endl;
    }
    else
    {
        std::cout << bur << "couldn't sign\n" << *this
        << "because: bureaucrat's grade too low" << std::endl;
    }
}

AForm &AForm::operator=(const AForm& other)
{
    if (this == &other) return *this;
    _is_signed = other._is_signed;
    return *this;
}

void AForm::check_grade(const Bureaucrat & bur) {
    if (!get_is_signed())
        std::cout << "Error: Form is not signed yet." << std::endl;
    if (get_exec_grade() < bur.getGrade())
    {
        std::cout << bur << "couldn't execute " << *this
        << "because: grade too low" << std::endl;
        throw AForm::GradeTooLowException();
    }
}

AForm::~AForm() {};

std::ostream& operator<<(std::ostream & os, const AForm & form) {
    os << "Form:"
    << "\t\nname:\t" << form.get_name()
    << "\t\nis signed:\t" << std::boolalpha << form.get_is_signed()
    << "\t\nmin sign grade:\t" << form.get_sign_grade()
    << "\t\nmin exec grade:\t" << form.get_exec_grade() << std::endl;
    return (os);
}