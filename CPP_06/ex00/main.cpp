#include "ScalarConverter.hpp"

int main(int argc, const char** argv) {

    // ScalarConverter::convert("\'a\'");
    // ScalarConverter::convert("97");
    // ScalarConverter::convert("0");
    // ScalarConverter::convert("12.0");
    // ScalarConverter::convert("100.0");
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}