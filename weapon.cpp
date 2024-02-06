#include "weapon.h"
using namespace std;

Weapon::Weapon(){
    type = "";
    strength = 0;
    cost = 0;
}

Weapon::Weapon(const string& type, int strength, int cost)
    : type(type), strength(strength), cost(cost) {
}

const string& Weapon::getType() const {
    return type;
}

int Weapon::getStrength() const {
    return strength;
}

int Weapon::getCost() const {
    return cost;
}

Weapon Weapon::createWeapon(const string& type) {
    if (type == "C") {
        return Weapon("Club", 1, 2);
    } else if (type == "S") {
        return Weapon("Spear", 1, 2);
    } else if (type == "R") {
        return Weapon("+1 Rapier", 2, 5);
    } else if (type == "B") {
        return Weapon("+2 Battle-axe", 3, 15);
    } else if (type == "L") {
        return Weapon("+3 Longsword", 4, 50);
    }
    return Weapon();
}
