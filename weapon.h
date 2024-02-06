#ifndef WEAPON_H
#define WEAPON_H


#include <string>
using namespace std;

class Weapon {
public:
    Weapon();
    Weapon(const string& type, int strength, int cost);

    const string& getType() const;
    int getStrength() const;
    int getCost() const;
     static Weapon createWeapon(const string& type);


private:
    std::string type;
    int strength;
    int cost;
};

#endif // WEAPON_H
