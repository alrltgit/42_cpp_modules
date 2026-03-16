#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    
    public:
        RobotomyRequestForm(const std::string& newTarget);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator = (const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void executeClassAction() const;

        class RobotomyFailed : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
