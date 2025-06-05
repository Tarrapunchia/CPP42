#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

// int main()
// {
//     // try
//     // {
//         Span sp = Span(5);
//         std::vector<unsigned int> vec = {6, 3, 17, 9, 11};
//         // sp.addNumber(6);
//         // sp.addNumber(3);
//         // sp.addNumber(17);
//         // sp.addNumber(9);
//         // sp.addNumber(11);
//         sp.addNumber(vec.begin(), vec.end());
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     // }
//     // catch (const std::exception& e)
//     // {
//     //     std::cerr << e.what() << std::endl;
//     // }
//     return 0;
// }

unsigned int bigRand()
{
    return ((static_cast<unsigned int>(rand()) << 15) | static_cast<unsigned int>(rand()));
}

int main()
{
	std::cout << "\033[33m" << "[Test vector container]\n"<< "\033[0m";
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[31m[ERROR SIMPLE]: \033[0m" << e.what() << std::endl;
	}
    try
    {
        std::vector<unsigned int> fail(2, 2);
        sp.addNumber(fail.begin(), fail.end());
    }
    catch (const std::exception& e)
    {
        std::cerr << "\033[31m[ERROR RANGE]: \033[0m" << e.what() << std::endl;
    }
	try
	{
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\033[33m" << "[Test vector RNG range]\n"<< "\033[0m";
	Span sp2 = Span(100);
	std::vector<int> v;
	std::srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		int random_int = rand() % 1000000;
		v.push_back(random_int);
	}
	try
	{
		sp2.addNumber(v.begin(), v.end());
		std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << "\033[33m" << "[Test vector ordered range]\n"<< "\033[0m";
	Span sp3 = Span(100);
	std::vector<int> x(100);
    unsigned int counter = 0;
    std::generate(x.begin(), x.end(), [&counter]() { return counter++; });
	try
	{
		sp3.addNumber(x.begin(), x.end());
		std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\033[33m" << "[Test vector large RNG range]\n"<< "\033[0m";
	Span sp4 = Span(10000);
	std::vector<int> z;
	for (int i = 0; i < 10000; i++)
	{
		unsigned int random_int = bigRand();
		z.push_back(random_int);
	}
	try
	{
		sp4.addNumber(z.begin(), z.end());
		std::cout << "shortest span: " << sp4.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp4.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

    std::cout << "\033[33m" << "[Test vector large ordered range]\n"<< "\033[0m";
	Span sp5 = Span(10000);
	std::vector<int> y(10000);
    counter = 0;
    std::generate(y.begin(), y.end(), [&counter]() { return counter++; });
	try
	{
		sp5.addNumber(y.begin(), y.end());
		std::cout << "shortest span: " << sp5.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp5.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}