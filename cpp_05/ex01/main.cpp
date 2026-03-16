#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat br (2, "br1");
        Form good_form("good_form", 3, 1);

        br.signForm(good_form);
        std::cout << br << std::endl;
        std::cout << good_form << std::endl;

        br.decrementGrade();
        br.decrementGrade();

        br.signForm(good_form);

        Form bad_form("bad_form", 3, 1);
        br.signForm(bad_form);
        std::cout << br << std::endl;
        std::cout << bad_form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
