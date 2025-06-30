#ifndef RPN_H
# define RPN_H
# include <iostream>
# include <stack>
#include <stdexcept>

enum Type
{
    DIGIT,
    OPERATOR,
    ERROR = -1
};

class RPN
{
public:
    RPN();
    RPN(const RPN &) = default;
    RPN &operator=(const RPN &) = default;
    ~RPN();

    void calculate(const std::string & input);

    private:

    std::stack<double> pp;
    double              _result;
    std::string         _valid_operators;

    Type getType(const std::string & value) const;
    void computeCalculations(const std::string & input);
    void printOutput() const;
    void compute(const char op);
    double computeOperation(const char op, const double x, const double y);
    
};

#endif