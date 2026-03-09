#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name = "Bureaucrat";
        int grade;

    public:
        Bureaucrat(int new_grade);
        ~Bureaucrat();

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        const std::string& get_name() const;
        const int& get_grade() const;
};

#endif
