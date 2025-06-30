#include "RPN.hpp"

int main(int argc, const char** argv) {
    try
    {
        if (argc != 2)
            throw (std::logic_error("Wrong number of arguments in input.\nUsage: ./RPN \"digits && operators\""));

        RPN rpn;
        rpn.calculate(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}