#include <iostream>
#include <string>
#include <fstream>
#include "map.h"
#include "merchant.h"
#include "monster.h"
#include "party.h"
#include "partyMember.h"
#include "weapon.h"



class DungeonEscape {
private:
    Party party;
    Map game_map;
    Monster monster;
    vector<Monster> createMonsterList;

public:
    DungeonEscape();
    DungeonEscape(const string &leaderName, const vector<string> &memberNames, int gold, const Map &game_map);
    void play();
    void playerTurn();
    void move(char direction);
    void investigate(Party& party);
    void pickFight(Party& party);
    void cookAndEat(Party& party);
    void giveUp();
    void NPCSpace(Party& party);
    void roomAction(Party& party, Map& gameMap);
    bool doorPuzzle(Party& party);
    void handleRoomEncounter(Party& party, int& clearedRooms,Map& gameMap );
    bool battleResult(Party& party, int challengeRating);
};
