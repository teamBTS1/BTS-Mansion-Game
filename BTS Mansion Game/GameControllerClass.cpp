
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
    /*we initialize the rooms and player class in the beginning. In the future we will probably wrap this in a function or refactor this class to remove clutter from gameLoop*/
    Door doorC = Door(true, "DOOR", "You are now in room A, In front of you is room B and C"); // create door
    RoomClass roomA = RoomClass("You are now in room A, In front of you is room B and DOOR", "A", std::list<std::string>{"B","DOOR"}, doorC); 
    RoomClass roomC = RoomClass("You are now in Room C, behind you is room A", "C", std::list<std::string>{"A"});
    RoomClass roomB = RoomClass("You are now in room B, behind you is room A", "B", std::list<std::string>{"A"});


    PlayerClass userPlayer = PlayerClass(roomA);
    ItemClass KEY = ItemClass("KEY","KEY");
    userPlayer.addItem(KEY);
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

                /*before you read: THIS IS A TEMPORARY FUNCTIONALITY FOR ROOM DETECTION THIS WILL BE REFACTORED WHEN WE DECIDE HOW TO BUILD OUR MAP
                TODO: setup hashmap for corresponding rooms, implement functionality to minimize conditional nesting*/

                if (command == "B") { //if valid option was B
                    userPlayer.setRoom(roomB);  //set this to current room
                }
                else if (command == "A") { //if valid option was A
                    userPlayer.setRoom(roomA); 
                }
                else if (command == "DOOR") {
                    if (userPlayer.inInventory("KEY"))
                    {
                        //userPlayer.removeItem("KEY")  <- FOR JOEY: IMPLEMENT REMOVE LOGIC SO ITEM IS NO LONGER IN INVENTORY
                        UI.displayPrompt("You unlock the door with the key in your pocket");
                        roomA.unlockDoor(); //unlocks door, sets description to different openDoor description through
                        roomA.setRoomOption(std::list<std::string>{"B", "C"}); //set options to new, this is TEMPORARY solution and there will be refactor which includes function within room class to find the option to modify instead of setting it explicity
                        userPlayer.setRoom(roomA); //set room
                    }
                    else
                    {
                        UI.displayPrompt("The door is locked");
                    }
                }
                else if (command == "C") {
                    userPlayer.setRoom(roomC);
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
    UI.displayPrompt("\nYour world disappears around you. You are still aware but there is nothing, like someone pulled the plug on your brain - Am I dead?\n...You wonder if this will end.\nThank you for playing");
    exit(0);  // Exit the game
}
