#include "Zombie.hpp"

int main() {
    int N = 6;
    Zombie *zombies = zombieHorde(N, "Bob");

    // test
    for(int i = 0; i < N; i++) {
        // std::cout << zombies[i].getName() << std::endl;
        zombies[i].announce();
    }
    delete[] zombies;
    return (0);
}
