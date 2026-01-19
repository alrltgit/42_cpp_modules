#include "Harl.hpp"

Harl::Harl() {
    ptrToFuncs[0] = &Harl::debug;
    ptrToFuncs[1] = &Harl::info;
    ptrToFuncs[2] = &Harl::warning;
    ptrToFuncs[3] = &Harl::error;
};

Harl::~Harl() {};

void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
        << std::endl;
    std::cout << std::endl;
};

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << std::endl;
    std::cout << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
        << std::endl;
    std::cout << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
    std::cout << std::endl;
}

void Harl::complain(std::string level) {
    int i = 4;

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (i--) {
        if (levels[i] == level) {
            break ;
        }
    }
    switch (i) {
        case 0:
            (this->*ptrToFuncs[0])();
            (this->*ptrToFuncs[1])();
            (this->*ptrToFuncs[2])();
            (this->*ptrToFuncs[3])();
            break ;
        case 1:
            (this->*ptrToFuncs[1])();
            (this->*ptrToFuncs[2])();
            (this->*ptrToFuncs[3])();
            break ;
        case 2:
            (this->*ptrToFuncs[2])();
            (this->*ptrToFuncs[3])();
            break ;
        case 3:
            (this->*ptrToFuncs[3])();
            break ;
        default:
			std::cout << "[ Probably complaining about insignificant problems ]" 
				<< std::endl;
    }
}
