#include "RoomClass.h"
#include "GameControllerClass.h"
#include "InteractClass.h"
#include "PickUpItemClass.h"
#include "MovementClass.h"
#include "PlayerClass.h"
#include "UserInterfaceClass.h"
#include "ItemClass.h"
#include "Door.h"

#include <iostream>

int main()
{
    ItemClass itm1("Item 1", "Item 1");
    ItemClass itm2("Item 2", "Item 2");
    ItemClass itm3("Item 3", "Item 3");
    std::vector <ItemClass> itmVec;
    itmVec.push_back(itm1);
    itmVec.push_back(itm2);
    itmVec.push_back(itm3);
    cout << itmVec.at(0).getName() << std::endl;
    cout << itmVec.at(1).getName() << std::endl;
    cout << itmVec.at(2).getName() << std::endl;
    itmVec.erase(itmVec.begin());
    cout << itmVec.at(0).getName() << std::endl;
    cout << itmVec.at(1).getName() << std::endl;


    
    PlayerClass player;
    GameControllerClass game;

    game.startGame(); 
    //game.pickUpNoteSequence(player); 
    //game.viewInventory(player);
    //game.interactWithStatueSequence();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
