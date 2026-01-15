#include "Zombie.hpp"

int main() {
    Zombie Foo("Foo"); // instantiate class Zombie
    Foo.announce();

    Zombie* Foo_heap = newZombie("Foo_heap"); // create a zombie object using dynamic allocation
    Foo_heap->announce(); // announce 
    delete Foo_heap; // deallocate memory

    randomChump("Foo_stack"); // the function allocates memory in stack, creates a zombie object, announces itself and dellocates memory when the function finishes

    return (0);
}
