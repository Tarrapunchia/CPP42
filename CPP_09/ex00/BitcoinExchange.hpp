#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <iostream>
#include <string>

class BitcoinExchange
{
public:
    BitcoinExchange() = delete;
    BitcoinExchange(const std::string& table);
    BitcoinExchange(const BitcoinExchange &) = default;
    BitcoinExchange &operator=(const BitcoinExchange &) = default;
    ~BitcoinExchange();

    void extractor(const std::string &inputFile);

private:
    std::map<std::string, double> _refTable;
    void check_values(const std::string& key, double value);
    void getValue(const std::string& date, double value) const;
};


#endif