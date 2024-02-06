#include "DungeonEscape.h"
#include "map.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;




bool DungeonEscape::battleResult(Party& party, int challengeRating) { // Function for determing battle outcomes
    int weaponStrength = party.getTotalWeaponStrength();
    int weaponDiversity = party.getWeaponVariety() == 4 ? 4 : 0; // Creating variables for outcome equations by calling functions from party class.
    int armor = party.getArmor();
    int monsterChallenge = challengeRating;
    int random1 = rand() % 6 + 1;
    int random2 = rand() % 6 + 1; // Creating random numbers

    double outcome = (random1 * weaponStrength + weaponDiversity) * ((random2 * challengeRating) / (armor)); // battle result.

    if (outcome > 0) {
        // The party wins the battle
        int goldReward = challengeRating * 10; // variables for potential battle rewards
        int ingredientReward = challengeRating * 5;
        int keyReward = 1;
        party.addGold(goldReward); // Adding rewards to party object.
        party.setIngredients(ingredientReward);
        cout << "You have slain the monster! For your valiant effor you are rewarded " << goldReward << " gold! " << endl;
        cout << keyReward << " keys! " << " and " << ingredientReward << " ingredients! " << endl;  

        // 10% chance to drop a key
        if (rand() % 100 < 10) {
            party.setKeys(1);
        }

        return true;
    } else {
        // The party loses the battle
        int goldLoss = party.getGold() / 4;
        int ingredientLoss = min(30, party.getIngredients());
        party.subtractGold(goldLoss);
        party.subtractIngredients(ingredientLoss);
        cout << "Your party fought valiantly, but the monster proved too difficult! " << endl;
        cout << "You have lost " << goldLoss << " gold, " << ingredientLoss << " ingredients, and your friend! " << endl;

        // Each party member (excluding the player) has a chance of being slain
        party.removePartyMember(2);

        return false;
    }
}



DungeonEscape::DungeonEscape(const string &leaderName, const vector<string> &memberNames, int gold, const Map &game_map)
    : party(leaderName, memberNames, gold), game_map(game_map), createMonsterList(Monster::createMonsterList()){}
// Parameterized constructor.
void DungeonEscape::move(char direction) {
    char input; // Creating move set.
    Map gameMap;
    cout << "Enter your move (WASD): ";
        cin >> input;
        

        if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
            bool moveResult = gameMap.move(input);
            if (moveResult) {
                cout << "Player moved successfully in direction: " << input << endl;
                gameMap.displayMap();
                party.setAnger(1);
            } else {
                cout << "Invalid move" << endl;
                gameMap.displayMap();
            }
        } else {
            cout << "Invalid input, use WASD keys to move " << endl;
        }
    }


void DungeonEscape::investigate(Party& party) { // Function for investigating a space.
      int currentRow = game_map.getPlayerRow();
      int currentColumn = game_map.getPlayerCol(); // Creating variables for player position.

    if (game_map.isExplored(currentRow, currentColumn)) {
        cout << "This space has already been investigated. Choose another action." << endl;
        return; // If space has been investigated do something else.
    }

    game_map.exploreSpace(currentRow, currentColumn); // Mark the space as explored

    srand(time(0)); // Seed the random number generator
    int randomChance = rand() % 100; // Generate a random number between 0 and 99

    if (randomChance < 10) {
        // 10% chance to find a key
        cout << "You found a key!" << endl;
        party.setKeys(1);
        game_map.displayMap(); // Displaying ususal map and status update after every outcome.
        party.displayStatus();
    } else if (randomChance < 30) {
        // 20% chance to find a treasure
        cout << "You found a piece of treasure!" << endl;
        party.setRings(1); 
        game_map.displayMap();
        party.displayStatus();
    } else if (randomChance < 50) {
        // 20% chance to fight a random monster
        cout << "A wild monster appears!" << endl;
        game_map.displayMap();
        party.displayStatus();
        pickFight(party);
        bool wonFight = battleResult(party, 3);

        if (wonFight) {
            int keyDropChance = rand() % 100;
            if (keyDropChance < 10) {
                // 10% chance the monster drops a key
                cout << "The defeated monster dropped a key!" << endl;
                party.setKeys(1);

            }
        }
    } else {
        // 50% chance of nothing happening
        cout << "You found nothing of interest." << endl;
        game_map.displayMap();
        party.displayStatus();
    }

    // 50% chance to reduce fullness level for each party member
    for ( PartyMember &member : party.getMembers()) {
        int fullnessDropChance = rand() % 100;
        if (fullnessDropChance < 50) {
            member.reduceFullness(5); // Reduciing fullness of a player
        }
    }
}


