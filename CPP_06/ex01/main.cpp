#include "Serializer.hpp"

int main() {
    Data data(12, "Gianni");

    void *ptr = Serializer::serialize(&data);

    Data *dptr = NULL;
    dptr = Serializer::deserialize(ptr);

    std::cout << dptr->flag << std::endl;
    std::cout << dptr->name << std::endl;

    // try
    // {
    //     Serializer *ser = new Serializer();
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    return 0;
}