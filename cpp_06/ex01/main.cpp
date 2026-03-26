#include "Serializer.hpp"

int main()
{
    Data obj;
    Data *original_obj = &obj;

    obj.val = 42;

    uintptr_t conv = Serializer::serialize(&obj);
    Data* res = Serializer::deserialize(conv);

    if (res == original_obj)
        std::cout << "Return value of deserialize() == the original pointer" << std::endl;
    else
        std::cout << "Return value of deserialize() != the original pointer" << std::endl;

    return (0);
}
