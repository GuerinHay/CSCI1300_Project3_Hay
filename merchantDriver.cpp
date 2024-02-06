#include <iostream>
#include <vector>
#include "party.h"
#include "merchant.h"
using namespace std;

int main() {
    // Create party members
    string leaderName = "John";
    vector<string> memberNames = {"Alice", "Bob", "Cindy"};

    // Create a new party with a given leader, members, and amount of gold
    Party myParty(leaderName, memberNames, 100);

    // Display the party's initial gold
    cout << "The party, led by " << leaderName << ", has " << myParty.getGold() << " gold." << endl;

    // Create a merchant
    Merchant merchant;

    // The party visits the merchant
    merchant.merchantMenu(myParty);

    // Display the party's gold after visiting the merchant
    cout << "After visiting the merchant, the party has " << myParty.getGold() << " gold." << endl;
    myParty.displayStatus();

    return 0;
}

