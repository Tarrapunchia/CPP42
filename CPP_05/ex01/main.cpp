#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main()
{
    Bureaucrat h("Hermes Conrad", 34);
    Bureaucrat N1("Number 1.0", 1);
    Bureaucrat bm("Beholder", 11);
    Bureaucrat mp("Morgan Proctor", 19);
    Bureaucrat wv("Warden Vogel", 135);

    try {
        Form liv15("Livello 15", 15, 15);
        Form liv1("Livello 1", 1, 1);
        liv15.beSigned(bm);
        liv1.beSigned(wv);
        Form liv300("Livello 300", 300, 300);
        Form liv0("Livello 0", 0, 0);
    } catch (std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
