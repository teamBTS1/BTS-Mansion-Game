
#include "GameControllerClass.h"
#include "RoomClass.h"
#include "InteractClass.h"
#include "PickUpItemClass.h"
#include "MovementClass.h"
#include "PlayerClass.h"
#include "UserInterfaceClass.h"
#include "ItemClass.h"
#include "Door.h"
#include "Puzzle.h"
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
        "\nWhat the fuck?"
        "\n----------------------"
        "\n INSTRUCTIONS: Any word that is in all caps, such as INSPECT, PICKUP or GARDEN, is a keyword and can be inputted for an action"
        "\n----------------------";
}
void GameControllerClass::startGame() {
    //displayBackstory();
    gameLoop();
}

void GameControllerClass::pickUpNoteSequence(PlayerClass& myPlayer) {

    ItemClass note1("Welcome Note", "You have entered the mansion", true); // define note item
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
        //myPickUpClass.addToInventory(myPlayer);  // Add the note to the player's inventory
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

    //Need to create the user interaction to view inventory
        std::cout << std::endl << std::endl;
        std::vector<ItemClass> myInventory = myPlayer.getInventory(); //Setting myInventory to direct reference of players inventory
        int inventorySize = myPlayer.getInventorySize();
        for (int i = 0; i < inventorySize; i++)
        {
            std::cout << myInventory[i].getName() << std::endl << std::endl; //Printing all of the users inventory
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
    Door doorC = Door(true, "BBBB", "You are now in the FOYER, In front of you is the LOUNGE and LIBRARY"); // create door

    InteractClass* userInteractStatueA = new InteractClass("Would you like to INTERACT with the statue?", "You feel a wave of knowledge wash over you, like you've learned something from someone previously here before you."); //Defining statue interaction
    ItemClass statueA("STATUE", "This statue is a woman carrying book", false, userInteractStatueA); // Define the statue as an item

    ItemClass keyB("KEY B", "Rusty key", "BBBB", true, true); //Initialzing items TEMP key B
    //ItemClass Candle1("CANDLE 1", "STUDY CANDLE", "CCC", true, true ) //initialize candle item, ID value CCC is important for determining whether item is valid candle to place in ritual room
    ItemClass noteA("NOTE A", "A note with dust and cobwebs all over", true); //Defining TEMP note A
    std::vector <ItemClass> roomA_Items = { noteA, statueA }; //Creating items
    std::vector <ItemClass> roomB_Items = { keyB };


    //Room A Doors
    std::vector<Door> FoyerDoors = { doorC };

    //Library Items
    InteractClass* userInteractSafe = new InteractClass("Would you like to look at the safe?", "Please enter a 4 digit code");
    ItemClass Book("Old Book", "An old book which appears to belong to a bookshelf", "BookKey", true, true);
    ItemClass Safe("Metal Safe", "A safe that appears to accept a 4 digit code", false, userInteractSafe);

    Door HiddenBookshelf = Door(true, "BookKey", "****You place the book on the shelf. The Bookshelf begins to move, screaching across the woodenfloor, it reveals the staircase leading down to the HIDDENSECTION********");

    std::vector <ItemClass> library_Items = { Book,Safe };

    std::vector <Door> Library_Doors = { HiddenBookshelf, doorC };

    //Hidden Section Items
    ItemClass Candle1("CANDLE", "A candle with pentagram etchings", "C1", true, true); //candle item instance, name must remain candle to be consumed in main algorithm
    std::vector <ItemClass> hiddensection_Items = { Candle1 };


    RoomClass roomA = RoomClass("You enter the foyer, the walls are lined with faded wallpaper and adorned with massive grim portraits of long forgotten residents whose eyes seem to follow your every move. A dim eeries light illuminates the room, as you stand here in feeling the chill of the cold and heavy air surronding you. There also appears to be a ornate wooden DOOR that is locked.\n", "FOYER", std::list<std::string>{"LOUNGE", "DOOR"}, FoyerDoors, roomA_Items);
    RoomClass roomB = RoomClass("You enter the lounge, There is a staircase, however there is a black sludge blocking the way\n", "LOUNGE", std::list<std::string>{"FOYER"}, roomB_Items);
    RoomClass roomC = RoomClass("You enter the library, filled to the brim with bookshelves along an ominous SAFE, it appears to accept a 4 digit code. You also see a BOOKSHELF with a missing book. There is a BOOK on the table  \n", "LIBRARY", std::list<std::string>{"FOYER", "BOOKSHELF"}, Library_Doors, library_Items);
    RoomClass HiddenSection = RoomClass("You now enter the hidden section, nothing is safe here, you feel a presense linger, as if it was plucking your heartstrings, there is a table with a candle on top", "HIDDEN SECTION", std::list<std::string>{"LIBRARY", "RITUAL ROOM"}, hiddensection_Items);
    RoomClass RitualRoom = RoomClass("You enter a room that does not invite you back. A perfect, pentacle drawn on the floor invites you to place a candle at each of it's vertecies. [Hint: enter CANDLE as input if you posses a candle]", "RITUAL ROOM", std::list<std::string>{"HIDDEN SECTION"}, true); //defenition for ritual room class


    //roomA.RemoveItem(noteA);

    PlayerClass userPlayer = PlayerClass(roomC); // set to ritual room for testing
    //userPlayer.addItem(Candle1);
    std::string startingRoom = "A";


    while (true) {
        RoomClass& currentRoom_temp = userPlayer.getRoom(); //temp current room instance of roomClass to access room data
        UI.displayPrompt(userPlayer.getRoomDescription());
        currentRoom_temp.displayRoomItems(); //Displaying room items, TEMP function until can implement into UI class
        std::cout << endl;
        currentRoom_temp.displayAdjacentRooms(); //Displaying adjacent rooms, TEMP function until can implement into UI class
        UI.displayPrompt("\nYou cant contain your curiosity and have the urge to INSPECT the items in the room. (type 'INVENTORY' to open inventory. Type 'QUIT' to exit the game)\n"); //user input 
        std::string command = UI.userInput();


        if (command == "CANDLE" && userPlayer.getRoomName() == "RITUAL ROOM") //user will type candle in input section to place a candle, only a valid input if they are in the RITUAL ROOM
        {
            if (userPlayer.getInventorySize() != 0)
            {
                if (userPlayer.inInventory("CANDLE"))
                {
                    userPlayer.useItem("CANDLE"); //Uses Candle from inventory, is removed
                    UI.displayPrompt("You have placed a candle\n");
                    currentRoom_temp.addCandle(); 
                    UI.displayPrompt(std::to_string(currentRoom_temp.getCandleValue()));// for testing purposes to see if candle is added to room
                    continue;
                }
                else
                {
                    UI.displayPrompt("You do not have a candle");
                    continue;
                }
            }
        }


            if (command == "QUIT") {
                endGame();  // Call endGame method
                return;  // Exit the game loop
            }

            else if (command == "INVENTORY")
            {
                viewInventory(userPlayer); //Call view inventory function
            }

            else if (command == "INSPECT") //If user wants to pick up item
            {
                currentRoom_temp.displayRoomItems();
                UI.displayPrompt("What item would you like to inspect?\n");
                command = UI.userInput(); //Getting item to be picked up

                if (currentRoom_temp.getRoomItemByName(command).getName() == command) //Checks if there is an item in the room same as item user wants to inspect
                {
                    std::string itemName = command;
                    std::cout << endl;
                    UI.displayPrompt(currentRoom_temp.getRoomItemByName(itemName).getDescription());
                    std::cout << endl;

                    if (currentRoom_temp.getRoomItemByName(itemName).getCanPickUp() == true) //Run Pick up sequence
                    {
                        UI.displayPrompt("Type PICKUP to pick up the item");
                        command = UI.userInput();

                        if (command == "PICKUP")
                        {
                            if (currentRoom_temp.getRoomItemByName(itemName).getCanPickUp() == true) //Run pick up sequence
                            {
                                for (int i = 0; i < currentRoom_temp.getItemsLength(); i++)
                                {
                                    ItemClass& itm = currentRoom_temp.getItems().at(i); //Looping through each item in room to check if exists
                                    //std::cout << itm.getName();
                                    if (itm.getName() == itemName)
                                    {
                                        PickUpItemClass pickUp(itm); //Picking up item the user requested to pick up
                                        pickUp.addToInventory(userPlayer);
                                        currentRoom_temp.RemoveItem(itm);
                                        userPlayer.setRoom(currentRoom_temp);
                                        std::cout << endl;
                                        std::cout << "You picked up " << itemName << "." << std::endl << std::endl;
                                        std::cout << "-----------" << endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    else //Run interact sequence if not pick up able object
                    {
                        //userInteractStatueA.runInteraction(); //Runs interaction with item
                        currentRoom_temp.getRoomItemByName(itemName).getInteraction()->runInteraction();
                    }
                }


            }

            else {
                //std::string current_room = userPlayer.getRoomName();
                std::list<std::string> validInputs = currentRoom_temp.GetRoomOption();
                if (std::find(validInputs.begin(), validInputs.end(), command) != validInputs.end()) //algorithm to parse command in valid room options
                {
                    UI.displayPrompt("\nyou moved to " + command);

                    /*before you read: THIS IS A TEMPORARY FUNCTIONALITY FOR ROOM DETECTION THIS WILL BE REFACTORED WHEN WE DECIDE HOW TO BUILD OUR MAP
                    TODO: setup hashmap for corresponding rooms, implement functionality to minimize conditional nesting*/

                    if (command == "LOUNGE") { //if valid option was B
                        userPlayer.setRoom(roomB);  //set this to current room
                        //currentRoom_temp = userPlayer.getRoom(); //setting temp room to userPlayers room
                    }
                    else if (command == "FOYER") { //if valid option was A
                        userPlayer.setRoom(roomA);
                        //currentRoom_temp = userPlayer.getRoom();
                    }
                    else if (command == "DOOR") {

                        std::vector<Door>& doors = currentRoom_temp.GetDoors();
                        for (int i = 0; i < doors.size(); i++) {
                            if (doors[i].getIsLocked())
                            {
                                if (userPlayer.getInventorySize() != 0)
                                {
                                    std::string playerKey = userPlayer.searchForKey(doors[i].getDoorKeyID());
                                    if (doors[i].getDoorKeyID() == playerKey)
                                    {

                                        userPlayer.useKey(playerKey); //Uses correct key from inventory
                                        UI.displayPrompt("You unlock the door with the key in your pocket, you can now traverse to the LIBRARY\n");
                                        currentRoom_temp.unlockDoor(i); //unlocks door, sets description to different openDoor description through
                                        doors[i].unlockDoor();
                                        currentRoom_temp.setRoomOption(std::list<std::string>{"LOUNGE", "LIBRARY"}); //set options to new, this is TEMPORARY solution and there will be refactor which includes function within room class to find the option to modify instead of setting it explicity
                                        userPlayer.setRoom(currentRoom_temp); //set room

                                        //currentRoom_temp = userPlayer.getRoom();
                                    }
                                    else
                                    {
                                        UI.displayPrompt("The door is locked");
                                    }
                                }
                                else
                                {
                                    UI.displayPrompt("The door is locked");
                                }
                            }
                            else
                            {
                                userPlayer.setRoom(roomC);
                                //currentRoom_temp = userPlayer.getRoom();
                            }
                        }
                    }
                    else if (command == "LIBRARY") {
                        userPlayer.setRoom(roomC);
                        //currentRoom_temp = userPlayer.getRoom();
                    }
                    else if (command == "BOOKSHELF") {

                        std::vector<Door>& doors = currentRoom_temp.GetDoors();
                        for (int i = 0; i < doors.size(); i++) {
                            if (doors[i].getIsLocked())
                            {
                                if (userPlayer.getInventorySize() != 0)
                                {
                                    std::string playerKey = userPlayer.searchForKey(doors[i].getDoorKeyID());
                                    if (doors[i].getDoorKeyID() == playerKey)
                                    {

                                        userPlayer.useKey(playerKey); //Uses correct key from inventory
                                        UI.displayPrompt("You unlock the door with the key in your pocket, you can now traverse to the LIBRARY\n");
                                        currentRoom_temp.unlockDoor(i); //unlocks door, sets description to different openDoor description through
                                        doors[i].unlockDoor();
                                        currentRoom_temp.setRoomOption(std::list<std::string>{"FOYER", "HIDDEN SECTION"}); //set options to new, this is TEMPORARY solution and there will be refactor which includes function within room class to find the option to modify instead of setting it explicity
                                        userPlayer.setRoom(currentRoom_temp); //set room

                                        //currentRoom_temp = userPlayer.getRoom();
                                    }
                                    else
                                    {
                                        UI.displayPrompt("The door is locked");
                                    }
                                }
                                else
                                {
                                    UI.displayPrompt("The door is locked");
                                }
                            }
                            else
                            {
                                userPlayer.setRoom(HiddenSection);
                                //currentRoom_temp = userPlayer.getRoom();
                            }
                        }


                    }
                    else if (command == "HIDDEN SECTION") {
                        userPlayer.setRoom(HiddenSection);
                    }
                    else if (command == "RITUAL ROOM") {
                        userPlayer.setRoom(RitualRoom);
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
    ItemClass statue("Statue\n", "This statue is a woman carrying book", false); // Define the statue as an item
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
