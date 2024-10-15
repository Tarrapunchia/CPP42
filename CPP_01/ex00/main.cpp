#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
    Zombie zombie("giovanni");

    zombie.announce();
    Zombie *newerZombie = newZombie("Carlo");
    newerZombie->announce();
    randomChump("pablito");

    delete newerZombie;
    return 0;
}
