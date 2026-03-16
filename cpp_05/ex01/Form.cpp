#include "Form.hpp"

Form::Form(std::string newName, int newSignGrade, int newExGrade) : name(newName), isSigned(false), signGrade(newSignGrade), exGrade(newExGrade)
{
    std::cout << "Form constructor is called"<< std::endl;
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), exGrade(other.exGrade)
{
    std::cout << "Form copy constructor is called"<< std::endl;
}

Form& Form::operator = (const Form& other)
{
    std::cout << "Form copy assignment operator is called"<< std::endl;
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor is called"<< std::endl;
};

const std::string& Form::getName() const
{
    return name;
}

const bool& Form::getIsSigned() const
{
    return isSigned;
}

const int& Form::getSignGrade() const
{
    return signGrade;
}

const int& Form::getExGrade() const
{
    return exGrade;
}

void Form::beSigned(const Bureaucrat& br)
{
    if (br.getGrade() >= signGrade)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& o, const Form& fr)
{
    o << "Form " << fr.getName() << " is signed: " << (fr.getIsSigned() ? "True" : "False") << ". Grade to sign: " << fr.getSignGrade() << ". Grade to execute: " << fr.getExGrade() << std::endl;
    return o;
}
