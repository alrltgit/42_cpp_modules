#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie();
        ~Zombie();

        const std::string& getName(void)const;
        void setName(std::string zombieName);
        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
