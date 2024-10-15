#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
    Zombie      *horde;
    std::string name;
    int         len;

    if (argc < 3)
    {
        name.assign("Zombie");
        len = 7;
    }
    else
    {
        name.assign(argv[2]);
        len = std::atoi(argv[1]);
    }

    if (len <= 0) return 0;

    horde = zombieHorde(len, name);

    for (size_t i = 0; i < len; i++)
        horde[i].announce();

    delete [] horde;

    return 0;
}
