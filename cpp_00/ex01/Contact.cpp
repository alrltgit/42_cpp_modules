#include "Contact.hpp"
#include <iostream>
#include <cctype>

Contact::Contact() {};
Contact::~Contact() {};

std::string Contact::get_first_name() {
    return first_name;
}

std::string Contact::get_last_name() {
    return last_name;
}

std::string Contact::get_nickname() {
    return nickname;
}

std::string Contact::get_phone_number() {
    return phone_number;
}

std::string Contact::get_darkest_secret() {
    return darkest_secret;
}

bool Contact::valid_number(std::string phone_number) {
    bool valid = true;

    for (size_t i = 0; i < phone_number.length(); i++) {
        if (!std::isdigit(static_cast<unsigned char>(phone_number[i]))) {
            std::cout << "Wrong format." << std::endl;
            valid = false;
            break ;
        }
    }
    return valid;
}

void Contact::set_contact() {
    std::cout << "First name: " << std::endl;
    std::cin >> first_name;
    if (std::cin.eof()) {
        std::cout << std::endl;
        exit(0);
    }

    std::cout << "Last name: " << std::endl;
    std::cin >> last_name;
    if (std::cin.eof()) {
        std::cout << std::endl;
        exit(0);
    }

    std::cout << "Nickname: " << std::endl;
    std::cin >> nickname;
    if (std::cin.eof()) {
        std::cout << std::endl;
        exit(0);
    }

    while (1) {
        std::cout << "Phone number: " << std::endl;
        std::cin >> phone_number;
        if (std::cin.eof()) {
            std::cout << std::endl;
            exit(0);
        }
        if (valid_number(phone_number))
            break ; 
    }

    std::cout << "Darkest secret: " << std::endl;
    std::cin >> darkest_secret;
    if (std::cin.eof()) {
        std::cout << std::endl;
        exit(0);
    }
}
