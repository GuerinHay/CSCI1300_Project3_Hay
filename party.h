#ifndef PARTY_H
#define PARTY_H

#include <vector>
#include <string>
#include "partyMember.h"
#include "weapon.h"
using namespace std;

class Party {
public:
    Party( string leaderName, const vector<string> &memberNames, int gold);

    void displayStatus() const;

    void addGold(int amount);
    int getGold() const;
    void setGold(int amount);
    void subtractGold(int amount);

    int getIngredients() const;
    void setIngredients(int amount); // getters and setters for all party attributes.
    void subtractIngredients(int amount);

    int getPots() const;
    void setPots(int amount);

    int getPans() const;
    void setPans(int amount);

    int getCauldrons() const;
    void setCauldrons(int amount);

    int getClubs() const;
    void setClubs(int amount);

    int getSpears() const;
    void setSpears(int amount);

    int getRapiers() const;
    void setRapiers(int amount);

    int getAxes() const;
    void setAxes(int amount);

    int getSwords() const;
    void setSwords(int amount);
    

    int getArmor() const;
    void setArmor(int amount);

    int getRings() const;
    void setRings(int amount);

     int getNecklaces() const;
    void setNecklaces(int amount);

     int getBracelets() const;
    void setBracelets(int amount);

     int getCirclets() const;
    void setCirclets(int amount);

     int getGoblets() const;
    void setGoblets(int amount);

    int getKeys() const;
    void setKeys(int amount);



    int getAnger() const;
    void setAnger(int amount);

    

    vector<PartyMember> &getMembers();
    vector<PartyMember> partyMembers;
    int getNumPartyMembers() const; // added function to get number of party members
    PartyMember& getPartyMember(int index) ; // gets a specific party member
    void removePartyMember(int index);

    int getTotalWeaponStrength() const;
    int getWeaponVariety() const;
    int getTotalArmorSets() const;

    int getClearedRooms() const;
    void addClearedRooms(int rooms);

    void handleMisfortune() ;

    bool isGameOver() const;


private:
    vector<PartyMember> members;
    int gold;
    int ingredients;
    int pots;
    int pans;
    int cauldrons;

    int armor;
    int anger;
    int keys;
    int clearedRooms;

    int rings;
    int necklaces;
    int bracelets;
    int circlets;
    int goblets;


    int clubs;
    int spears;
    int rapiers;
    int axes;
    int swords;
    int weaponStrength;
    Weapon weapon;

    
};

#endif 
