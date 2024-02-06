#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>
using namespace std;

class Monster {
public:
    Monster();
    Monster(const string& name, int challengeRating, int goldReward, int ingredientReward);

    const string& getName() const;
    int getChallengeRating() const;
    int getGoldReward() const;
    int getIngredientReward() const;
    void setDefeated(bool defeated);

    static vector<Monster> createMonsterList();

private:
    string name;
    int challengeRating;
    int goldReward;
    int ingredientReward;
};

#endif 

