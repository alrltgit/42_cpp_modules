#include "../inc/Dog.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog: default constructor called" << std::endl;
    type = "Dog";
    br = new Brain();
};

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog: copy constructor called" << std::endl;
    br = NULL;
    *this = other;
}

Dog& Dog::operator = (const Dog& other) {
    std::cout << "Dog: copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator = (other);
        if (br)
            delete br;
        br = new Brain(*other.br);
    }
    return *this;
}

Dog::~Dog() {
    delete br;
    std::cout << "Dog: destructor called" << std::endl;
}

Brain* Dog::getBrain() const {
    return br;
}

void Dog::makeSound() const {
    std::cout << "Dog makes a sound: Woof Woof!" << std::endl;
}
