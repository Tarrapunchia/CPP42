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
  check_grade(executor);
  std::ofstream file((_target + "_shrubbery").c_str());
  if (!file.is_open()) {
      throw std::ios_base::failure("Failed to open the file.");
  }
  file << "   ,d\n";
  file << "   88                                      \n";
  file << " MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,  \n";
  file << "   88    88P'   \"Y8 a8P_____88 a8P_____88  \n";
  file << "   88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"  \n";
  file << "   88,   88         \"8b,   ,aa \"8b,   ,aa  \n";
  file << "   \"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"'\n";
  file.close();  
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
    if (this == &other) return *this;
    _target = other._target;

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};