#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& newTarget) : AForm(newTarget, 72, 45), target(newTarget)
{
    std::cout << "RobotomyRequestForm constructor is called"<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
    std::cout << "RobotomyRequestForm copy constructor is called"<< std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm copy assignment operator is called"<< std::endl;
    if (this != &other)
    {
        AForm::operator = (other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor is called"<< std::endl;
}

void RobotomyRequestForm::executeClassAction() const
{
    std::cout << "brrrrrr brrrrrr. Target has been robotomized successfully 50% of the time!" << std::endl;
    srand(time(NULL)); // changes the starting point of the sequence; without it the program will generate the same numbers
    
    if (rand() % 2) // 
        std::cout << target << " has been robotomized successfully 50% of the time" << std::endl;
    else
        throw RobotomyFailed();
}

const char* RobotomyRequestForm::RobotomyFailed::what() const throw()
{
    return "Robotomy failed!";
}
