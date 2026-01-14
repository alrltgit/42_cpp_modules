#include "Contact.hpp"
#include <iostream>

Contact::Contact() {};
Contact::~Contact() {};

void Contact::set_contact() {
    std::cout << "First name: " << std::endl;
    std::cin >> first_name;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }

    std::cout << "Last name: " << std::endl;
    std::cin >> last_name;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }

    std::cout << "Nickname: " << std::endl;
    std::cin >> nickname;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }

    std::cout << "Phone number: " << std::endl;
    std::cin >> phone_number;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }

    std::cout << "Darkest secret: " << std::endl;
    std::cin >> darkest_secret;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }
}
