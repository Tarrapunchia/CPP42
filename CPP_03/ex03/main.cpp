#include "DiamondTrap.hpp"

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <name>" << std::endl;
        return 1;
    }

    DiamondTrap diamondTrap(argv[1]);
    const std::string target = "a target";

    diamondTrap.whoAmI();
    diamondTrap.attack(target);



    return 0;
}
