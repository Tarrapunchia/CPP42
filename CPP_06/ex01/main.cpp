#include "Serializer.hpp"
#include <cstddef>
#include <cstdint>

int main(int argc, const char** argv) {

    Data data(12, "Gianni");

    uintptr_t ptr = Serializer::serialize(&data);

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