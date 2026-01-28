#include "../inc/Brain.hpp"

Brain::Brain() {
    std::cout << "Brain: default constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain: copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator = (const Brain& other) {
    std::cout << "Brain: copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain: destructor called" << std::endl;
}

void Brain::displayIdea() const {
    for (int i = 0; i < 2; i++) {
        std::cout << ideas[i] << std::endl;
    }
}

void Brain::setIdea(int i, std::string idea) {
    ideas[i] = idea;   
}
