#include "Span.hpp"

Span::Span(const unsigned int & N)
: _capacity(N)
{
    _nbs.reserve(N);
}

void Span::addNumber(unsigned int n) 
{
    if (_nbs.size() >= _capacity)
        throw std::overflow_error("Span is already full");
    _nbs.push_back(n);
}

unsigned int Span::shortestSpan() const
{
    if (_nbs.size() <= 1)
        throw std::logic_error("Not enough elements");

    std::vector<unsigned int> buf = _nbs;
    std::sort(buf.begin(), buf.end());
    unsigned int slz = buf[1] - buf[0];
    for (unsigned int i = 2; i < buf.size(); i++)
    {
        slz = std::min(slz, (buf[i] - buf[i - 1]));
    }

    return (slz);
} 

unsigned int Span::longestSpan() const
{
    if (_nbs.size() <= 1)
        throw std::logic_error("Not enough elements");
    
    std::vector<unsigned int> buf = _nbs;
    std::sort(buf.begin(), buf.end());
    unsigned int slz = buf[1] - buf[0];
    for (unsigned int i = 2; i < buf.size(); i++)
    {
        slz = std::max(slz, (buf[i] - buf[0]));
    }

    return (slz);
}

Span::~Span()
{
}