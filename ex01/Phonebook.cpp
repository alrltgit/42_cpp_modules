#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::add_contact(Contact user) {
    if (contact_idx == 7)
        this->contacts[contact_idx] = user;
    this->contacts[contact_idx] = user;
    contact_idx++;
};

void PhoneBook::display_contacts() {
    std::cout << "    index|" << "first name|" << " last name|" << "  nickname|"
}
