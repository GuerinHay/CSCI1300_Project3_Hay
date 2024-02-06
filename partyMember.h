#ifndef PARTY_MEMBER_H
#define PARTY_MEMBER_H

#include <string>
#include <vector>
#include "weapon.h"
using namespace std;

class PartyMember {
public:
    PartyMember(const string &name, int fullness);

    const string &getName() const;
    int getFullness() const;
    void setFullness(int fullness);
    void reduceFullness(int fullness);
     string getWeapon() const;
    int getArmor() const;
    void setWeaponStrength(int strength);
     int getWeaponStrength() const;
   



private:
    string name;
    int fullness;
    int armor;
    Weapon weapon;
    int weaponStrength;
    

    
};

#endif 
