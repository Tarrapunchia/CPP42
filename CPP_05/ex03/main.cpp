#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat h("Hermes Conrad", 34);
    Bureaucrat N1("Number 1.0", 1);
    Bureaucrat bm("Beholder", 11);
    Bureaucrat mp("Morgan Proctor", 19);
    Bureaucrat wv("Warden Vogel", 135);
    Bureaucrat ll;
    Intern intern;
    AForm *presidential;
    AForm *robotomy;
    AForm *trees;
    try {
        presidential = intern.makeForm("pardon request", "Zaphod Beeblebrox");
        robotomy = intern.makeForm("robotomy request", "Bender");
        trees = intern.makeForm("shrubbery request", "trees.txt");
        N1.signForm(*presidential);
        N1.executeForm(*presidential);
        N1.signForm(*robotomy);
        N1.executeForm(*robotomy);
        N1.signForm(*trees);
        N1.executeForm(*trees);
        intern.makeForm("non existent", "bombolo");

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
