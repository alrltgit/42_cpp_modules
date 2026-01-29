#include "inc/Dog.hpp"
#include "inc/Animal.hpp"
#include "inc/Cat.hpp"
#include "inc/WrongAnimal.hpp"
#include "inc/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Cat *cat = new Cat();
    const Dog *dog = new Dog();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;

    j->makeSound();
    i->makeSound();
    meta->makeSound();
    cat->makeSound();
    dog->makeSound();

    delete j;
    delete i;
    delete meta;
    delete cat;
    delete dog;

    std::cout << "----------- Wrong class -----------" << std::endl;

    WrongAnimal* wA = new WrongAnimal();
    WrongAnimal* wrC = new WrongCat();
    WrongCat* wC = new WrongCat();

    std::cout << wA->getType() << " " << std::endl;
    std::cout << wrC->getType() << " " << std::endl;
    std::cout << wC->getType() << " " << std::endl;

    wA->makeSound();
    wrC->makeSound();
    wC->makeSound();

    delete wC;
    delete wrC;
    delete wA;

    return 0;
}
