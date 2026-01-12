#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream>

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
            return text.substr(0, 9) + '.';
    std::string right_align(10 - text.length(), ' '); // std::string constructor;
    return right_align + text;
}

std::string PhoneBook::int_to_string(int num) {
    std::stringstream str;
    str << num;
    return str.str();
}

int PhoneBook::string_to_int(std::string str) {
    int final_num = 0;

    std::stringstream num;
    num << str;
    num >> final_num;
    return final_num;
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
    std::string chosen_contact;
    int idx;

    while (1) {
        std::cout << "Choose index from the list: ";
        std::cin >> idx;
        if (std::cin.fail()) { // check if the input is of the same type as the variable we try to insert the input to to
            std::cin.clear(); // clear the error flags on the input stream
            std::cin.ignore(1000, '\n'); //  ignore (or discard) certain number of characters from the input buffer
            std::cout << "Wrong index." << std::endl;
            continue ;
        }

        if ((idx < contact_idx) || idx == 7) {
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
