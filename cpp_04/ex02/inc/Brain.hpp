#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator = (const Brain& other);
        ~Brain();

        void displayIdea() const;
        void setIdea(int i, std::string idea);
};

#endif
