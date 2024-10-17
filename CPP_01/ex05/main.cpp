#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl    harl;

    std::cout << "Hi, how can I help you with DEBUGGING, Sir?" << std::endl;
    harl.complain("debug");
    std::cout << "Sir you've been given the wrong INFO..." << std::endl;
    harl.complain("info");
    std::cout << "You don't understand: your WARNINGs are useless since we're at..." << std::endl;
    harl.complain("warning");
    std::cout << "Sir, listen to me: there's been an ERROR..." << std::endl;
    harl.complain("error");
    std::cout << "Sir you're actually @42Florence right now..." << std::endl;
    return 0;
}
