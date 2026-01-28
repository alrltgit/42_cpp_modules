#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain *br;

    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator = (const Dog& other);
        ~Dog();

        Brain* getBrain() const; 
        void makeSound() const;
};

#endif
