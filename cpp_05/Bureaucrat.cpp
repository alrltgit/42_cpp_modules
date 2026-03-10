#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int new_grade, std::string new_name) : name(new_name), grade(new_grade) {
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

void Bureaucrat::increment_grade()
{
    try 
    {
        if (grade - 1 < 1)
            throw GradeTooHighException();
        grade--;
    }
    catch (GradeTooHighException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void Bureaucrat::decrement_grade()
{
    try
    {
        if (grade + 1 > 150)
            throw GradeTooLowException();
        grade++;
    }
    catch (GradeTooLowException& e)
    {
        std::cout << "Excepion caught: " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& br)
{
    o << br.get_name() << ", bureaucrat grade " << br.get_grade() << std::endl;
    return o;
}
