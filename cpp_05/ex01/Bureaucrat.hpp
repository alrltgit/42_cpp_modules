#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

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

        const std::string& getName() const;
        const int& getGrade() const;

        void incrementGrade();
        void decrementGrade();
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& br);

#endif
