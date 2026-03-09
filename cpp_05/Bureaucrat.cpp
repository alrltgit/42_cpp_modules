#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int new_grade) : grade(new_grade) {
    std::cout << "Construct is called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor is called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const std::string& Bureaucrat::get_name() const
{
    return name;
}

const int& Bureaucrat::get_grade() const
{
    return grade;
}
