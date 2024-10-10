
#include "GameControllerClass.h"
#include "RoomClass.h"
#include "InteractClass.h"
#include "PickUpItemClass.h"
#include "MovementClass.h"
#include "PlayerClass.h"
#include "UserInterfaceClass.h"
#include "ItemClass.h"
#include "Door.h"
#include <iostream>
#include <sstream>
#include <list>

GameControllerClass::GameControllerClass() {
    // Initialize backstory in the constructor
    backstory = "You and your friend seemed in-tune with nature."
        "\nLet's get out of here! said your friend, the night you both decided to leave for a water-logged cabin in the woods."
        "\n40 miles removed from civilization, you wake up the following morning to an empty house."
        "\nYou mumble obscenities under your breath as you set out to find your friend. He is the only one with service. For 3 hours you walked in every direction."
        "\nAs you started to panic at the disapperance of your friend, you hear a faint, low hum. You turn to your left."
        "\nI can't believe I'm doing this - you say as you stare down the oppresive opening of a cave face."
        "\nWith options running thin and desparate to find your friend, you approach the cave with the flashlight of your phone."
        "\nThe more you walk, the more you notice the detail in the walls of the cave. Fresh granite soon becomes tile."
        "\nYou reach what seems to be the Foyer of a mansion. You turn around and see the inside of 8 foot double doors."
        "\nWhat the fuck?";
}


void GameControllerClass::startGame() {
    displayBackstory();
    gameLoop();
}

void GameControllerClass::displayBackstory() {
    std::istringstream stream(GameControllerClass::backstory);
    std::string line;

    while (std::getline(stream, line)) { //algorithm to display story line by line, user will press enter via waitForInput() function form UI class
        UI.displayPrompt(line);
        UI.waitForInput();                
    }
}

void GameControllerClass::gameLoop() {
    /*we initialize the rooms and player class in the beginning. In the future we will probably wrap this in a function or refactor this class to remove clutter from gameLoop*/
    RoomClass roomA = RoomClass("You are now in room A, In front of you is room B", "A", std::list<std::string>{"B"});
    RoomClass roomB = RoomClass("You are now in room B, behind you is room A", "B", std::list<std::string>{"A"});
    PlayerClass userPlayer = PlayerClass(roomA);
    std::string startingRoom = "A";

    while (true) {
        UI.displayPrompt(userPlayer.getRoomDescription());
        UI.displayPrompt("\nWhat would you like to do? (type 'QUIT' to exit the game)"); //user input 
        std::string command = UI.userInput();
        RoomClass currentRoom_temp = userPlayer.getRoom(); //temp current room instance of roomClass to access room data

        if (command == "QUIT") {
            endGame();  // Call endGame method
            return;  // Exit the game loop
        }
        else {
            //std::string current_room = userPlayer.getRoomName();
            std::list<std::string> validInputs = currentRoom_temp.GetRoomOption();
            if (std::find(validInputs.begin(), validInputs.end(), command) != validInputs.end()) //algorithm to parse command in valid room options
            {
                UI.displayPrompt("\nyou moved to " + command);

                /*before you read: THIS IS A TEMPORARY FUNCTIONALITY FOR ROOM DETECTION THIS WILL BE REFACTORED WHEN WE DECIDE HOW TO BUILD OUR MAP*/
                if (command == "B") { //if valid option was B
                    userPlayer.setRoom(roomB);  //set this to current room
                }
                else if (command == "A") { //if valid option was A
                    userPlayer.setRoom(roomA); 
                }
            }
            else
            { //catch invalid input NOTE - in the future we will refactor to utilize UI class input validation
                UI.displayPrompt("\nYou tried to choose your option but you couldn't move your body. It seems like there is an unforseen force telling you can't perform that action..You look around again\n");
            }
        }
    }
}

void GameControllerClass::showMenu() {
    while (true) {
        UI.displayMenu();
        std::string input = UI.userInput();

        if (input == "START") //conditional for input validation of menu selection
        {
            startGame();
            return;  // Exit the menu after starting the game
        }
        else if (input == "QUIT")
        {
            endGame();  // Call endGame method to exit
            return;  // Exit the menu
        }
        else
        {
            UI.displayPrompt("Invalid choice. Please try again.");
        }
    }
}

void GameControllerClass::endGame() {
    UI.displayPrompt("\nYour world disappears around you. You are still aware but there is nothing, like someone pulled the plug on your brain - Am I dead?\n...You wonder if this will end.\nThank you for playing");
    exit(0);  // Exit the game
}