void DungeonEscape::pickFight(Party& party) {
    srand(time(NULL));
    Monster monsterCreator; 
    vector<Monster> monsterList = monsterCreator.createMonsterList();
    int index = rand() % monsterList.size();
    Monster monster = monsterList[index];

    cout << "The party has encountered a " << monster.getName() << "!" << endl;
    
    cout << "1. Do you want to attack " << monster.getName() << "? (Y/N): ";
    char decision;
    cin >> decision;

    if (decision == 'Y' || decision == 'y') {
        bool result = battleResult(party, 4);
        if (result) {
            cout << "You won the fight!" << endl;
            party.displayStatus();
            game_map.displayMap();
        } else {
            cout << "You lost the fight." << endl;
            party.displayStatus();
            game_map.displayMap();
        }
    } else {
        cout << "Do you want to surrender? " << endl;
        cin >> decision;
        if (decision == 'N' || decision == 'n'){
            cout << " Oh no! one of your members was unable to escape the monster!!" << endl;
        }
    }
}
/* Function operates by using a random number generator and a vector list of monsters to randomly choose a 
monster for the party to fight from the list of monsters. The function then prompts user for input 
then if the user decides to fight the battle calls upon the battleResult function from above to 
calculate the outcome of the battle. */





void DungeonEscape::cookAndEat(Party& party) {
    if (party.getIngredients() < 0) {
        cout << "You don't have any ingredients to cook!" << endl;
        return;
    }

    int cookwareChoice;
    cout << "Select the cookware you want to use (1: Pot, 2: Pan, 3: Cauldron): ";
    cin >> cookwareChoice;

    int cookwareSuccessChance;
    int cookwareCount;

    switch (cookwareChoice) {
        case 1:
            cookwareSuccessChance = 75;
            cookwareCount = party.getPots();
            break;
        case 2:
            cookwareSuccessChance = 50;
            cookwareCount = party.getPans();
            break;
        case 3:
            cookwareSuccessChance = 25;
            cookwareCount = party.getCauldrons();
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
    }

    if (cookwareCount <= 0) {
        cout << "You don't have the selected cookware!" << endl;
        return;
    }

    int ingredientAmount;
    cout << "Enter the amount of ingredients you want to cook (in increments of 5 kg): ";
    cin >> ingredientAmount;

    if (ingredientAmount % 5 != 0 || ingredientAmount > party.getIngredients()) {
        cout << "Invalid amount of ingredients!" << endl;
        return;
    }

    int randomNumber = rand() % 100;
    bool cookingSuccessful = randomNumber < cookwareSuccessChance;
    int fullnessIncrease = ingredientAmount / 5;

    if (cookingSuccessful) {
        cout << "Cooking was successful!" << endl;

        for (auto &member : party.getMembers()) {
            member.setFullness(member.getFullness() + fullnessIncrease);
        }
        party.displayStatus();
        game_map.displayMap();
    } else {
        cout << "Cooking failed! The cookware broke and the ingredients were lost." << endl;

        switch (cookwareChoice) {
            case 1:
                party.setPots(-1);
                break;
            case 2:
                party.setPans(-1);
                break;
            case 3:
                party.setCauldrons(-1);
                break;
        }
    }

    party.setIngredients(-ingredientAmount);

    cout << "Party members' fullness levels:" << endl;
    for (const auto &member : party.getMembers()) {
        cout << member.getName() << ": " << member.getFullness() << endl;
    }

    cout << "Remaining kg of ingredients: " << party.getIngredients() << endl;
}
/* Cook and eat operates asking users for the type of cookware and amount of ingredients they would like to use.
It then uses RNG to determine if the cook was successfull or not. Then if successfull the fullness levels of the 
party increase and the amount of cookware is then decreased by 1. */

void DungeonEscape::giveUp() {
    cout << "Those who seek to conquer the dungeon often find that it has conquered them instead." << endl;
    cout << "It seems as though you were not worthy of my time, till we meet again!" << endl;
    cout << " GAME OVER" << endl;
    return;
} // ends the game and displays endgame update + message.

