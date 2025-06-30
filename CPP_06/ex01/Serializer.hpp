#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer
{
protected:
    Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
public:
    ~Serializer();

    static void* serialize (Data *ptr);
    static Data* deserialize(void *raw);

private:
    
};
#endif