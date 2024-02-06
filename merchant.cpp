#include <iostream>
#include <string>
#include <vector>
#include "party.h"
#include "merchant.h"
using namespace std;

void Merchant::displayInventory(Party &party)
{
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;     // here we are displaying the merchant menu.
    cout << "+-------------+" << endl;
    cout << "| Gold        |  " << endl;
    cout << "| Ingredients | " << endl;
    cout << "| Cookware    | " << endl;
    cout << "| Weapons     | " << endl;
    cout << "| Armor       | " << endl;
    cout << "| Treasures   | " << endl;
}
void Merchant::buyIngredients(Party &party)
{
    /* In each function involving purchases from the merchant the structure is roughly the same. 
    Starting off by showing the player the purhcase options for that category(if applicable) then 
    extending a purchase choice to the player. The player inputs the number of whatever item they
    are purchasing, then confrim it using simple y/n. In the process the party objeect is being 
    updated to display updated user inventory values using getters and setters from the party class.
    */
    int ingredients;
    cout << "How many kg of ingredients do you need [1 Gold/kg]? (Enter a positive multiple of 5, or 0 to cancel)" << endl;
    cin >> ingredients;

    while (cin.fail() || ingredients < 0 || (ingredients % 5 != 0 && ingredients != 0))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a positive multiple of 5 or 0 to cancel." << endl;
        cin >> ingredients;
    }

    if (ingredients == 0)
    {
        cout << "No ingredients purchased. Returning to menu." << endl;
        return;
    }

    cout << endl
         << "You want to buy " << ingredients << " kg of ingredients for " << ingredients << " Gold? (y/n)" << endl;
    char confirmation;
    cin >> confirmation;
    if (confirmation == 'y' || confirmation == 'Y')
    {
        if (party.getGold() >= ingredients)
        {
            party.setGold(party.getGold() - ingredients);
            party.setIngredients(ingredients);
            cout << "Great purhcase my friend! You now have " << party.getIngredients() << " kg of ingredients and " << party.getGold() << " Gold remaining." << endl;
        }
        else
        {
            cout << "You don't have enough Gold to make this purchase." << endl;
        }
    }
    else
    {
        cout << "Purchase canceled. Returning to menu." << endl;
    }
}

