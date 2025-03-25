#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat h("Hermes Conrad", 34);
    Bureaucrat N1("Number 1.0", 1);
    Bureaucrat bm("Beholder", 11);
    Bureaucrat mp("Morgan Proctor", 19);
    Bureaucrat wv("Warden Vogel", 135);
    Bureaucrat ll;
    AForm *presidential = new PresidentialPardonForm("Zaphod Beeblebrox");
    AForm *robotomy = new RobotomyRequestForm("Bender");
    AForm *trees = new ShrubberyCreationForm("trees.txt");
    try {
        N1.signForm(*presidential);
        N1.executeForm(*presidential);
        N1.signForm(*robotomy);
        N1.executeForm(*robotomy);
        N1.signForm(*trees);
        N1.executeForm(*trees);
        delete presidential;
        delete robotomy;
        delete trees;
    } catch (std::exception & e) {
        delete presidential;
        delete robotomy;
        delete trees;
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
