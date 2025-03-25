#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm()
:AForm("ShrubberyCreationForm", 145, 137), _target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
:AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other)
:AForm("ShrubberyCreationForm", 145, 137), _target(other._target) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) {
    if (!get_is_signed())
        std::cout << "Error: Form is not signed yet." << std::endl;
    if (get_exec_grade() < executor.getGrade())
    {
        std::cout << executor << "couldn't execute " << *this
        << "because: grade too low" << std::endl;
        throw AForm::GradeTooLowException();
    }
    std::ofstream file(_target);
    if (!file.is_open()) {
        throw std::ios_base::failure("Failed to open the file.");
    }
    file <<   R"(
    ,d                                      
    88                                      
  MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  
    88    88P'   "Y8 a8P_____88 a8P_____88  
    88    88         8PP""""""" 8PP"""""""  
    88,   88         "8b,   ,aa "8b,   ,aa  
    "Y888 88          `"Ybbd8"'  `"Ybbd8"')";
    file.close();  
}
