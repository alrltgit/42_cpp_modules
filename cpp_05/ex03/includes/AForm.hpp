#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
    protected:
        const std::string name;
        bool isSigned;
        int signGrade;
        int exGrade;

    public:
        AForm();
        AForm(std::string newName, int newSignGrade, int newExGrade);
        AForm(const AForm& other);
        AForm& operator = (const AForm& other);
        virtual ~AForm();

        const std::string& getName() const;
        const bool& getIsSigned() const;
        const int& getSignGrade() const;
        const int& getExGrade() const;

        void beSigned(const Bureaucrat& br);
        virtual void executeClassAction() const = 0;
        void execute(Bureaucrat const & executor) const;

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

#endif
