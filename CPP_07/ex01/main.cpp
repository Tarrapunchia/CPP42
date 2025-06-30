#include "iter.hpp"

void times_two(int &i)
{
	i *= 2;
}

void to_upper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int main( void )
{
	std::cout << "\033[33m" << "[Test int array]"<< "\033[0m" << std::endl;
	int int_arr[] = {1, 2, 3};

    iter(int_arr, sizeof(int_arr) / sizeof(int), print<int>);
    std::cout << std::endl;
	iter(int_arr, 3, times_two);
	for (int i = 0; i < 3; i++)
		std::cout << int_arr[i] << std::endl;

	std::cout << "\033[33m" << "[Test string array]\n"<< "\033[0m";
	std::string str_arr[] = {"Hello", "World", "!"};
    iter(str_arr, 3, print<std::string>);
    std::cout << std::endl;
	iter(str_arr, 3, to_upper);
	iter(str_arr, 3, print<std::string>);
	std::cout << std::endl;

	return 0;
}