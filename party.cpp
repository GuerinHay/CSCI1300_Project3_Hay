#include "party.h"
#include <iostream>
using namespace std;


Party::Party(const string leaderName, const vector<string> &memberNames, int gold) {
    members.emplace_back(leaderName, 50);
    for (const auto &name : memberNames) {
        members.emplace_back(name, 50);
    }

    this->gold = gold;
    
    this->ingredients = 0;
    this->pots = 0;
    this->pans = 0;
    this->cauldrons = 0;
    this->clubs = 0;
    this->spears = 0;
    this->rapiers = 0;
    this->axes = 0;
    this->swords = 0;
    this->armor = 0;
    this->rings = 0;
    this->necklaces = 0;
    this->bracelets = 0;
    this->circlets = 0;
    this->goblets = 0;
    this->keys = 0;
    this->anger = 0;
}


void Party::displayStatus() const {
    // Calculate total cookware pieces
    int totalPots = getPots();
    int totalFryingPans = getPans();
    int totalCauldrons = getCauldrons();
    int totalCookware = totalPots + totalFryingPans + totalCauldrons;

    // Calculate total weapons and armor
    int totalClubs = getClubs();
    int totalSpears = getSpears();
    int totalRapiers = getRapiers();
    int totalAxes = getAxes();
    int totalSwords = getSwords();
    int totalArmor = getArmor();

    // Calculate total treasure items
    int totalRings = getRings();
    int totalNecklaces = getNecklaces();
    int totalBracelets = getBracelets();
    int totalCirclets = getCirclets();
    int totalGoblets = getGoblets();
    int keys = getKeys();
    int roomsCleared = getClearedRooms();
    int anger = getAnger();

    // Display status update header
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;

    // Display status update body
    cout << "| Rooms Cleared: " << roomsCleared << " | Keys: " << keys << " | Anger Level: " << anger << endl;
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << gold << endl;
    cout << "| Ingredients | " << ingredients << " kg" << endl;
    cout << "| Cookware    | P: " << totalPots << " | F: " << totalFryingPans << " | C: " << totalCauldrons << endl;
    cout << "| Weapons     | C: " << totalClubs << " | S: " << totalSpears << " | R: " << totalRapiers << " | B: " << totalAxes << " | L: " << totalSwords << endl;
    cout << "| Armor       | " << totalArmor << endl;
    cout << "| Treasures   | R: " << totalRings << " | N: " << totalNecklaces << " | B: " << totalBracelets << " | C: " << totalCirclets << " | G: " << totalGoblets << endl;
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;

    // Display party members' names and fullness levels
    for (const auto &member : members) {
        cout << "| " << member.getName() << " | Fullness: " << member.getFullness() << endl;
    }

    cout << "+-------------+" << endl;
}

void Party::setGold(int gold) {
    this->gold = gold;
}

void Party::addGold(int amount){
    gold += amount;
}
int Party::getGold() const {
    return gold;
}

void Party::subtractGold(int amount){
    gold -= amount;
}

int Party::getIngredients() const{
    return ingredients;
}

void Party::setIngredients(int amount) {
    ingredients += amount;
}

void Party::subtractIngredients(int amount){
    ingredients -= amount;
}

int Party::getPots() const{
    return pots;
}

void Party::setPots(int amount ){
    pots += amount;
}

int Party::getPans() const{
    return pans;
}

void Party::setPans(int amount){
    pans += amount;
}

int Party::getCauldrons() const{
    return cauldrons;
}

void Party::setCauldrons(int amount){
    cauldrons += amount;
}

int Party::getClubs() const{
    return clubs;
}

void Party::setClubs(int amount){
    clubs += amount;
}

int Party::getSpears() const{
    return spears;
}

void Party::setSpears(int amount){
    spears += amount;
}

int Party::getRapiers() const{
    return rapiers;
}

void Party::setRapiers(int amount){
    rapiers += amount;
}

int Party::getAxes() const{
    return axes;
}

void Party::setAxes(int amount){
    axes += amount;
}

int Party::getSwords() const{
    return swords;
}

void Party::setSwords(int amount){
    swords += amount;
}


int Party::getArmor() const{
    return armor;
}

void Party::setArmor(int amount){
    armor += amount;
}

int Party::getRings() const{
    return rings;
}

void Party::setRings(int amount){
    rings -= amount;
}

int Party::getNecklaces() const{
    return necklaces;
}

void Party::setNecklaces(int amount){
    necklaces -= amount;
}


