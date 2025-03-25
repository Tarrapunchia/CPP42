#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <ctime>
RobotomyRequestForm::RobotomyRequestForm()
:AForm("RobotomyRequestForm", 72, 45), _target("") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
:AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other)
:AForm("RobotomyRequestForm", 72, 45), _target(other._target) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) {
    if (!get_is_signed())
        std::cout << "Error: Form is not signed yet." << std::endl;
    if (get_exec_grade() < executor.getGrade())
    {
        std::cout << executor << "couldn't execute " << *this
        << "because: grade too low" << std::endl;
        throw AForm::GradeTooLowException();
    }
    if (std::time(nullptr) % 2 == 0)
        std::cout << "🔪 🔨 ⚒️ 🔫 🔧 🔩 ⚙️" << std::endl
        << _target << " has been robotomized." << std::endl;
    else
        std::cout << "Robotomy has failed." << std::endl;
}
