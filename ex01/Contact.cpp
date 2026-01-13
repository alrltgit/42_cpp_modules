#include "Contact.hpp"
#include <iostream>

void Contact::set_contact() {
    std::cout << "First name: ";
    if (!std::getline(std::cin, first_name))
    {
        std::cout << std::endl;
        exit(0);
    }

    std::cout << "Second name: ";
    if (!std::getline(std::cin, last_name))
    {
        std::cout << std::endl;
        exit(0);
    }

    std::cout << "Nickname: ";
    if (!std::getline(std::cin, nickname))
    {
        std::cout << std::endl;
        exit(0);
    }

    std::cout << "Phone number: ";
    if (!std::getline(std::cin, phone_number))
    {
        std::cout << std::endl;
        exit(0);
    }

    std::cout << "Darkest secret: ";
    if (!std::getline(std::cin, darkest_secret))
    {
        std::cout << std::endl;
        exit(0);
    }
}
