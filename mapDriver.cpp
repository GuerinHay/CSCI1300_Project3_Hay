#include "map.h"
using namespace std;

int main() {
    Map gameMap;

    gameMap.resetMap();
    gameMap.setPlayerPosition(1, 1);
    gameMap.setDungeonExit(10, 10);
    gameMap.addNPC(3, 3);
    gameMap.addNPC(5, 5);
    gameMap.addRoom(7, 7);

    gameMap.displayMap();

    char input;

    while (true) {
        
        cout << "Enter your move (WASD): ";
        cin >> input;
        

        if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
            bool moveResult = gameMap.move(input);
            if (moveResult) {
                cout << "Player moved successfully in direction: " << input << endl;
                gameMap.displayMap();
            } else {
                cout << "Invalid move" << endl;
                gameMap.displayMap();
            }
        } else {
            cout << "Invalid input, use WASD keys to move or Q to quit" << endl;
        }
        if (input =='q'){
            break;
        }
    }

    return 0;
}
