#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &)
{
}

Serializer &Serializer::operator=(const Serializer &)
{
    return *this;
}

Serializer::~Serializer()
{
}

void * Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<void *>(ptr);
}

Data* Serializer::deserialize(void * raw)
{
    return reinterpret_cast<Data *>(raw);
}