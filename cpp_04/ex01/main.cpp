#include "inc/Dog.hpp"
#include "inc/Animal.hpp"
#include "inc/Cat.hpp"
#include "inc/Brain.hpp"

int main()
{
    Animal* arr[4];

    arr[0] = new Cat();
    arr[1] = new Cat();
    arr[2] = new Dog();
    arr[3] = new Dog();

    for (int i = 0; i < 4; i++) {
        arr[i]->makeSound();
    }

    for (int i = 0; i < 4; i++) {
        delete arr[i];
    }

    Cat* cat = new Cat();
    Dog* dog = new Dog();

    cat->getBrain()->setIdea(0, "Cat: Idea #1");
    cat->getBrain()->setIdea(1, "Cat: Idea #2");
    dog->getBrain()->setIdea(0, "Dog: Idea #1");
    dog->getBrain()->setIdea(1, "Dog: Idea #2");
    dog->getBrain()->setIdea(2, "Dog: Idea #3");

    std::cout << "----- Cat ideas -----" << std::endl;
    cat->getBrain()->displayIdea();

    std::cout << "----- Dog ideas -----" << std::endl;
    dog->getBrain()->displayIdea();

    delete cat;
    delete dog;

    return 0;
}
