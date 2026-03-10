#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "================= Bureaucrat initial grades =================" << std::endl;
        Bureaucrat br1 = Bureaucrat(5, "br1");
        Bureaucrat br2 = Bureaucrat(150, "br2");
        Bureaucrat br3 = Bureaucrat(1, "br3");

        std::cout << br1;
        std::cout << br2;
        std::cout << br3;

        std::cout << "================= Bureaucrat incremented grades =================" << std::endl;
        br1.incrementGrade();
        br2.incrementGrade();
        br3.decrementGrade();

        std::cout << br1;
        std::cout << br2;
        std::cout << br3;

        std::cout << "================= Bureaucrat decremented grades =================" << std::endl;
        br1.decrementGrade();
        br2.decrementGrade();
        br3.decrementGrade();

        std::cout << br1;
        std::cout << br2;
        std::cout << br3;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
