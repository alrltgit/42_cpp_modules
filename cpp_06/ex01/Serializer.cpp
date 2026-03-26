#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default constructor is called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
    std::cout << "Copy constructor is called" << std::endl;
}

Serializer& Serializer::operator = (const Serializer& other)
{
    (void)other;
    std::cout << "Copy assignment operator is called" << std::endl;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Destructor is called" << std::endl;
}

// Data serialization uses a serializer to convert data objects into byte streams 
// containing the object information. After serialization, the data is saved in standardized,
// platform-independent formats: JSON, XML, Avro, Protobuf, and binary.

// reinterpret cast:
// - It is used to convert a pointer of some data type into a pointer of another data type.
// - It does not check if the pointer type and data pointed by the pointer is same or not.

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
