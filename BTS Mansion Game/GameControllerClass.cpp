
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
#include <algorithm>

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
    while (true) {
        UI.displayPrompt("What would you like to do? (type 'QUIT' to exit the game)");
        std::string command = UI.userInput();

        if (command == "QUIT") {
            endGame();  // Call endGame method
            return;  // Exit the game loop
        }
        else {
            UI.displayPrompt("prompt: " + command); // For testing, it will be different from this this just to meet our acceptance criteria for the story
            //game logic will be contained here 
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

void GameControllerClass::interactWithStatueSequence() {

    PlayerClass myPlayer; // Create an instance of the player
    ItemClass statue("Statue\n", "This statue is a woman carrying book"); // Define the statue as an item
    InteractClass interactWithStatue; // Define the interaction class
    UserInterfaceClass Myuserinterface; // Interface for handling input/output

    std::cout << "You have found a statue." << std::endl;

    Myuserinterface.displayPrompt("You can INTERACT with the statue, READ its description ,or EXIT. Enter INTERACT,READ or EXIT:");

    // Loop until the user interacts with the statue or exits
    while (true) {
        Myuserinterface.userInput(); // Get the user's input

        // Convert input to uppercase for case-insensitive comparison
        std::string input = Myuserinterface.getCurrentInput();
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);

        if (input == "READ") {
            // Display the description of the statue
            Myuserinterface.displayPrompt(statue.getDescription());

            // After reading, give an option to interact or exit
            Myuserinterface.displayPrompt("You can now INTERACT with the statue or EXIT. Enter INTERACT or EXIT:");

            // Loop again to get valid input for interacting or exiting
            while (true) {
                Myuserinterface.userInput(); // Get user input again

                input = Myuserinterface.getCurrentInput();
                std::transform(input.begin(), input.end(), input.begin(), ::toupper);

                if (input == "INTERACT") {
                    interactWithStatue.setInputMessage("You've touched the statue");
                    interactWithStatue.runInteraction();  // Run interaction logic for the statue
                    break; // Exit the loop after interaction
                }
                else if (input == "EXIT") {
                    std::cout << "You have chosen to exit the interaction." << std::endl;
                    break; // Exit the loop if they choose to exit
                }
                else {
                    // Invalid input, ask again
                    std::cout << "Invalid input. Please type 'INTERACT' to interact with the statue or 'EXIT' to leave." << std::endl;
                }
            }

            // Exit the outer loop after valid action (interact or exit)
            break;
        }
        else if (input == "INTERACT") {
            interactWithStatue.setInputMessage("You've touched the statue.");
            interactWithStatue.runInteraction();  // Run interaction logic for the statue
            break; // Exit the loop after interaction
        }
        else if (input == "EXIT") {
            std::cout << "You have chosen to exit the interaction." << std::endl;
            break; // Exit the loop
        }
        else {
            // Invalid input, prompt user to enter a valid option
            std::cout << "Invalid input. Please type 'READ' to read the description, 'INTERACT' to interact with the statue, or 'EXIT' to leave." << std::endl;
        }
    }
    std::cout << "Interaction with the statue completed." << std::endl;
}

void GameControllerClass::endGame() {
    UI.displayPrompt("Exiting the game. Thank you for playing!");
    exit(0);  // Exit the game
}
