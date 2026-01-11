#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    std::string cmd;
    Contact user;
    PhoneBook phonebook;

    // cmd = "ADD";

    while (cmd != "EXIT") {
        std::cout << "Type one of three commands (ADD, SEARCH or EXIT): ";
        std::cin >> cmd;

        if (cmd == "ADD") {
            user.set_contact();
            phonebook.add_contact(user);
        }
        else if (cmd == "SEARCH") {
            phonebook.display_contacts();
        }

        // for (int i = 0; i < 2; i++) {
        //     std::cout << phone_book.contacts[i].first_name << '\n';
        //     std::cout << phone_book.contacts[i].last_name << '\n';
        //     std::cout << phone_book.contacts[i].nickname << '\n';
        //     std::cout << phone_book.contacts[i].phone_number << '\n';
        //     std::cout << phone_book.contacts[i].darkest_secret << '\n';
        // }

    }
    return 0;
}

