#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& newTarget) : AForm(newTarget, 25, 5), target(newTarget)
{
    std::cout << "PresidentialPardonForm constructor is called"<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
    std::cout << "PresidentialPardonForm copy constructor is called"<< std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& other)
{
    std::cout << "PresidentialPardonForm copy assignment operator is called"<< std::endl;

    if (this != &other)
    {
        AForm::operator = (other);
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor is called"<< std::endl;
}

void PresidentialPardonForm::executeClassAction() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
