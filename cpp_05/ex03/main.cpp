#include "includes/Intern.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int main()
{
    Intern randomIntern;
    AForm* form;

    form = randomIntern.makeForm("robot", "R1");
    if (form)
    {
        std::cout << "Form created!" << std::endl;
        delete form;
    }

    return 0;
}
