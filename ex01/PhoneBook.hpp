#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include "Contact.hpp"

class PhoneBook {
    public:
        Contact contacts[8];
    
    private:
        int contact_idx;
    
    public:
        PhoneBook() {
            this->contact_idx = 0;
        }; // constructor
        // PhoneBook(const PhoneBook &other);
        // PhoneBook& operator = (const PhoneBook& other);
        ~PhoneBook() {}; // destructor 

        void add_contact(Contact user);
        std::string format_text(std::string text);
        void display_contacts();
};

#endif
