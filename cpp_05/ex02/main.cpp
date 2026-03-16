#include "includes/Bureaucrat.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat br(1, "br1");
    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("robot");
    PresidentialPardonForm pardonForm("pardon");

    std::cout << std::endl;
    std::cout << "================ Not signed forms ================" << std::endl;
    std::cout << std::endl;
    br.executeForm(shrubberyForm);
    br.executeForm(robotomyForm);
    br.executeForm(pardonForm);

    std::cout << std::endl;
    std::cout << "================ Sign forms ================" << std::endl;
    std::cout << std::endl;
    br.signForm(shrubberyForm);
    br.signForm(robotomyForm);
    br.signForm(pardonForm);

    std::cout << std::endl;
    std::cout << "================ Signed forms ================" << std::endl;
    std::cout << std::endl;
    br.executeForm(shrubberyForm);
    br.executeForm(robotomyForm);
    br.executeForm(pardonForm);
    std::cout << std::endl;

    return 0;
}


