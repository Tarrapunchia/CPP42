#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl    harl;

    std::cout << "[MAIN]\nHi, how can I help you with DEBUGGING, Sir?" << std::endl;
    harl.complain("DEBUG");
    std::cout << "[MAIN]\nSir you've been given the wrong INFO..." << std::endl;
    harl.complain("INFO");
    std::cout << "[MAIN]\nYou don't understand: your WARNINGs are useless since we're at..." << std::endl;
    harl.complain("WARNING");
    std::cout << "[MAIN]\nSir, listen to me: there's been an ERROR..." << std::endl;
    harl.complain("ERROR");
    std::cout << "[MAIN]\nSir you're actually @42Florence right now..." << std::endl;
    return 0;
}
