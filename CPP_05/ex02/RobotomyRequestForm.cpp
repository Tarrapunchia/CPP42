#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>
RobotomyRequestForm::RobotomyRequestForm()
:AForm("RobotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
:AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
:AForm("RobotomyRequestForm", 72, 45), _target(other._target) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) {
    check_grade(executor);
    if (std::time(NULL) % 2 == 0)
        std::cout << "🔪 🔨 ⚒️ 🔫 🔧 🔩 ⚙️" << std::endl
        << _target << " has been robotomized." << std::endl;
    else
        std::cout << "Robotomy has failed." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
    if (this == &other) return *this;
    _target = other._target;

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {};