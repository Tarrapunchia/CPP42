#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "\033[1;34m[DEBUG]: -= Animal - Dog - Cat tests =-\033[0m\n" << std::endl;
    Animal*  animalArray[50];

    for (size_t i = 0; i < 50; i++)
    {
        std::cout << "***********************************************" << std::endl;
        if (i % 2)
            animalArray[i] = new Cat();
        else
            animalArray[i] = new Dog();
    }

    for (size_t i = 0; i < 50; i++)
    {
        std::cout << "***********************************************" << std::endl;
        delete animalArray[i];
    }

    return 0;
}
