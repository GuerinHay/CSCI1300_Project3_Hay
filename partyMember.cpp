#include "partyMember.h"
using namespace std;

PartyMember::PartyMember(const string &name, int fullness) : name(name), fullness(fullness), weapon(weapon) {
    
}

const string &PartyMember::getName()  const{
    return name;
}

int PartyMember::getFullness() const {
    return fullness;
}

void PartyMember::setFullness(int fullness) {
    this->fullness = fullness;
}

void PartyMember::reduceFullness(int amount){
    fullness -= amount;
}

int PartyMember::getArmor() const{
    return armor;
}

string PartyMember::getWeapon() const {
    return weapon.getType();
}

void PartyMember::setWeaponStrength(int strength){
    weaponStrength = weapon.getStrength();
}

int PartyMember::getWeaponStrength() const {
    return weaponStrength;
}




