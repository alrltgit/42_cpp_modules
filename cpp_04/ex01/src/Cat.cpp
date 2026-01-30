#include "../inc/Cat.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat: default constructor called" << std::endl;
    type = "Cat";
    br = new Brain();
};

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat: copy constructor called" << std::endl;
    br = NULL;
    *this = other;
}

Cat& Cat::operator = (const Cat& other) {
    std::cout << "Cat: copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator = (other);
        if (br)
            delete br;
        br = new Brain(*other.br);
    }

    return *this;
}

Cat::~Cat() {
    delete br;
    std::cout << "Cat: destructor called" << std::endl;
}

Brain* Cat::getBrain() const {
    return br;
}

void Cat::makeSound() const {
    std::cout << "Cat makes a sound: Meow Meow!" << std::endl;
}
