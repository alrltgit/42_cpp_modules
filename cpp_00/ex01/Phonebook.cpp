#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream>
#include <string>

PhoneBook::PhoneBook() : contact_idx(0) {};

void PhoneBook::add_contact(Contact user) {
    if (user.first_name.empty() || user.last_name.empty() 
        || user.nickname.empty() || user.phone_number.empty()
        || user.darkest_secret.empty())
        return ;
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
            return text.substr(0, 9) + '.';
    std::string right_align(10 - text.length(), ' ');
    return right_align + text;
}

std::string PhoneBook::int_to_string(int num) {
    std::stringstream str;
    str << num;
    return str.str();
}

void PhoneBook::display_contacts() {
    std::cout << format_text("index") << '|' 
            << format_text("first name") << '|'
            << format_text("last name") << '|'
            << format_text("nickname") << '|' << std::endl;
    for (int i = 0; i < 8; i++) {
        if (contacts[i].first_name != "") {
            std::cout << format_text(int_to_string(i)) << '|'
                << format_text(contacts[i].first_name) << '|'
                << format_text(contacts[i].last_name) << '|'
                << format_text(contacts[i].nickname) << '|' << std::endl;
        }
    }
}

void PhoneBook::ask_for_index() {
    int idx;

    while (1) {
        if (contacts[0].first_name.empty())
            return ;
        std::cout << "Choose index from the list: ";
        
        std::cin >> idx;
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        else if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Wrong index." << std::endl;
            continue ;
        }

        if (idx < contact_idx || idx == 7) {
            display_chosen_contact(idx);
            break ;
        }
        else
            std::cout << "Wrong index." << std::endl;
    }
}

void PhoneBook::display_chosen_contact(int idx) {
    std::cout << "Index: " << int_to_string(idx) << std::endl;
    std::cout << "First name: " << contacts[idx].first_name << std::endl;
    std::cout << "Last name: " << contacts[idx].last_name << std::endl;
    std::cout << "Nickname: " << contacts[idx].nickname << std::endl;
}

PhoneBook::~PhoneBook() {};
