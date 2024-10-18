#include "ScavTrap.hpp"

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <name>" << std::endl;
        return 1;
    }

    ClapTrap clapTrap(argv[1]);
    const std::string target = "a target";

    std::cout << "ClapTrap Acts!" << std::endl;
    clapTrap.attack("a target");

    ScavTrap    scava("Scavona");

    scava.attack("gesu");

    return 0;
}
