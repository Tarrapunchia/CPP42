#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
    Bureaucrat h("Hermes Conrad", 34);
    Bureaucrat N1("Number 1.0", 1);
    Bureaucrat bm("Beholder", 11);
    Bureaucrat mp("Morgan Proctor", 19);
    Bureaucrat wv("Warden Vogel", 135);
    Bureaucrat ll;

    std::cout << h;
    h.increaseGrade();
    std::cout << h;
    h.decreaseGrade();
    std::cout << h;
    
    try {
        ll.decreaseGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        N1.increaseGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}