void Merchant::buyCookware(Party &party)
{
    int choice;
    int amount;
    int price;

    cout << "I have several types of cookware, which one would you like traveller? " << endl;
    cout << "Each type has a different probability of breaking when used, marked with (XX%) " << endl;

    cout << "Please select one of the following: " << endl;
    cout << "1. (25%) Ceramic Pot [2 Gold] " << endl;
    cout << "2. (10%) Frying Pan [10 Gold] " << endl;
    cout << "3. ( 2%) Cauldron [20 Gold] " << endl;
    cout << "4. Cancel " << endl;
    cin >> choice;

    while (cin.fail() || choice < 0 && choice != 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a positive integer or 0 to cancel." << endl;
        cin >> choice;
    }

    if (choice == 0)
    {
        cout << "No cookware purchased. Returning to menu." << endl;
        return;
    }
    switch (choice)
    {
    case 1:
        cout << endl
             << "How many would you like? (Enter a positive integer, or 0 to cancel) " << endl;
        cin >> amount;
        price = amount * 2;
        cout << "You want to buy " << amount << " Ceramic Pot(s) for " << price << " Gold? (y/n)" << endl;
        char confirmation;
        cin >> confirmation;
        if (confirmation == 'y' || confirmation == 'Y')
        {
            if (party.getGold() >= price)
            {
                party.setGold(party.getGold() - price);
                party.setPots(party.getPots() + amount);
                cout << "Great purhcase my friend! You now have " << party.getPots() << " Ceramic Pot(s) and " << party.getGold() << " Gold remaining." << endl;
            }
            else
            {
                cout << "You don't have enough Gold to make this purchase." << endl;
            }
        }
        else
        {
            cout << "Purchase canceled. Returning to menu." << endl;
        }
        break;

    case 2:
        cout << endl
             << "How many would you like? (Enter a positive integer, or 0 to cancel) " << endl;
        cin >> amount;
        price = amount * 10;
        cout << "You want to buy " << amount << " Frying Pan(s) for " << price << " Gold? (y/n)" << endl;
        cin >> confirmation;
        if (confirmation == 'y' || confirmation == 'Y')
        {
            if (party.getGold() >= price)
            {
                party.setGold(party.getGold() - price);
                party.setPans(amount);
                cout << "Great purhcase my friend! You now have " << party.getPans() << " Frying Pan(s) and " << party.getGold() << " Gold remaining." << endl;
            }
            else
            {
                cout << "You don't have enough Gold to make this purchase." << endl;
            }
        }
        else
        {
            cout << "Purchase canceled. Returning to menu." << endl;
        }
        break;

    case 3:
        cout << endl
             << "How many would you like? (Enter a positive integer, or 0 to cancel) " << endl;
        cin >> amount;
        price = amount * 20;
        cout << "You want to buy" << amount << " Cauldron(s) for " << price << " Gold? (y/n)" << endl;
        cin >> confirmation;
        if (confirmation == 'y' || confirmation == 'Y')
        {
            if (party.getGold() >= price)
            {
                party.setGold(party.getGold() - price);
                party.setCauldrons(party.getCauldrons() + amount);
                cout << "Great purhcase my friend! You now have " << party.getCauldrons() << " Cauldron(s) and " << party.getGold() << " Gold remaining." << endl;
            }
            else
            {
                cout << "You don't have enough Gold to make this purchase." << endl;
            }
        }
        else
        {
            cout << "Purchase canceled. Returning to menu." << endl;
        }
        break;
    case 4:
    cout << endl;
    cout << " Returning to menu. " << endl;
    return;
    }
}
void Merchant::buyWeapons(Party &party)
{
    int weapon;
    int amount;
    int price;
    char confirmation;
    cout << " I have quite the collection of weapons available for you, please take your pick. " << endl
         << "Some of my weapons are more powerful than others, providing special bonuses in combat denoted by (+X)" << endl;
    cout << "Choose one of the following: " << endl;
    cout << endl;
    cout << " 1. Stone Club [2 Gold]" << endl;
    cout << " 2. Iron Spear [2 Gold]" << endl;
    cout << " 3. (+1) Mythril Rapier [5 Gold]" << endl;
    cout << " 4. (+2) Flaming Battle-Axe [15 Gold]" << endl;
    cout << " 5. (+3) Vorpal Longsword [50 Gold]" << endl;
    cout << " 6. Cancel" << endl;
    cin >> weapon;

     while (cin.fail() || weapon < 0 && weapon != 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a positive integer or 0 to cancel." << endl;
        cin >> weapon;
    }
    if (weapon == 0){
        cout << "No weapons purhcased, returning to menu." << endl;
        return;
    }
    switch (weapon)
    {
    case 1:
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        price = amount * 2;
        cout << "You want to buy " << amount << " Stone club(s) for " << price << " Gold? (y/n) " << endl;
        cin >> confirmation;
        if (confirmation == 'y' || confirmation == 'Y')
        {
            if (party.getGold() >= price)
            {
                party.setGold(party.getGold() - price);
                party.setClubs(party.getClubs() + amount);
                cout << "Great purhcase my friend! You now have " << party.getClubs() << " Stone Club(s) and " << party.getGold() << " Gold remaining." << endl;
            }
            else
            {
                cout << "You don't have enough Gold to make this purchase." << endl;
            }
        }
        else
        {
            cout << "Purchase canceled. Returning to menu." << endl;
        }
        
        break;

    case 2:
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        price = amount * 2;
        cout << "You want to buy " << amount << " Iron Spear(s) for " << price << " Gold? (y/n) " << endl;
        cin >> confirmation;
        if (confirmation == 'y' || confirmation == 'Y')
        {
            if (party.getGold() >= price)
            {
                party.setGold(party.getGold() - price);
                party.setSpears(party.getSpears() + amount);
                cout << "Great purhcase my friend! You now have " << party.getSpears() << " Iron Spear(s) and " << party.getGold() << " Gold remaining." << endl;
            }
            else
            {
                cout << "You don't have enough Gold to make this purchase." << endl;
            }
        }
        else
        {
            cout << "Purchase canceled. Returning to menu." << endl;
        }
        break;

    case 3:
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        price = amount * 5;
        cout << "You want to buy " << amount << " (+1)Mythril Rapier(s) for " << price << " Gold? (y/n) " << endl;
        cin >> confirmation;
        if (confirmation == 'y' || confirmation == 'Y')
        {
            if (party.getGold() >= price)
            {
                party.setGold(party.getGold() - price);
                party.setRapiers(party.getRapiers() + amount);
                cout << "Great purhcase my friend! You now have " << party.getRapiers() << " (+1)Mythril Rapier(s) and " << party.getGold() << " Gold remaining." << endl;
            }
            else
            {
                cout << "You don't have enough Gold to make this purchase." << endl;
            }
        }
        else
        {
            cout << "Purchase canceled. Returning to menu." << endl;
        }
        break;

    case 4:
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        price = amount * 15;
        cout << "You want to buy " << amount << " (+2) Flaming Battle-Axe(s) for " << price << " Gold? (y/n) " << endl;
        cin >> confirmation;
        if (confirmation == 'y' || confirmation == 'Y')
        {
            if (party.getGold() >= price)
            {
                party.setGold(party.getGold() - price);
                party.setAxes(party.getAxes() + amount);
                cout << "Great purhcase my friend! You now have " << party.getAxes() << " (+2) Flaming Battle-Axe(s) and " << party.getGold() << " Gold remaining." << endl;
            }
            else
            {
                cout << "You don't have enough Gold to make this purchase." << endl;
            }
        }
        else
        {
            cout << "Purchase canceled. Returning to menu." << endl;
        }
        break;

    case 5:
        cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
        cin >> amount;
        price = amount * 50;
        cout << "You want to buy " << amount << " (+3)Vorpal Longsword(s) for " << price << " Gold? (y/n) " << endl;
        cin >> confirmation;
        if (confirmation == 'y' || confirmation == 'Y')
        {
            if (party.getGold() >= price)
            {
                party.setGold(party.getGold() - price);
                party.setSwords(party.getSwords() + amount);
                cout << "Wow going for the big one! Excellent choice this weapon will slay any monster with haste!" << endl;
                cout << "Great purhcase my friend! You now have " << party.getSwords() << " Stone Club(s) and " << party.getGold() << " Gold remaining." << endl;
            }
            else
            {
                cout << "You don't have enough Gold to make this purchase." << endl;
            }
        }
        else
        {
            cout << "Purchase canceled. Returning to menu." << endl;
        }
        break;

    case 6:
    cout << endl;
    cout << " Returning to menu. " << endl;
    return;
    }
    
}
void Merchant::buyArmor(Party &party)
{
    int amount;
    int price;
    char confirmation;
    cout << "You look in need of some new armor, well good thing I get mine from the best blacksmith in town!" << endl
         << "How many can i get you (Enter a positive integer, or 0 to cancel)" << endl;
    cin >> amount;
    price = amount * 5;
    cout << "You want to buy " << amount << " suit(s) of armor for " << price << " Gold? (y/n) " << endl;
    cin >> confirmation;
        if (confirmation == 'y' || confirmation == 'Y')
        {
            if (party.getGold() >= price)
            {
                party.setGold(party.getGold() - price);
                party.setArmor(party.getArmor() + amount);
                cout << "Great purhcase my friend! You now have " << party.getArmor() << " Suit(s) of armor and " << party.getGold() << " Gold remaining." << endl;
            }
            else
            {
                cout << "You don't have enough Gold to make this purchase." << endl;
            }
        }
        else
        {
            cout << "Purchase canceled. Returning to menu." << endl;
        }
}
void Merchant::sellTreasures(Party &party)
{
    int treasure;
    cout << "Anything I can take off of your hands my friend? " << endl;
    cin >> treasure;
}
void Merchant::merchantMenu(Party &party)
{

    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl;

    bool done = false;
    int choice;

    while (!done)
    {
        /* Here the merchant inventory is being displayed on a loop to the player until cancelled,
        this loop uses a switch inside of it to execute the different functions for purchasing different items.
        Thus case 1 will call the buyIngredients for example with the party object. 
        */
        displayInventory(party);
        cout << "Choose one of the following:" << endl;
        cout << " 1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << " 2. Cookware: You will need something to cook those ingredients." << endl;
        cout << " 3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << " 4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << " 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << " 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        cout << "> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            buyIngredients(party);
            break;
        case 2:
            buyCookware(party);
            break;
        case 3:
            buyWeapons(party);
            break;
        case 4:
            buyArmor(party);
            break;
        case 5:
            sellTreasures(party);
            break;
        case 6:
            char confirm;
            cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y')
            {
                done = true;
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    cout << "Stay safe out there! Goodbye!" << endl;
};