void DungeonEscape::NPCSpace(Party& party){
 // Read the riddles from the file
  vector<pair<string, string>> riddles;
  ifstream file("riddle.txt");
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      size_t pos = line.find('~');
      if (pos != string::npos) {
        string riddle = line.substr(0, pos);
        string answer = line.substr(pos + 1);
        riddles.push_back(make_pair(riddle, answer));
      }
    }
    file.close();
  } else {
    cout << "Unable to open file!" << endl;
    return;
  }

  // Select a random riddle
  srand(time(NULL));
  int index = rand() % riddles.size();
  string riddle = riddles[index].first;
  string answer = riddles[index].second;

  // Prompt the player to solve the riddle
  cout << "NPC: Solve this riddle to obtain my wares: " << riddle << endl;
  cout << "Enter your answer: ";
    string playerAnswer;
    cin >> playerAnswer;

    if (playerAnswer == answer) {
  cout << "NPC: Congratulations, you solved the riddle! What can I help you with?" << endl;
  Merchant merchant;
  merchant.merchantMenu(party);
  // Handle the interaction with the NPC here
} else {
  cout << "NPC: Sorry, that's not the right answer. Your lack of knowledge shall be punished!" << endl;
  pickFight(party);
}
}
/* Function reads through riddle.txt file and uses rng to randomly choose a riddle for NPC to tell player,
if player gets riddle correct a merchant object is created and then players are available to purchase items.
If answered wrong the function calls on the pickFight function to randomly spawn a monster for players to fight.*/

bool DungeonEscape::doorPuzzle(Party& party) {
    int attempts = 0;
    while (attempts < 3) {
        cout << "Boulder/Parchment/Shears: What will you choose?" << endl;
        cout << "1. Boulder" << endl;
        cout << "2. Parchment" << endl;
        cout << "3. Shears" << endl;
        int playerChoice;
        cin >> playerChoice;

        int doorChoice = rand() % 3 + 1; // Randomly choose 1, 2, or 3

        if (playerChoice == doorChoice) {
            cout << "It's a tie! Try again." << endl;
        } else if ((playerChoice == 1 && doorChoice == 3) || (playerChoice == 2 && doorChoice == 1) || (playerChoice == 3 && doorChoice == 2)) {
            cout << "You won! The door is unlocked." << endl;
            return true;
        } else {
            cout << "You lost this round. Try again." << endl;
        }

        attempts++;
    }

    cout << "You couldn't beat the door in three attempts. One of your party members is lost." << endl;
    //party.removePartyMember(); // Remove a random party member (excluding the leader)
    return false;
}

void DungeonEscape::handleRoomEncounter(Party& party, int& clearedRooms, Map& gameMap) {
    int challengeRating = clearedRooms + 2;
    if (clearedRooms == 4) {
        challengeRating = 6;
    }

    pickFight(party);
        if (battleResult(party, challengeRating ) == true){
        gameMap.removeRoom(gameMap.getPlayerRow(), gameMap.getPlayerCol());
        clearedRooms++;
        party.addClearedRooms(1);
        party.setKeys(1);

          cout << "You have cleared " << party.getClearedRooms() << " rooms." << endl;
        }
        else {
            cout << "The monster stalks back into the room after your party had to flee! " << endl;
        }
}
// Handles room encounters first checking for the challenge rating, then calling on pickFight to randomly spawn a monster.
// Then if the fight is won the room is cleared and a status update is shown to the player.




void DungeonEscape::roomAction(Party& party, Map& gameMap) {
    int choice;
    int clearedRooms = 0;
    cout << "You've landed on a room space! What would you like to do?" << endl;
    cout << "1. Move" << endl;
    cout << "2. Open the door" << endl;
    cout << "3. Give up" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            // Move logic
            char input;
            cout << "Enter your move (WASD): ";
        cin >> input;
        

        if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
            bool moveResult = gameMap.move(input);
            if (moveResult) {
                cout << "Player moved successfully in direction: " << input << endl;
                gameMap.displayMap();
                party.setAnger(10);
            } else {
                cout << "Invalid move" << endl;
                gameMap.displayMap();
            }
        } else {
            cout << "Invalid input, use WASD keys to move " << endl;
        }
            break;
        case 2:
        if (party.getKeys() <= 0) {
    cout << "You don't have any keys!" << endl;
    if (doorPuzzle(party)) { // If the player successfully solves the puzzle
        handleRoomEncounter(party, clearedRooms, gameMap);
    }
} else { // The player has at least one key
    handleRoomEncounter(party, clearedRooms, gameMap);
}
    break;

        case 3:
            giveUp();
            return;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
    }
}

/* Function displays choices available to user when on a room space. if user chooses to move the same set of moves are 
then presented, else if user chooses to open the door then user either uses available keys or must solve a door puzzle
by calling on the doorPuzzle function. then a random monster is spawned by handleRoomEncounter. */
