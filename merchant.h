#include <iostream>
#include <string>
#include <vector>
#include "party.h"

class Merchant {
public:
    void displayInventory(Party &party);
    void buyIngredients(Party &party);
    void buyCookware(Party &party);
    void buyWeapons(Party &party);
    void buyArmor(Party &party);
    void sellTreasures(Party &party);
    void merchantMenu(Party &party);
};
