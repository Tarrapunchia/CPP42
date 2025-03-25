#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat( void ): _name("Lowliest form of life"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade ): _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ): _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
    if (this != &other)
    {
        _grade = other._grade;
        _name = other._name;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat( void ) {}

const std::string& Bureaucrat::getName() const { return (_name); };
int Bureaucrat::getGrade() const { return (_grade); };

void Bureaucrat::increaseGrade()
{
    std::cout << "\033[1;34m[DEBUG]: Trying to increase the grade of:\n\t" 
               << _name 
               << "\n\tGrade " << _grade
               << "\033[0m" << std::endl;
    if ((_grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decreaseGrade()
{
    std::cout << "\033[1;34m[DEBUG]: Trying to decrease the grade of:\n\t" 
               << _name 
               << "\n\tGrade " << _grade
               << "\033[0m" << std::endl;
    if ((_grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept { return ("GradeTooHighException"); }
const char* Bureaucrat::GradeTooLowException::what() const noexcept { return ("GradeTooLowException"); }

void    Bureaucrat::signForm(AForm & form) const {
    form.beSigned(*this);
}

std::ostream &operator<<(std::ostream & out, const Bureaucrat & bur)
{
    out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;
    return (out);
}