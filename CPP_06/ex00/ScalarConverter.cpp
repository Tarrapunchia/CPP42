#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>
#include <string>

bool cycle(const std::string &str, const int &i, bool isInt)
{
    if (isInt)
    {
        for(std::string::const_iterator it = str.begin() + i; it != str.end(); it++)
        {
            if (!std::isdigit(*it))
                return false;
        }
    }
    else
    {
        size_t end = 0;
        if (*(str.end() - 1) == 'f')
            end++;
        for(std::string::const_iterator it = str.begin() + i; it != str.end() - end; it++)
        {
            if (!(std::isdigit(*it) == true || *it == '.'))
                return false;
        }
    }
    return true;
}

int count(std::string::const_iterator begin, const std::string::const_iterator & end, char character)
{
    int counter = 0;

    while (begin != end)
    {
        if (*begin == character)
            counter++;
        begin++;
    }

    return counter;
}

TypeFlag getType(const std::string &str)
{
    // special (nan etc)
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf"
        ||  str == "+inff" || str == "-inff")
        return Special;

    // char
    if ((str.size() == 1 && !std::isdigit(str.at(0)))
        || (str.size() == 3 && *(str.begin()) == '\'' && *(str.end() - 1) == '\''))
        return Char;
    
    // int
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i < str.size() && cycle(str, i, true))
        return Int;

    // float
    if (*(str.end() - 1) == 'f')
    {
        if (str.find('.') != std::string::npos
            && count(str.begin(), str.end(), '.') == 1
            && cycle(str, i, false))
                return (Float);
    }

    // double
    if (str.find('.') != std::string::npos
        && count(str.begin(), str.end(), '.') == 1
        && cycle(str, i, false))
            return (Double);


    return Error;
}

void printChar(const std::string &str)
{
    size_t i = 0;
    if (*(str.begin()) == '\'')
        i = 1;
    std::cout << "char: " << str[i] << std::endl;
    std::cout << "int: " << static_cast<int>(str[i]) << std::endl;
    std::cout << "float: " << static_cast<int>(str[i]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<int>(str[i]) << ".0" << std::endl;
}

void printInt(const std::string &str)
{
    double nmb = std::strtold(str.c_str(), NULL);
    if (std::isprint(static_cast<char>(nmb)) && nmb <= 127 && nmb >= -128)
        std::cout << "char: " << static_cast<char>(nmb) << std::endl;
    else
        std::cout << "char: Non Printable" << std::endl;
    if (nmb > std::numeric_limits<int>::max() || nmb < (std::numeric_limits<int>::max() + 1))
        std::cout << "int: " << "Out of bounds" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(nmb) << std::endl;
    if (nmb > std::numeric_limits<float>::max() || nmb < (-std::numeric_limits<float>::max()))
        std::cout << "float: " << "Out of bounds" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(nmb) << ".0f" << std::endl;
    if (nmb > std::numeric_limits<double>::max() || nmb < (-std::numeric_limits<double>::max()))
        std::cout << "double: " << "Out of bounds" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(nmb) << ".0" << std::endl;
}

void printDouble(const std::string &str)
{
    double nmb = std::strtold(str.c_str(), NULL);
    std::string suffix("");
    if ((nmb - static_cast<int>(nmb)) == 0)
        suffix += ".0";
    if (std::isprint(static_cast<char>(nmb)) && suffix.size() != 0 && nmb <= 127 && nmb >= -128)
        std::cout << "char: " << static_cast<char>(nmb) << std::endl;
    else
        std::cout << "char: Non Printable" << std::endl;
    if (nmb > std::numeric_limits<int>::max() || nmb < (std::numeric_limits<int>::max() + 1))
        std::cout << "int: " << "Out of bounds" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(nmb) << std::endl;
    if (nmb > std::numeric_limits<float>::max() || nmb < (-std::numeric_limits<float>::max()))
        std::cout << "float: " << "Out of bounds" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(nmb) << suffix << "f" << std::endl;
    if (nmb > std::numeric_limits<double>::max() || nmb < (std::numeric_limits<double>::max()))
        std::cout << "double: " << "Out of bounds" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(nmb) << suffix << std::endl;
}

void printFloat(const std::string &str)
{
    double nmb = std::strtod(str.c_str(), NULL);
    std::string suffix("");
    if ((nmb - static_cast<int>(nmb)) == 0)
        suffix += ".0";
    if (std::isprint(static_cast<char>(nmb)) && suffix.size() != 0 && nmb <= 127 && nmb >= -128)
        std::cout << "char: " << static_cast<char>(nmb) << std::endl;
    else
        std::cout << "char: Non Printable" << std::endl;
    if (nmb > std::numeric_limits<int>::max() || nmb < (std::numeric_limits<int>::max() + 1))
        std::cout << "int: " << "Out of bounds" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(nmb) << std::endl;
    if (nmb > std::numeric_limits<float>::max() || nmb < (-std::numeric_limits<float>::max()))
        std::cout << "float: " << "Out of bounds" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(nmb) << suffix << "f" << std::endl;
    if (nmb > std::numeric_limits<double>::max() || nmb < (-std::numeric_limits<double>::max()))
        std::cout << "double: " << "Out of bounds" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(nmb) << suffix << std::endl;
}

void printSpecial(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << str << "f" << std::endl;
    std::cout << "double: " << str << std::endl; 
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &str)
{
    TypeFlag type = getType(str);

    switch (type)
    {
        case Char:
            printChar(str);
            break;
        case Int:
            printInt(str);
            break;
        case Float:
            printFloat(str);
            break;
        case Double:
            printDouble(str);
            break;
        case Special:
            printSpecial(str);
            break;
        case Error:
            throw std::invalid_argument("Invalid Argument: \"" + str + "\"");
    default:
        break;
    }
}