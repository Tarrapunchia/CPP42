#include <iostream>

int main(int argc, char const *argv[])
{
    std::string     salute = "HI THIS IS BRAIN";
    std::string     *stringPTR = &salute;
    std::string     &stringREF = salute;

    std::cout << "Memory address of string: " << &salute << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << "Value of the string variable: " << salute << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    return 0;
}
