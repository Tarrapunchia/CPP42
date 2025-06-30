#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>
# include <iostream>


// BitcoinExchange::BitcoinExchange()
// : _values(NULL)
// {
// }

BitcoinExchange::BitcoinExchange(const std::string& table)
{
    std::ifstream file(table);
    if (!file.is_open())
        throw std::invalid_argument("Error: cannot open file " + table);
    
    std::string buffer;
    std::getline(file, buffer);
    while (std::getline(file, buffer))
    {
        size_t del = buffer.find(",");
        if (del == std::string::npos)
            throw std::invalid_argument("Error: problem in table file format");
        std::string key = buffer.substr(0, del);
        double value = atof(buffer.substr(del + 1).c_str());
        _refTable[key] = value;
    }

    file.close();
}

bool isLeap(int anno)
{
    if (anno % 4 == 0) {
        if (anno % 100 == 0) {
            return (anno % 400 == 0);
        }
        return true;
    }
    return false;
}

void BitcoinExchange::check_values(const std::string& key, double value)
{
    // date validation
    int anno   = std::stoi(key.substr(0,4));
    int mese   = std::stoi(key.substr(5,2));
    int giorno = std::stoi(key.substr(8,2));
    int febDay = (isLeap(anno))? 29: 28;

    if(anno < 0)
        throw std::out_of_range("Error: bad input => " + key);
    if (mese > 12 || mese < 1)
        throw std::out_of_range("Error: bad input => " + key);
    if ((mese == 11 || mese == 4 || mese == 6 || mese == 9)
        && (giorno < 1 || giorno > 30))
        throw std::out_of_range("Error: bad input => " + key);
    else if (mese == 2 && (giorno < 1 || giorno > febDay))
        throw std::out_of_range("Error: bad input => " + key);
    else if (giorno > 31)
        throw std::out_of_range("Error: bad input => " + key); 

    // value validation
    if (value < 0)
        throw std::out_of_range("Error: not a positive number.");
    if (value > 1000)
        throw std::out_of_range("Error: too large a number.");
}

void BitcoinExchange::getValue(const std::string& date, double value) const
{
    std::map<std::string, double>::const_iterator it = _refTable.upper_bound(date);
    if (it != _refTable.begin())
        it--;
    std::cout << it->first << " => " << value << " = " << (it->second * value) << std::endl;
}

void BitcoinExchange::extractor(const std::string& inputFile)
{
    std::ifstream file(inputFile);
    if (!file.is_open())
        throw std::invalid_argument("Error: cannot open file " + inputFile);
    
    std::string buffer;
    std::getline(file, buffer);
    while (std::getline(file, buffer))
    {
        try
        {
            size_t del = buffer.find("|");
            if (del == std::string::npos)
                throw std::invalid_argument("Error: bad input => " + buffer);
            std::string key = buffer.substr(0, del);
            double value = atof(buffer.substr(del + 2).c_str());
            check_values(key, value);
            getValue(key, value); 
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

BitcoinExchange::~BitcoinExchange()
{
}