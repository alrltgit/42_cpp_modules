#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::add_contact(Contact user) {
    if (contact_idx == 7)
    {
        contacts[contact_idx] = user;
        return ;
    }
    contacts[contact_idx] = user;
    contact_idx++;
};

std::string PhoneBook::format_text(std::string text) {
    if (text.length() > 10)
            return text.substr(0, 9) + '.'; // if text is bigger that 10 chars, truncate the text with dot
    return std::string(10 - text.length(), ' ') + text; // right-align padding
}

void PhoneBook::display_contacts() {
    std::cout << format_text("index") << '|' 
            << format_text("first name") << '|'
            << format_text("last name") << '|'
            << format_text("nickname") << '|' << std::endl;
    for (int i = 0; i < 8; i++) {
        if (contacts[i].first_name != "") {
            std::cout << format_text(std::to_string(i)) << '|'
                << format_text(contacts[i].first_name) << '|'
                << format_text(contacts[i].last_name) << '|'
                << format_text(contacts[i].nickname) << '|' << std::endl;
        }
    }
}
