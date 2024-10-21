#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "\033[1;34m[DEBUG]: -= Animal - Dog - Cat tests =-\033[0m\n" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "\033[1;34m\n[DEBUG]: -= WrongAnimal - WrongCat tests =-\033[0m\n" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    wrongMeta->makeSound();
    wrongCat->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
