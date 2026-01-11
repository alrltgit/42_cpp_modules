#include "Contact.hpp"
#include <iostream>

// call the constructor
// Contact::Contact(std::string first_name, std::string last_name, std::string phone_number, std::string darkest_secret) {
//     std::cout << "Counstructor called";
//     this->first_name = first_name;
//     this->last_name = last_name;
//     this->phone_number = phone_number;
//     this->darkest_secret = darkest_secret;
// }

void Contact::set_contact() {
    // store first name
    std::cout << "First name: ";
    std::cin >> first_name;

    // store second name
    std::cout << "Second name: ";
    std::cin >> last_name;

    // store nickname
    std::cout << "Nickname: ";
    std::cin >> nickname;

    // store phone number
    std::cout << "Phone number: ";
    std::cin >> phone_number;

    // store darkest secret
    std::cout << "Darkest secret: ";
    std::cin >> darkest_secret;
}
