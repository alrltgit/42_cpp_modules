#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

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
        ~Form();

        const std::string& getName() const;
        const bool& getIsSigned() const;
        const int& getSignGrade() const;
        const int& getExGrade() const;

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        void beSigned(const Bureaucrat& br);
};

std::ostream& operator<<(std::ostream& o, const Form& fr);

#endif
