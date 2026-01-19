#include "Zombie.hpp"

int main() {
    Zombie* Foo_heap = newZombie("Foo_heap");
    Foo_heap->announce();
    delete Foo_heap;

    randomChump("Foo_stack");

    return (0);
}
