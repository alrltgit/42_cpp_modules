#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm(const std::string& newTarget);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator = (const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        void executeClassAction() const;
};

#endif
