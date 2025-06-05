#ifndef SCALAR_CONVERTER
# define SCALAR_CONVERTER
#include <cstddef>
# include <iostream>

enum class TypeFlag : uint8_t {
    None    = 0,      // 0000 0000
    Char    = 0x01,   // 0000 0001
    Int     = 0x02,   // 0000 0010
    Float   = 0x04,   // 0000 0100
    Double  = 0x08,   // 0000 1000
    Special = 0x16,   // 0001 0000
    Error   = 0x32    // 0010 0000
};

class ScalarConverter
{
public:
    ScalarConverter() = default;
    ScalarConverter(const ScalarConverter &) = default;
    ScalarConverter &operator=(const ScalarConverter &) = default;
    ~ScalarConverter() = default;

    static void convert(const std::string &str);

  private:
    
};

const TypeFlag getType(const std::string &str);
const void printChar(const std::string &str);
const void printInt(const std::string &str);
const void printDouble(const std::string &str);
const void printFloat(const std::string &str);
const void printSpecial(const std::string &str);

#endif