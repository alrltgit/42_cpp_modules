#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int exGrade;

    public:
        Form(std::string newName, int newSignGrade, int newExGrade);
        Form(const Form& other);
        Form& operator = (const Form& other);
        ~Form();

        const std::string& getName() const;
        const bool& getIsSigned() const;
        const int& getSignGrade() const;
        const int& getExGrade() const;
        void beSigned(const Bureaucrat& br);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, const Form& fr);

#endif
