#include "ScavTrap.hpp"

int main(int argc, char const *argv[])
{
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <name Clap> <name Scav>" << std::endl;
        return 1;
    }

    ClapTrap clapTrap(argv[1]);
    const std::string target = "a target";

    std::cout << "ClapTrap Acts!" << std::endl;
    clapTrap.attack("a target");

    ScavTrap    scavTrap(argv[2]);

    scavTrap.attack("a target");
    scavTrap.guardGate();

    return 0;
}
