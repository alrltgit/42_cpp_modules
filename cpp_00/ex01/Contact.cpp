#include "Contact.hpp"
#include <iostream>

void Contact::set_contact() {
    std::cout << "First name: ";
    std::cin >> first_name;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }
    // if (!std::getline(std::cin, first_name))
    // {
    //     std::cout << std::endl;
    //     exit(0);
    // }

    std::cout << "Second name: ";
    std::cin >> last_name;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }
    // if (!std::getline(std::cin, last_name))
    // {
    //     std::cout << std::endl;
    //     exit(0);
    // }

    std::cout << "Nickname: ";
    std::cin >> nickname;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }
    // if (!std::getline(std::cin, nickname))
    // {
    //     std::cout << std::endl;
    //     exit(0);
    // }

    std::cout << "Phone number: ";
    std::cin >> phone_number;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }
    // if (!std::getline(std::cin, phone_number))
    // {
    //     std::cout << std::endl;
    //     exit(0);
    // }

    std::cout << "Darkest secret: ";
    std::cin >> darkest_secret;
    if (std::cin.eof())
    {
        std::cout << std::endl;
        exit(0);
    }
    // if (!std::getline(std::cin, darkest_secret))
    // {
    //     std::cout << std::endl;
    //     exit(0);
    // }
}
