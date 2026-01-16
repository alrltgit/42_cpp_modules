#include "Weapon.hpp"

Weapon::Weapon(std::string newType) : type(newType) {};

Weapon::~Weapon() {};

const std::string& Weapon::getType() const { return type; };

void Weapon::setType(std::string newType) {
    type = newType;
};
