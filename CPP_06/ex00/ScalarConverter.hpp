#ifndef SCALAR_CONVERTER
# define SCALAR_CONVERTER
# include <cstddef>
# include <iostream>

typedef enum e_TypeFlag {
    None    = 0,      // 0000 0000
    Char    = 0x01,   // 0000 0001
    Int     = 0x02,   // 0000 0010
    Float   = 0x04,   // 0000 0100
    Double  = 0x08,   // 0000 1000
    Special = 0x16,   // 0001 0000
    Error   = 0x32    // 0010 0000
} TypeFlag;

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();

    static void convert(const std::string &str);

  private:
    
};

TypeFlag getType(const std::string &str);
void printChar(const std::string &str);
void printInt(const std::string &str);
void printDouble(const std::string &str);
void printFloat(const std::string &str);
void printSpecial(const std::string &str);

#endif