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
        PhoneBook();
        ~PhoneBook();

        void add_contact(Contact user);
        std::string format_text(std::string text);
        std::string int_to_string(int num);
        void display_contacts();
        void ask_for_index();
        void display_chosen_contact(int idx);
};

#endif
