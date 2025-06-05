#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iterator>
#include <algorithm>

class Span
{
public:
    Span() = delete;
    Span(const unsigned int & N);
    Span(const Span &);
    Span &operator=(const Span &);
    ~Span();

    void addNumber(unsigned int);

    template <typename InputIt>
    void addNumber(InputIt start, InputIt end)
    {
        if ((_nbs.size() + std::distance(start, end)) > _capacity)
            throw std::overflow_error("Span is already full");
        _nbs.insert(_nbs.end(), start, end);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

private:
    std::vector<unsigned int> _nbs;
    unsigned int _capacity;
};

#endif