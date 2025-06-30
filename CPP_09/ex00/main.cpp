
#include "BitcoinExchange.hpp"
int main(int argc, const char** argv) {
    try
    {
        BitcoinExchange btc("data.csv");
        btc.extractor("input.txt");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}