#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int contact_idx;
        int oldest_contact_idx;
    
    public:
        PhoneBook();
        ~PhoneBook();

        // getters
        int get_oldest_contact_idx();
        int get_contact_idx();
    
        void add_contact(Contact user);
        std::string format_text(std::string text);
        std::string int_to_string(int num);
        void display_contacts();
        void ask_for_index();
        void display_chosen_contact(int idx);
};

#endif
