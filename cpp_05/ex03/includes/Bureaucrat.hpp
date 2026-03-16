#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat(int newGrade, std::string newName);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator = (const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName() const;
        const int& getGrade() const;
        
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& form);
        void executeForm(AForm const & form) const;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& br);

#endif
