#include "Harl.hpp"

Harl::Harl() {
    ptrToFuncs[0] = &Harl::debug;
    ptrToFuncs[1] = &Harl::info;
    ptrToFuncs[2] = &Harl::warning;
    ptrToFuncs[3] = &Harl::error;
};

Harl::~Harl() {};

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
        << std::endl;
};

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
        << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

void Harl::complain(std::string level) {
    int i = 4;

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (i--) {
        if (levels[i] == level) {
            (this->*ptrToFuncs[i])();
            return ;
        }
    }
    std::cout << "Wrong level!" << std::endl;
}
