#include "monster.h"
#include <vector>
using namespace std;

Monster::Monster(){ // Initializing values for defalt constructor.
    name = "";
    challengeRating = 1;
    goldReward = 1;
    ingredientReward=1;
}

Monster::Monster(const string& name, int challengeRating, int goldReward, int ingredientReward) // Initializing values for parameterized constructor that will be passed through later.
    : name(name), challengeRating(challengeRating), goldReward(goldReward), ingredientReward(ingredientReward) {}

const string& Monster::getName() const {
    return name;
} 
/* getters used to get the name challenge rating
gold reward and ingredient reward for defeating a monster
as well as one setter that sets a monster as defeated after a succesfull battle.*/
int Monster::getChallengeRating() const {
    return challengeRating;
}

int Monster::getGoldReward() const {
    return goldReward;
}

int Monster::getIngredientReward() const {
    return ingredientReward;
}

void Monster::setDefeated(bool defeated){
    defeated = true;
}

  vector<Monster> Monster::createMonsterList() { // Vector that holds all of the details of the different monsters.
    return {
        {"Animated Armor", 1, 10, /* ingredientReward */ 5},
        {"Bugbear", 1, /* goldReward */ 10, /* ingredientReward */ 5},
        {"Harpy", 1, /* goldReward */ 10, /* ingredientReward */ 5},
        {"Scarecrow", 1, /* goldReward */ 10, /* ingredientReward */ 5},
        {"Minotaur", 2, /* goldReward */ 20, /* ingredientReward */ 10},
        {"Owlbear", 2, /* goldReward */ 20, /* ingredientReward */ 10},
        {"Banshee", 2, /* goldReward */ 20, /* ingredientReward */ 10},
        {"Wereboar", 2, /* goldReward */ 20, /* ingredientReward */ 10},
        {"Giant Crocodile", 3, /* goldReward */ 30, /* ingredientReward */ 15},
        {"Troll", 3, /* goldReward */ 30, /* ingredientReward */ 15},
        {"Hobgoblin Warlord", 3, /* goldReward */ 30, /* ingredientReward */ 15},
        {"Mammoth", 3, /* goldReward */ 30, /* ingredientReward */ 15},
        {"Stone Giant", 4, /* goldReward */ 40, /* ingredientReward */ 20},
        {"Night Hag", 4, /* goldReward */ 40, /* ingredientReward */ 20},
        {"Assassin", 4, /* goldReward */ 40, /* ingredientReward */ 20},
        {"Hydra", 4, /* goldReward */ 40, /* ingredientReward */ 20},
        {"Cloud Giant", 5, /* goldReward */ 50, /* ingredientReward */ 25},
        {"Silver Dragon", 5, /* goldReward */ 50, /* ingredientReward */ 25},
        {"Vampire", 5, /* goldReward */ 50, /* ingredientReward */ 25},
        {"Lich", 5, /* goldReward */ 50, /* ingredientReward */ 25},
        {"Sorcerer", 6, 6*10,6*5}
    };
}

