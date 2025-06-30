#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form()
: _NAME("No Form"), _is_signed(false), _SIGN_GRADE(150), _EXEC_GRADE(150) {}

Form::Form(const std::string & name, int sign_grade, int exec_grade)
: _NAME(name), _is_signed(false), _SIGN_GRADE(sign_grade), _EXEC_GRADE(exec_grade) {
    if (_SIGN_GRADE > 150 || _EXEC_GRADE > 150)
        throw Form::GradeTooLowException();
    if (_SIGN_GRADE < 1 || _EXEC_GRADE < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form & other)
: _NAME(other._NAME), _is_signed(other._is_signed), _SIGN_GRADE(other._SIGN_GRADE), _EXEC_GRADE(other._EXEC_GRADE) {}

std::string Form::get_name() const { return (_NAME); };
bool        Form::get_is_signed() const { return (_is_signed); };
int         Form::get_sign_grade() const { return (_SIGN_GRADE); };
int         Form::get_exec_grade() const { return (_EXEC_GRADE); };

const char* Form::GradeTooHighException::what() const throw() { return ("GradeTooHighException"); }
const char* Form::GradeTooLowException::what() const throw() { return ("GradeTooLowException"); }

void    Form::beSigned(const Bureaucrat & bur) {
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

Form &Form::operator=(const Form& other)
{
    if (this == &other) return *this;
    _is_signed = other._is_signed;
    return *this;
}

Form::~Form() {};

std::ostream& operator<<(std::ostream & os, const Form & form) {
    os << "Form:"
    << "\t\nname:\t" << form.get_name()
    << "\t\nis signed:\t" << std::boolalpha << form.get_is_signed()
    << "\t\nmin sign grade:\t" << form.get_sign_grade()
    << "\t\nmin exec grade:\t" << form.get_exec_grade() << std::endl;
    return (os);
}