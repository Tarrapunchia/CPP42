#ifndef DATA_HPP
# define DATA_HPP
# include <iostream>

struct Data {
    Data();
    Data(int _flag, const std::string & _str);
    Data(const Data & other);
    Data & operator=(const Data & other);
    ~Data();
    int flag;
    std::string name;
};

#endif // DATA_HPP