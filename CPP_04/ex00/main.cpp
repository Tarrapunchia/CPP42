#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "\033[1;34m[DEBUG]: -= Animal - Dog - Cat tests =-\033[0m\n" << std::endl;
    // const Animal* bestio = new Animal();
    // const Animal* doggo = new Dog();
    // const Animal* catto = new Cat();
    {
        const Animal bestio;
        const Dog doggo;
        const Cat catto;
        std::cout << doggo.getType() << " " << std::endl;
        std::cout << catto.getType() << " " << std::endl;
        catto.makeSound();
        doggo.makeSound();
        bestio.makeSound();
    }

    std::cout << "\033[1;34m\n[DEBUG]: -= WrongAnimal - WrongCat tests =-\033[0m\n" << std::endl;
    {
        const WrongAnimal wrongBestio;
        const WrongCat wrongCat;
        wrongBestio.makeSound();
        wrongCat.makeSound();
    }

    return 0;
}
