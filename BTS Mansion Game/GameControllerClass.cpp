#include "GameControllerClass.h"
#include <iostream>
#include <sstream>

GameControllerClass::GameControllerClass() {
    // Initialize backstory in the constructor
    backstory = "You and your friend seemed in-tune with nature. Let's get out of here! said your friend, the night you both decided to leave for a water-logged cabin in the woods.
                 "\n40 miles removed from civilization, you wake up the following morning to an empty house.
                 "\nYou mumble obscenities under your breath as you set out to find your friend. He is the only one with service For 3 hours you walked in every direction.
                 "\nAs you started to panic at the disapperance of your friend, you hear a faint, low hum. You turn to your left.
                 "\nI can't believe I'm doing this - you say as you stare down the oppresive opening of a cave face. 
                 "\nWith options running thin and desparate to find your friend, you approach the cave with the flashlight of your phone.
                 "\nThe more you walk, the more you notice the detail in the walls of the cave. Fresh granite soon becomes tile.
                 "\nYou reach what seems to be the Foyer of a mansion. You turn around and see the inside of 8 foot double doors.
                 "\nWhat the fuck?"
                    ;
}

void GameControllerClass::startGame() {
    gameLoop();
}

void GameControllerClass::dispayBackstory() {
    std::istringstream stream(GameControllerClass::backstory);
    std::string line;

    while (std::getline(stream, line)) { //algorithm to display story line by line, user will press enter via waitForInput() function form UI class
        std::cout << line << std::endl;
        UI.waitForInput();                
    }
}

void GameControllerClass::gameLoop() {
    displayBackstory();
    while (true) {
        UI.displayMessage("What would you like to do? (type 'QUIT' to exit the game)");
        std::string command = ui.getUserInput();

        if (command == "QUIT") {
            endGame();  // Call endGame method
            return;  // Exit the game loop
        }
        else {
            ui.displayMessage("prompt: " + command);
            //game logic will be contained here 
        }
    }
}

void GameController::showMenu() {
    int choice;
    while (true) {
        ui.displayMenu();
        std::string input = ui.getUserInput();
        try {
            choice = std::stoi(input);
        }
        catch (...) {
            ui.displayMessage("Invalid choice. Please try again.");
            continue;
        }

        switch (choice) {
        case 1:
            startGame();
            return;  // Exit the menu after starting the game
        case 2:
            endGame();  // Call endGame method to exit
            return;  // Exit the menu
        default:
            ui.displayMessage("Invalid choice. Please try again.");
        }
    }
}

void GameController::endGame() {
    ui.displayMessage("Exiting the game. Thank you for playing!");
    exit(0);  // Exit the game
}