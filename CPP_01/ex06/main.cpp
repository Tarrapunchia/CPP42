#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl    harl;

    if (argc != 2)
        return 0;
    harl.complain(argv[1]);
    return 0;
}
