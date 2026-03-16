#ifndef SHRUBERRY_CREATION_FORM_HPP
#define SHRUBERRY_CREATION_FORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm(const std::string& newTarget);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator = (const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        void executeClassAction() const;

        class FailedToOpenFile : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
