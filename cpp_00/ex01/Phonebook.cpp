#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream>
#include <string>

PhoneBook::PhoneBook() : contact_idx(0), oldest_contact_idx(0) {};
PhoneBook::~PhoneBook() {};

int PhoneBook::get_oldest_contact_idx() {
    return oldest_contact_idx;
}

int PhoneBook::get_contact_idx() {
    return contact_idx;
}

void PhoneBook::add_contact(Contact user) {
    if (contact_idx < 8) {
        contacts[contact_idx] = user;
        contact_idx++;
    } else {
        if (oldest_contact_idx == 8)
            oldest_contact_idx = 0;
        contacts[oldest_contact_idx] = user;
        oldest_contact_idx++;
    }
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
        if (contacts[i].get_first_name() != "") {
            std::cout << format_text(int_to_string(i)) << '|'
                << format_text(contacts[i].get_first_name()) << '|'
                << format_text(contacts[i].get_last_name()) << '|'
                << format_text(contacts[i].get_nickname()) << '|' << std::endl;
        }
    }
}

void PhoneBook::ask_for_index() {
    int idx;

    while (1) {
        if (contacts[0].get_first_name().empty())
            return ;
        std::cout << "Choose index from the list: " << std::endl;
        
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

        if (idx >= 0 && idx < 8 && !contacts[idx].get_first_name().empty()) {
            display_chosen_contact(idx);
            break ;
        }
        else
            std::cout << "Wrong index." << std::endl;
    }
}

void PhoneBook::display_chosen_contact(int idx) {
    std::cout << "Index: " << int_to_string(idx) << std::endl;
    std::cout << "First name: " << contacts[idx].get_first_name() << std::endl;
    std::cout << "Last name: " << contacts[idx].get_last_name() << std::endl;
    std::cout << "Nickname: " << contacts[idx].get_nickname() << std::endl;
}
