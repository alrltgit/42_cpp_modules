#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

class Contact {
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact() {};
        // Contact(std::string first_name, std::string last_name, std::string phone_number, std::string darkest_secret); // constructor
        // Contact(const Contact& other); // copy constructor
        // Contact& operator=(const Contact& other); // copy assignment operator
        ~Contact() {}; // destructor

        void set_contact();
};

#endif
