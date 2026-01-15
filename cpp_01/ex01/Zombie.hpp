#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string zombieName);    
        ~Zombie(void);

        const std::string& getName(void)const; // getter
        void setName(std::string zombieName);
        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
