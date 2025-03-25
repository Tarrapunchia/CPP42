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
        presidential->beSigned(N1);
        presidential->execute(N1);
        robotomy->beSigned(N1);
        robotomy->execute(N1);
        trees->beSigned(N1);
        trees->execute(ll);
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
