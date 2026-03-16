#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& newTarget) : AForm(newTarget, 145, 137), target(newTarget)
{
    std::cout << "ShrubberyCreationForm constructor is called"<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
    std::cout << "ShrubberyCreationForm copy constructor is called"<< std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm copy assignment operator is called"<< std::endl;
    if (this != &other)
    {
        AForm::operator = (other);
        target = other.target;
    }
    return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm desctructor is called"<< std::endl;
}

void ShrubberyCreationForm::executeClassAction() const
{
    std::ofstream target_shrubbery((target + "_shrubbery").c_str());
    if (!target_shrubbery)
        throw FailedToOpenFile();

    target_shrubbery << std::endl;
    target_shrubbery << "      /\\" << std::endl;
    target_shrubbery << "     /  \\" << std::endl;
    target_shrubbery << "    /    \\" << std::endl;
    target_shrubbery << "   /      \\" << std::endl;
    target_shrubbery << "  /        \\" << std::endl;
    target_shrubbery << " /__________\\" << std::endl;
    target_shrubbery << " |           |" << std::endl;
    target_shrubbery << " |   _____   |" << std::endl;
    target_shrubbery << " |  |__|__|  |" << std::endl;
    target_shrubbery << " |  |__|__|  |" << std::endl;
    target_shrubbery << " |           |" << std::endl;
    target_shrubbery << " |___________|" << std::endl;
    target_shrubbery << " \\__________/" << std::endl;
    target_shrubbery << std::endl;
}

const char* ShrubberyCreationForm::FailedToOpenFile::what() const throw()
{
    return "Failed to open a file";
}
