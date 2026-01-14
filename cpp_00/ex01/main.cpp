#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    std::string cmd;
    Contact user;
    PhoneBook phonebook;

    while (cmd != "EXIT") {
        std::cout << "Type one of three commands (ADD, SEARCH or EXIT): ";
    
        std::cin >> cmd;
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        // if (!std::getline(std::cin, cmd))
        // {
        //     std::cout << std::endl;
        //     exit(0);
        // }
        if (cmd == "ADD") {
            user.set_contact();
            phonebook.add_contact(user);
        }
        else if (cmd == "SEARCH") {
            phonebook.display_contacts();
            phonebook.ask_for_index();
        }
    }
    return 0;
}

