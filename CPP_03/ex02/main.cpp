#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    ScavTrap    s = scava;

    scava.attack("gesu");
    s.attack("un amico di gesu");

    FragTrap    frag("gianni");
    FragTrap    f = frag;
    FragTrap    f2(frag);

    frag.attack("fragged");
    frag.highFiveGuys();
    f.attack("fragged f");
    f.highFiveGuys();
    f2.attack("fragged f2");
    f2.highFiveGuys();

    return 0;
}
