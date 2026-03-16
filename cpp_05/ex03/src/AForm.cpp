#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : isSigned(false)
{
    std::cout << "AForm constructor is called"<< std::endl;
}

AForm::AForm(std::string newName, int newSignGrade, int newExGrade) : name(newName), isSigned(false), signGrade(newSignGrade), exGrade(newExGrade)
{
    std::cout << "AForm parameterized constructor is called"<< std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), exGrade(other.exGrade)
{
    std::cout << "AForm copy constructor is called"<< std::endl;
}

AForm& AForm::operator = (const AForm& other)
{
    std::cout << "AForm copy assignment operator is called"<< std::endl;
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor is called"<< std::endl;
};

const std::string& AForm::getName() const
{
    return name;
}

const bool& AForm::getIsSigned() const
{
    return isSigned;
}

const int& AForm::getSignGrade() const
{
    return signGrade;
}

const int& AForm::getExGrade() const
{
    return exGrade;
}

void AForm::beSigned(const Bureaucrat& br)
{
    if (br.getGrade() >= signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned || executor.getGrade() > exGrade)
        throw GradeTooLowException();
    executeClassAction();
}

std::ostream& operator<<(std::ostream& o, const AForm& fr)
{
    o << "AForm " << fr.getName() << " is signed: " << (fr.getIsSigned() ? "True" : "False") << ". Grade to sign: " << fr.getSignGrade() << ". Grade to execute: " << fr.getExGrade() << std::endl;
    return o;
}
