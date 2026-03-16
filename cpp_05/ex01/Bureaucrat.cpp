#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int newGrade, std::string newName)
    : name(newName), grade(newGrade)
{
    std::cout << "Bureaucrat constructor is called" << std::endl;

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    std::cout << "Bureaucrat copy constructor is called" << std::endl;
    *this = other;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& other)
{
    std::cout << "Bureaucrat assignment operator is called" << std::endl;
    if (this != &other)
        grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor is called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

const int& Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& br)
{
    o << br.getName() << ", bureaucrat grade " << br.getGrade() << std::endl;
    return o;
}
