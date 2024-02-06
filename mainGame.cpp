#include "DungeonEscape.h"


int main() {
    // Ask user for party leader name
    string leaderName;
    cout << "Enter the name of the party leader: ";
    cin >> leaderName;

    // Ask user for up to 3 additional party member names
    vector<string> memberNames;
    int numMembers;
    cout << "How many additional party members? (0-3): ";
    cin >> numMembers;

    for (int i = 0; i < numMembers; i++) {
        string name;
        cout << "Enter name of party member " << i+1 << ": ";
        cin >> name;
        memberNames.push_back(name);
    }

    // Create Party instance
    Party party(leaderName, memberNames, 100);

    // Display the party's initial gold
    cout << "The party, led by " << leaderName << ", has " << party.getGold() << " gold." << endl;

   Merchant merchant;
    merchant.merchantMenu(party);

    cout << "After visiting the merchant, the party has " << party.getGold() << " gold." << endl;
    party.displayStatus();

   Map gameMap;
gameMap.resetMap();
gameMap.setPlayerPosition(1, 1);
gameMap.addNPC(5,5);

// Randomly generate positions for the rooms, NPCs, and exit
int numRooms = 6;
int numNPCs = 4;
int exitX, exitY;
exitX = exitY = 0;

srand(time(NULL));

for (int i = 0; i < numRooms; i++) {
    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    gameMap.addRoom(x, y);
}

for (int i = 0; i < numNPCs; i++) {
    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;
    gameMap.addNPC(x, y);
}

gameMap.setDungeonExit(10, 10);

gameMap.displayMap();



DungeonEscape game(leaderName, memberNames, 100, gameMap); // Creating dungeon escape object.
int currentCol = gameMap.getPlayerCol() ;
   int currentRow = gameMap.getPlayerRow();
char input;
int choice;
int gold;
    while(true){
        
if (gameMap.isNPCLocation(currentRow, currentCol)){ // Checking for NPC space and if so displaying choices for NPC space.
        cout << "You've landed on an NPC Space! " << endl;
        cout  << "1. Move" << endl;
        cout << " 2. Speak to NPC " << endl;
        cout << "3. Give up" << endl;
        int choice_n;
        cin >> choice_n;
        switch (choice_n){
            case 1: 
              cout << "Enter your move (WASD) or Q to quit: ";
        cin >> input;
        

        if (input == 'w' || input == 'a' || input == 's' || input == 'd') { // Mechanics for moving around the map.
            bool moveResult = gameMap.move(input);
            if (moveResult) {
                cout << "Player moved successfully in direction: " << input << endl;
                party.displayStatus();
                gameMap.displayMap(); // Displays map and status update after each turn.
                currentRow = gameMap.getPlayerRow();
                currentCol = gameMap.getPlayerCol();
            } else {
                cout << "Invalid move" << endl;
                party.displayStatus();
                gameMap.displayMap();
            }
        } else {
            cout << "Invalid input, use WASD keys to move or Q to quit" << endl;
        }
        if (input == 'q'){
            break; // Cancels move.
        }
    
    break;
            case 2: 
            game.NPCSpace(party); // Calls the NPC space function from DungeonEscape.
            break;

            case 3: 
            game.giveUp(); // Give up option also presented.

        }
    }
    else if (gameMap.isRoomLocation(currentRow, currentCol)) { // Checks for room location and executes if found.
        cout << "You've landed on a Room Space!" << endl;
        game.roomAction(party, gameMap); // Calls the roomAction function for room mechanics.
    } 
    else{
    cout << "It's your turn. Choose an action:" << endl; // Displays  choices.
    cout << "1. Move" << endl;
    cout << "2. Investigate" << endl;
    cout << "3. Pick a fight" << endl;
    cout << "4. Cook and eat" << endl;
    cout << "5. Give up" << endl;
    cin >> choice;

   
    switch(choice) { // Creating a switch for different input options while on a normal space.

    case 1:        
    
        cout << "Enter your move (WASD): ";
        cin >> input; // Same move mechanics.
        

        if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
            bool moveResult = gameMap.move(input);
            if (moveResult) {
                cout << "Player moved successfully in direction: " << input << endl;
                party.displayStatus();
                gameMap.displayMap();
                currentRow = gameMap.getPlayerRow();
                currentCol = gameMap.getPlayerCol();
            } else {
                cout << "Invalid move" << endl;
                party.displayStatus();
                gameMap.displayMap();
            }
        } else {
            cout << "Invalid input, use WASD keys to move or Q to quit" << endl;
        }
        if (input == 'q'){
            break;
        }
    
    break;
    
    case 2: 
    game.investigate(party); // Calls the investigate function.
    break;

    case 3:
    game.pickFight(party); // More function calls.
    break;

    case 4:
    game.cookAndEat(party);
    
    break;

    case 5: 
    game.giveUp();
    return 0; // ends the game.
    }
  }
    
    if (currentRow == 10 && currentCol == 10 && party.getClearedRooms() == 5){
        cout << "Congragulations traverllers, you have braved the dungeon and made it out to the other side! " << endl;
        cout << " YOU WIN! " << endl;
        cout << endl << "Game Statistics:" << endl;
    cout << "Party members: " <<  endl;
    cout << "  " << leaderName << " (Leader)" << endl;
    for (int i = 1; i < party.getNumPartyMembers(); i++) {
        cout << "  " << party.getPartyMember(i).getName() << endl;
    }
    cout << "Rooms cleared: " << party.getClearedRooms() << endl;
    cout << "Gold pieces remaining: " << party.getGold() << endl;
    cout << "Treasure items in inventory: " << endl;
    }
    else if (party.getAnger() == 100  ){
        cout << "Those who seek to conquer the dungeon often find that it has conquered them instead." << endl;
    cout << "    It seems as though you were not worthy of my time, till we meet again!" << endl;
    cout << " GAME OVER" << endl;
    }
    }    
  }




