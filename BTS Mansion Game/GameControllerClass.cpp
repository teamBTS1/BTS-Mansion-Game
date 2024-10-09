
#include "GameControllerClass.h"
#include "PlayerClass.h"
#include "InteractClass.h"
#include "PickUpItemClass.h"
#include <iostream>
#include <sstream>

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

void GameControllerClass::pickUpNoteSequence(PlayerClass& myPlayer) {

    ItemClass note1("Welcome Note", "You have entered the mansion"); // define note item
    InteractClass interactWithNote; // define interact class
    PickUpItemClass myPickUpClass(note1); // define pickup class
    UserInterfaceClass Myuserinterface;
    
    std::cout << "You are in room 1, there is a note on the ground next to you" << std::endl; //Room Message

    Myuserinterface.displayPrompt("enter PICKUP to pick up the item");
    Myuserinterface.userInput(); 
   
   
    interactWithNote.setInputMessage("You have picked up the note!"); //message when ITEM IS PICKED UP
    
    
    //Need to create the user interaction to add item to inventory
    if (Myuserinterface.getCurrentInput() == "PICKUP")
    { 
        myPickUpClass.addToInventory(myPlayer);  // Add the note to the player's inventory
        Myuserinterface.displayPrompt("You Have Picked Up an Item."); // Message upon successful interaction
    }
    else 
    {
        // If the user didn't type "PICKUP",
        std::cout << "You did not pick up the note. Try 'PICKUP'." << std::endl;
    }
  
}

void GameControllerClass::viewInventory(PlayerClass& myPlayer) {

    UserInterfaceClass Myuserinterface; //Lines 62-65 are for testing purposes to make sure code works, prompting user won't be necessary
    //since prompting will be done after user has already asked to open inventory and then this function will be called

    std::cout << "Want to check what items you have?" << std::endl; //Room Message

    Myuserinterface.displayPrompt("Enter INVENTORY to view your inventory.");
    Myuserinterface.userInput();


    //Need to create the user interaction to view inventory
    if (Myuserinterface.getCurrentInput() == "INVENTORY")
    {
        std::cout << std::endl << std::endl;
        std::vector<ItemClass> myInventory = myPlayer.getInventory(); //Setting myInventory to direct reference of players inventory
        int inventorySize = myPlayer.getInventorySize();
        for (int i = 0; i < inventorySize; i++)
        {
            std::cout << myInventory[i].getName() << std::endl; //Printing all of the users inventory
        }
        
        Myuserinterface.displayPrompt("Type the name of an item to get its description.");
        Myuserinterface.userInput(); //Allowing user to inspect from inventory getting input

        for (int i = 0; i < inventorySize; i++)
        {
            if (myInventory[i].getName() == Myuserinterface.getCurrentInput()) //Checking all the input and printing the description of entered item
            {
                std::cout << myInventory[i].getName() << ": " << myInventory[i].getDescription() << std::endl;
            }
            else
            {
                std::cout << "The item you entered is not in your inventory." << std::endl;
            }
        }

    }
    else
    {
        // If the user didn't type "INVENTORY",
        std::cout << "You did not enter the correct input. Try 'INVENTORY'." << std::endl;
    }

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
            UI.displayPrompt("prompt: " + command); // For testing, it will be different from this just to meet our acceptance criteria for the story
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

void GameControllerClass::endGame() {
    UI.displayPrompt("Exiting the game. Thank you for playing!");
    exit(0);  // Exit the game
}
