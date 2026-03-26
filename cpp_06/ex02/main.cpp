#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

// In C++, dynamic_cast is a cast operator that converts 
// data from one type to another type at runtime. 
// It is mainly used in inherited class hierarchies for 
// safely casting the base class pointer or reference to 
// derived class (called downcasting)

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type of the object pointed to by p - A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type of the object pointed to by p - B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type of the object pointed to by p - C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type of the object pointed to by p - A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type of the object pointed to by p - B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type of the object pointed to by p - C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    Base *obj = generate();

    identify(obj);

    identify(*obj);

    delete obj;
    return (0);
}
