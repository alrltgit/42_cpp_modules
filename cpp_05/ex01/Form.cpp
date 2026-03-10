#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string newName, int newSignGrade, int newExGrade) : name(newName), signGrade(newSignGrade), exGrade(newExGrade)
{
    isSigned = false;
    std::cout << "Constructor is called"<< std::endl;
}

Form::~Form() {
    std::cout << "Destructor is called"<< std::endl;
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
    try
    {
        if (br.get_grade() >= signGrade)
            throw GradeTooLowException();

        isSigned = true;
    }
    catch(GradeTooLowException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& o, const Form& fr)
{
    o << fr.getName() << fr.getIsSigned() << fr.getSignGrade() << fr.getExGrade() << std::endl;
    return o;
}
