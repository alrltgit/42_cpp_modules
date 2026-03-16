#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor is called"<< std::endl;
};

Intern::Intern(const Intern& other)
{
    std::cout << "Intern copy constructor is called"<< std::endl;
    (void)other;
}

Intern& Intern::operator = (const Intern& other)
{
    std::cout << "Intern assignment operator is called"<< std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
    if (formName == "shrubbery")
    {
        std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
        return new ShrubberyCreationForm(formTarget);
    }
    else if (formName == "robot")
    {
        std::cout << "Intern creates RobotomyRequestForm" << std::endl;
        return new RobotomyRequestForm(formTarget);
    }
    else if (formName == "pardon")
    {
        std::cout << "Intern creates PresidentialPardonForm" << std::endl;
        return new PresidentialPardonForm(formTarget);
    }

    std::cout << "Intern can't create a form" << std::endl;
    return NULL;
}
