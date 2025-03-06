#include "ClapTrap.hpp"

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <name>" << std::endl;
        return 1;
    }

    ClapTrap clapTrap(argv[1]);
    const std::string target = "a target";

    for (int i = 0; i < 12; i++) {
        std::cout << "ClapTrap Acts!" << std::endl;
        clapTrap.attack("a target");
    }


    return 0;
}
