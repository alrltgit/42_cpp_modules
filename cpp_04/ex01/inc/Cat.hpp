#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *br;

    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator = (const Cat& other);
        ~Cat();

        Brain* getBrain() const ;
        void makeSound() const ;
};

#endif
