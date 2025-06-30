#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN()
: _result(0), _valid_operators("*/+-")
{
}

Type RPN::getType(const std::string & value) const
{
    if (std::isdigit(value[0]))
        return DIGIT;
    if (_valid_operators.find(value[0]) != std::string::npos)
        return OPERATOR;
    return ERROR;
}

void RPN::calculate(const std::string & input)
{
    try
    {
        computeCalculations(input);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

double RPN::computeOperation(const char op, const double x, const double y)
{
    switch (op) {
        case '+': return (x + y);
        case '-': return (x - y);
        case '*': return (x * y);
        case '/':
            if (y == 0) throw std::logic_error("Error: Division by zero.");
            return (x / y);
        default: return (0.f);
    }
    return (0.f);
}

void RPN::compute(const char op)
{
    if (pp.size() < 2)
        throw std::logic_error("Not enough digits in the stack to perform the operation.");
    const double value2 = pp.top();
    pp.pop();
    const double value1 = pp.top();
    pp.pop();
    pp.push(computeOperation(op, value1, value2));

}

void RPN::computeCalculations(const std::string & input)
{
    std::istringstream iss(input);
    std::string        token;

    while (iss >> token)
    {
        int8_t type = getType(token);
        switch (type) {
            case DIGIT: pp.push(std::atof(token.c_str())); break;
            case OPERATOR: compute(token[0]); break;
            case ERROR: throw std::runtime_error("Error in input values: " + token); break;
        }
    }
    if (pp.size() >= 2) throw std::overflow_error("Too many digits provided.");
    std::cout << pp.top() << std::endl;
}

RPN::~RPN()
{
}