int Party::getBracelets() const{
    return bracelets;
}

void Party::setBracelets(int amount){
    bracelets -= amount;
}

int Party::getCirclets() const{
    return circlets;
}

void Party::setCirclets(int amount){
    circlets -= amount;
}

int Party::getGoblets() const{
    return goblets;
}

void Party::setGoblets(int amount){
    goblets -= amount;
}

int Party::getKeys() const{
    return keys;
}

void Party::setKeys(int amount){
    keys += amount;
}

int Party::getAnger() const{
    return anger;
}

void Party::setAnger(int amount){
    anger++;
}
 vector<PartyMember> &Party::getMembers()  {
    return members;
}

int Party::getNumPartyMembers() const {
    return members.size();
}

PartyMember& Party::getPartyMember(int index) {
    return members[index];
}



void Party::removePartyMember(int index) {
    if (index >= 0 && index < members.size()) {
        members.erase(members.begin() + index);
    }
}


int Party::getTotalWeaponStrength() const {
    int totalWeaponStrength = 0;
    for (const auto& member : partyMembers) {
        
            totalWeaponStrength += weapon.getStrength();
        
    }
    return totalWeaponStrength;
}

int Party::getWeaponVariety() const {
    bool allSame = true;
    std::string weaponType;
    for (const auto& member : partyMembers) {
        if (weaponType.empty()) {
            weaponType = member.getWeapon();
        } else if (weaponType != member.getWeapon()) {
            allSame = false;
            break;
        }
    }
    return allSame ? 4 : 0;
}


int Party::getTotalArmorSets() const {
    int totalArmorSets = 0;
    for (const auto& member : partyMembers) {
        
            totalArmorSets += member.getArmor();
    }
    return totalArmorSets;
}

int Party::getClearedRooms() const {
    return clearedRooms;
}

void Party::addClearedRooms(int rooms) {
    clearedRooms++;
}

void Party::handleMisfortune() {
    int randomNum = rand() % 100 + 1; // Generate random number between 1 and 100
    if (randomNum <= 30) {
        // Robbery misfortune
        int randomItem = rand() % 3; // Generate random number between 0 and 2
        if (randomItem == 0) {
            // Lose 10 kg of ingredients
            ingredients -= 10;
            cout << "OH NO! Your team was robbed by dungeon bandits!\nYou lost 10 kg of ingredients!\n";
        } else if (randomItem == 1) {
            // Lose 1 cookware item
            pans -= 1;
            cout << "OH NO! Your team was robbed by dungeon bandits!\nYou lost 1 cookware item!\n";
        } else {
            // Lose 1 armor item
            
            cout << "OH NO! Your team was robbed by dungeon bandits!\nYou lost 1 armor item!\n";
        }
    } else if (randomNum <= 40) {
        // Weapon/armor breaking misfortune
        int randomMember = rand() % partyMembers.size(); // Generate random number between 0 and size of partyMembers vector - 1
        string weaponType = partyMembers[randomMember].getWeapon();
        if (weaponType != "None") {
            // If the party member has a weapon, it breaks
            partyMembers[randomMember].getWeapon();
            cout << "OH NO! Your " << weaponType << " broke!\n";
        } else {
            // If the party member doesn't have a weapon, a random armor item breaks
            int randomArmor = rand() % armor;
            armor -= 1;
            cout << "OH NO! One of your armor items broke!\n";
        }
    } else if (randomNum <= 70) {
        // Food poisoning misfortune
        int randomMember = rand() % partyMembers.size(); // Generate random number between 0 and size of partyMembers vector - 1
        int fullness = partyMembers[randomMember].getFullness();
        fullness -= 10;
        partyMembers[randomMember].setFullness(fullness);
        if (fullness <= 0) {
            // If hunger reaches 0, the party member dies of hunger
            partyMembers.erase(partyMembers.begin() + randomMember);
            cout << "OH NO! " << partyMembers[randomMember].getName() << " died of hunger!\n";
        } else {
            cout << "OH NO! " << partyMembers[randomMember].getName() << " got food poisoning and lost 10 points of hunger!\n";
        }
    } else {
        // Team member locked in previous room misfortune
        if (clearedRooms == 0) {
            // If no rooms have been cleared yet, nothing happens
            cout << "You can't be locked in the previous room if you haven't been in any rooms yet!\n";
        } else {
            // Choose a random party member to be locked in previous room
            int randomMember = rand() % partyMembers.size(); // Generate random
        }
    }}


