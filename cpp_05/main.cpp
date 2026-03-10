#include "Bureaucrat.hpp"

int main()
{
    std::cout << "================= Bureaucrat initial grades =================" << std::endl;
    Bureaucrat br1 = Bureaucrat(5, "br1");
    Bureaucrat br2 = Bureaucrat(150, "br2");
    Bureaucrat br3 = Bureaucrat(1, "br3");

    std::cout << br1;
    std::cout << br2;
    std::cout << br3;

    std::cout << "================= Bureaucrat incremented grades =================" << std::endl;
    br1.increment_grade();
    br3.increment_grade();

    std::cout << br1;
    std::cout << br2;
    std::cout << br3;

    std::cout << "================= Bureaucrat decremented grades =================" << std::endl;
    br1.decrement_grade();
    br2.decrement_grade();
    br3.decrement_grade();

    std::cout << br1;
    std::cout << br2;
    std::cout << br3;
    return 0;
}
