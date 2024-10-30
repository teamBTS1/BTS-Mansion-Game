
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
#include "GalleryPuzzle.h"
#include "MirrorPuzzle.h"
#include "FountainPuzzle.h"
#include "MazePuzzle.h"
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include<string>
#include <unordered_map>

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

    std::cout << std::endl << std::endl;
    std::vector<ItemClass> myInventory = myPlayer.getInventory(); //Setting myInventory to direct reference of players inventory
    int inventorySize = myPlayer.getInventorySize();
    for (int i = 0; i < inventorySize; i++)
    {
        std::cout << myInventory[i].getName() << std::endl << std::endl; //Printing all of the users inventory
    }

    Myuserinterface.displayPrompt("Type the name of an item to get its description.");
    Myuserinterface.userInput(); //Allowing user to inspect from inventory getting input


    bool itemFound = false;
    for (int i = 0; i < inventorySize; i++)
    {
        if (myInventory[i].getName() == Myuserinterface.getCurrentInput()) //Checking all the input and printing the description of entered item
        {
            system("cls");
            std::cout << myInventory[i].getName() << ": " << myInventory[i].getDescription() << std::endl;
            itemFound = true;
            break;
        }
    }
    if (!itemFound)
    {
        std::cout << "The item you entered is not in your inventory." << std::endl;
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

    std::unordered_map<std::string, RoomClass> rooms; //hashmap for all rooms
    std::unordered_map<std::string, Door> doors; // hashmap for all doors

    //Declare all doors TODO: Joey add logic for door map 

    doors["DOOR"] = Door(true, "BBBB", "You enter the foyer, the walls are lined with faded wallpaper and adorned with massive grim portraits of long forgotten residents whose eyes seem to follow your every move.A dim eeries light illuminates the room, as you stand here in feeling the chill of the cold and heavy air surronding you.There also appears to be a ornate wooden DOOR that is locked"); // create FOYER door
    doors["BOOKSHELF"] = Door(true, "BookKey", "You enter the library, filled to the brim with bookshelves.");
    doors["DOUBLE DOORS"] = Door(true, "idMaster", "You are now in the MASTER BEDROOM."); //Adding master bedroom door
    doors["BLOCKED HEDGE MAZE"] = Door(true, "MAZEKEY", "You pour the holy water on the dark force blocking the entrance to the hedge maze, granting yourself access as the dark sludge burns away.");
    doors["MAZE EXIT"] = Door(true, "MAZEEXITKEY", "Using the map, you are able to find your way out of the maze, reaching the exit.");

    //Greater Library Door
    doors["GREATER LIBRARY DOOR"] = Door(true, "DHKey", "You have now opened the door, you are now in the GREATER LIBRARY");

    std::vector<Door> FoyerDoors = { doors["DOOR"] };
    std::vector <Door> Library_Doors = { doors["BOOKSHELF"], doors["DOOR"], doors["GREATER LIBRARY DOOR"]};
    std::vector <Door> Master_Doors = { doors["DOUBLE DOORS"] };
    std::vector<Door> shedDoors;       // Doors for the Shed
    std::vector<Door> mazeDoors = { doors["BLOCKED HEDGE MAZE"] };       // Doors for the Hedge Maze
    std::vector<Door> fountainDoors;   // Doors for the Fountain
    std::vector<Door> mazeExitDoors = { doors["MAZE EXIT"] }; //Exit of hedge maze

    //define all ineractions
    InteractClass* userInteractStatueA = new InteractClass("Would you like to INTERACT with the statue?", "You feel a wave of knowledge wash over you, like you've learned something from someone previously here before you."); //Defining statue interaction
    InteractClass* userInteractKitchenCounter = new InteractClass("Would you like to look at the kitchen counter?", "");
    InteractClass* userInteractSafe = new InteractClass("Would you like to look at the safe?", "Please enter a 4 digit code");
    InteractClass* userInterectSafeDiningHall = new InteractClass("Would you like to look at the safe?", "");
    InteractClass* userInteractBody1 = new InteractClass("Would you like to look at dead body 1?", "");
    InteractClass* userInteractBody2 = new InteractClass("Would you like to look at dead body 2", "");
    InteractClass* userInteractBody3 = new InteractClass("Would you like to look at dead body 3", "");
    InteractClass* userInteractBody4 = new InteractClass("Would you like to look at dead body 4", "");
    InteractClass* storyBookInteraction = new InteractClass("You read the title of a poem, 'The Cycle of a Servant'.", "The lord with crimson cloak, His eyes once sharp, but now they choke. A wineglass shattered at his feet, his lips were poisoned - death so sweet. The servant went into the night, The deed done, taking flight, Blocking the way a spear of the night, The lord’s son seeking justice, lunged forward claiming blood. The servant however did not fall, Gutting the son, no longer standing tall. The servant reached the lowly village, To the bar seeking refuge, Bleeding from his gut. The town drunk drank into the night, While the barkeep kept the light. However a mob did approach, The servant hid, but could not hide, Seized by the people he despised. So the end approached for the lowly servant, Vengeance acquired, accepted his end. Before he met his end, His son’s eyes he met, Looking at his father’s soon to be killer, The servant knew the look, for he had seen it before, The reason that he had killed his lord, The servant was killed purpose fulfilled, However the servant knew before he died, His son would now live his same life.");
    InteractClass* lordPaintingInteraction = new InteractClass("Would you like to touch the portrait?", "You reach to your mouth and see a speck of blood on your finger.");
    InteractClass* barkeepPaintingInteraction = new InteractClass("Would you like to touch the portrait?", "You feel a sensation wash over you, dulling your senses briefly.");

    //define all items
    ItemClass statueA("STATUE", "a STATUE of a woman carrying a book", false, userInteractStatueA); // Define the statue as an item
    ItemClass keyB("RUSTY KEY", "a RUSTY KEY", "BBBB", true, true); //Initialzing items TEMP key B
    ItemClass noteA("NOTE A", "A note with dust and cobwebs all over", true); //Defining TEMP note A
    ItemClass metalSafe("METAL SAFE", "A safe that appears to accept a 4 digit code", false, userInterectSafeDiningHall);
    ItemClass deadBody1("DEAD BODY 1", "A dead body with a red shirt with a number 8 on and has his mouth open", false, userInteractBody1);
    ItemClass deadBody2("DEAD BODY 2", "A dead body with a blue shirt with a number 6 on and has his skull cracked open", false, userInteractBody2);
    ItemClass deadBody3("DEAD BODY 3", "A dead body with a green shirt with a number 9 on and has his hands on the floor", false, userInteractBody3);
    ItemClass deadBody4("DEAD BODY 4", "A dead body with a purple shirt with a number 1 on and has his right leg over his left leg", false, userInteractBody4);
    ItemClass galleryKey = ItemClass("GALLERY HALF KEY", "Half of the key needed to enter the master bedroom.");
    ItemClass diningHallKey = ItemClass("DINING HALL KEY", "Key can be used to enter the greater library","DHKey",true, true);    //Initializing key from safe in dining hall
    ItemClass mirrorKey = ItemClass("MIRROR HALF KEY", "Half of the key needed to enter the master bedroom.");
    ItemClass kitchenCounter("KITCHEN COUNTER", "The kitchen counter has different colors as its design, it red as its first color, then blue, green, and purple", false, userInteractKitchenCounter);

    //Library Items
    ItemClass Book("OLD BOOK", "an OLD BOOK which appears to belong to a bookshelf", "BookKey", true, true);

    //Upstairs items
    ItemClass lordPainting = ItemClass("CRIMSON LORD PORTRAIT", "CRIMSON LORD PORTRAIT of a regal man in a crimson cloak, with blood dripping from his lips as a glass is raised to his lips.", false, lordPaintingInteraction);
    ItemClass barkeepPainting = ItemClass("BARKEEP PORTRAIT", "CRIMSON LORD PORTRAIT of a stocky man cleaning a glass behind the bar, wearing a fake smile.", false, barkeepPaintingInteraction);
    ItemClass noteUpA = ItemClass("SCRIBBLED NOTE", "SCRIBBLED NOTE that looks like a child's drawing of two kids side by side, both looking almost exactly similair, but one of the children seems to have jagged teeth instead of normal teeth.", true); //Note for clue to mirror puzzle
    ItemClass storyBook = ItemClass("STORYBOOK", "A giant STORYBOOK made of tough leather and weathered pages, indicating many stories have been told from this book. It is open to a page with a poem on it.", false, storyBookInteraction);
    ItemClass masterKey = ItemClass("MASTER KEY", "Fully completed MASTER KEY to the master bedroom", "idMaster", true, true); //Adding master bedroom key

    //Fountain items
    ItemClass mazeKey = ItemClass("HOLY WATER", "Pristine bottle of blessed water", "MAZEKEY", true, true); //Key to unlock hedge maze

    //Hedge maze items
    ItemClass mazeExitKey = ItemClass("MAZE MAP", "Map outlining the layout of the maze, able to lead you to the exit.", "MAZEEXITKEY", true, true); //Key to unlock hedge maze exit

    //define candles
    ItemClass Candle1("CANDLE", "A CANDLE with pentagram etchings", "C1", true, true); //candle item instance, name must remain candle to be consumed in main algorithm
    ItemClass studyCandle("CANDLE", "A CANDLE with a pentagram design", "C2", true, true);
    ItemClass candle3 = ItemClass("CANDLE", "THE THIRD CANDLE is scribbled on the side... hm", "C3", true, true); //Third candle item
    ItemClass candle4 = ItemClass("CANDLE", "The fourth candle, one more until you're finally out of this nightmare.", "C4", true, true); //Fourth candle
    
    //define all itemclass vectors for rooms
    std::vector <ItemClass> roomA_Items = { noteA, statueA }; //Creating items
    std::vector <ItemClass> roomB_Items = { keyB };
    std::vector <ItemClass> library_Items = {Book};
    std::vector<ItemClass>diningHallItems = { metalSafe, deadBody1,deadBody2,deadBody3,deadBody4 };
    std::vector <ItemClass> hiddensection_Items = { Candle1 };
    std::vector <ItemClass> storytellerItems = { storyBook }; //Storyteller's items
    std::vector <ItemClass> masterBedroomItems = { candle3 }; //Master bedroom items
    //InteractClass* userInteractCandle = new InteractClass("Would you like to look at the candle?", "Pickup the candle");
    std::vector<ItemClass>studyItem = { studyCandle };
    std::vector<ItemClass>kitchenItems = { kitchenCounter };
    std::vector <ItemClass> portraits = { lordPainting, barkeepPainting };


    //define puzzle solution/s
    std::vector <std::string> mirrorSolution = { "MOONLIGHT", "FOREST GREEN", "BLACK" };
    //defining Gallery puzzle
    GalleryPuzzle galleryPuzzle = GalleryPuzzle(portraits, { lordPainting });
    //defining mirror puzzle
    MirrorPuzzle mirrorPuzzle = MirrorPuzzle(mirrorSolution);
    //defining fountain puzzle
    FountainPuzzle fountainPuzzle = FountainPuzzle("FEAR", "MEMORY", "CLOCK", "GRAVE");
    //defining maze puzzle
    MazePuzzle mazePuzzle = MazePuzzle({ "RABBIT", "CROW", "SNAKE", "SCARAB" });

    InteractClass* mirrorPuzzleStarterInteraction = new InteractClass("Do you want to solve the three word combination? (YES or NO)", "Test", mirrorPuzzle);
    InteractClass* altarInteraction = new InteractClass("Do you want to initiate puzzle? (YES or NO)", "Test", galleryPuzzle);
    InteractClass* fountainPuzzleStarterInteraction = new InteractClass("Do you want to begin the Fountain Puzzle? (YES or NO)", "Test", fountainPuzzle);
    InteractClass* mazePuzzleStarterInteraction = new InteractClass("You should explore the maze, paying attention to your surrondings, do you want to explore? (YES or NO)", "Test", mazePuzzle);
    ItemClass mirrorPuzzleStarter = ItemClass("COMBINATION LOCK", "A three word combination lock...", false, mirrorPuzzleStarterInteraction);
    ItemClass galleryPuzzleStarter = ItemClass("ALTAR", "An altar stands before you with a knife...", false, altarInteraction);
    ItemClass fountainPuzzleStarter = ItemClass("FOUNTAIN PANEL", "A panel in the base of the fountain seems like you could push it like a button...", false, fountainPuzzleStarterInteraction);
    ItemClass mazePuzzleStarter = ItemClass("LANTERN", "A lantern to help you see while exploring the maze...", false, mazePuzzleStarterInteraction);
    std::vector <ItemClass> upstairsItems = { noteUpA, mirrorPuzzleStarter }; //Upstairs items
    std::vector <ItemClass> galleryItems = { galleryPuzzleStarter, lordPainting, barkeepPainting }; //Gallery items
    std::vector <ItemClass> fountainItems = { fountainPuzzleStarter }; //Fountain items
    std::vector <ItemClass> mazeExitItems = { candle4 }; //Maze exit items
    std::vector <ItemClass> hedgeMazeItems = { mazePuzzleStarter }; //Hedge Maze Items

    //Defining downstairs rooms
    rooms["FOYER"] = RoomClass("You enter the foyer, the walls are lined with faded wallpaper and adorned with massive grim portraits of long forgotten residents whose eyes seem to follow your every move. A dim eeries light illuminates the room, as you stand here in feeling the chill of the cold and heavy air surronding you. There also appears to be a ornate wooden DOOR that is locked.\n", "FOYER", std::list<std::string>{"LOUNGE", "DOOR","KITCHEN DOOR",}, FoyerDoors, roomA_Items);
    rooms["LIBRARY"] = RoomClass("You enter the library, filled to the brim with bookshelves.\n", "LIBRARY", std::list<std::string>{"FOYER", "BOOKSHELF", "GREATER LIBRARY DOOR"}, Library_Doors, library_Items);
    rooms["LOUNGE"] = RoomClass("You enter the lounge, There is a staircase, however there is a black sludge blocking the way\n", "LOUNGE", std::list<std::string>{"FOYER", "DINING HALL DOOR"}, roomB_Items);
    rooms["GREATER LIBRARY"] = RoomClass("You are now in the greater library, many books and shelves are around and there seems to be a door leading to another room to a office , you must solve the puzzle to enter!!", "GREATER LIBRARY", std::list<std::string>{"LIBRARY", "PUZZLE"});
    rooms["STUDY"] = RoomClass("You enter the study, the walls are dark brown with shelfs full of books and paper scrolls. There is a desk that is rather neat and organize. Behind the desk is grand portrait of a man with a stern face, eyes so dark its you uncomfortable.The man's finger is pointing to what seems to be a cabinet and on behind a pile of books you see a candle.", "STUDY", std::list<std::string>{"GREATER LIBRARY"}, studyItem);
    //defenition for ritual room class, specific constructor
    rooms["RITUAL ROOM"] = RoomClass("You enter a room that does not invite you back. A perfect, pentacle drawn on the floor invites you to place a candle at each of it's vertecies. [Hint: enter CANDLE as input if you posses a candle]", "RITUAL ROOM", std::list<std::string>{"HIDDEN SECTION",}, true);
    //HIDDEN SECTION 
    rooms["HIDDEN SECTION"] = RoomClass("You now enter the hidden section, nothing is safe here, you feel a presense linger, as if it was plucking your heartstrings, there is a table with a candle on top", "HIDDEN SECTION", std::list<std::string>{"LIBRARY", "RITUAL ROOM"}, hiddensection_Items);
    
    //PORTAL
    RoomClass PORTAL = RoomClass("You step into the portal, and feel a strange pull as reality warps around you. Moments later, you find yourself in a different part of the mansion.",
        "PORTAL", std::list<std::string>{}, FoyerDoors, std::vector<ItemClass>{});
   
    //Defining upstairs rooms
    rooms["UPSTAIRS"] = RoomClass("You are now upstairs. The area is dimly lit, and there are several doors leading to other parts of the mansion. There is a set of double doors at the end of the hallway with a complex lock. The lock has two halves of a dais empty, that form an opening mechanism similair to a safe. There is also a three word combination lock on the wall in between MIRROR ROOM 1 and MIRROR ROOM 2.",
        "UPSTAIRS", std::list<std::string>{"PORTAL", "MIRROR ROOM 1", "MIRROR ROOM 2", "STORYTELLER'S ROOM", "GALLERY", "DOUBLE DOORS"}, Master_Doors, upstairsItems);  // Add PORTAL as an option
    //Defining upstairs rooms
    rooms["MIRROR ROOM 1"] = RoomClass("You enter a grand parlor bathed in soft, golden sunlight streaming through tall, arched windows. The room is elegantly furnished, with a velvet chaise lounge positioned in the center, its deep burgundy fabric complementing the warm tones of the oak-paneled walls. A large, ornate mirror hangs above a marble fireplace on the north wall. On a small table beside the chaise, a crystal vase holds a single white rose, perfectly fresh. The air smells faintly of lavender, adding a serene ambiance to the room. A plush rug, embroidered with intricate floral patterns, covers the floor, leading to a door on the opposite side of the room.", "MIRROR ROOM 1", std::list<string>{"UPSTAIRS"});
    rooms["MIRROR ROOM 2"] = RoomClass("Stepping into this parlor feels eerily familiar. Bathed in soft golden moonlight streaming through tall, arched windows. The room is elegantly furnished, with a velvet chaise lounge positioned in the center, its deep forest green fabric complementing the warm tones of the oak-paneled walls. A large, ornate mirror hangs above a marble fireplace on the north wall. On a small table beside the chaise, a crystal vase holds a single black rose, perfectly fresh. The air smells faintly of soot, adding a serene ambiance to the room. A plush rug, embroidered with intricate floral patterns, covers the floor, leading to a door on the opposite side of the room.", "MIRROR ROOM 2", std::list<string>{"UPSTAIRS"});
    rooms["STORYTELLER'S ROOM"] = RoomClass("You enter a room filled with a luxuorious carpet, fancy linen bedsheets, and elegant embroidery all about. In the center of the room on a stand, is a big tome open to the page of a story.", "STORYTELLER'S ROOM", std::list <string> {"UPSTAIRS"}, storytellerItems); //have a non pick upable item with poem in it
    rooms["GALLERY"] = RoomClass("You enter a room with many portraits, all of them depicting different people of different statuses. All of the portraits are almost calling you to touch them.", "GALLERY", std::list <string> {"UPSTAIRS"}, galleryItems); //Room full of portraits for poem puzzle
    rooms["MASTER BEDROOM"] = RoomClass(
        "You are now in the Master Bedroom. The room is elegantly decorated with fine linens and rich colors.",
        "MASTER BEDROOM",
        std::list<std::string>{"UPSTAIRS", "GARDEN"}, // Add GARDEN as an option
        masterBedroomItems
    );    rooms["DINING HALL"] = RoomClass("You are now in the Dining Hall. There is a large table and chairs. From here, you can go to the kitchen.\n", "DINING HALL", std::list<std::string>{"DINING HALL DOOR", "KITCHEN"}, diningHallItems);
    rooms["KITCHEN"] = RoomClass("You are now in the Kitchen,You can return to the dining hall from here.\n", "KITCHEN", std::list<std::string>{"DINING HALL", "KITCHEN DOOR"}, kitchenItems);
    rooms["GARDEN"] = RoomClass(
        "You step outside into a serene garden, filled with vibrant flowers and lush greenery. The moon shines brightly above, and you can hear the gentle rustling of leaves in the breeze. There's a feeling of tranquility here, but also an underlying sense of mystery, as if the garden holds secrets waiting to be uncovered.",
        "GARDEN",
        std::list<std::string>{"SHED", "FOUNTAIN", "BLOCKED HEDGE MAZE"},
        mazeDoors,
        std::vector<ItemClass>{} // No items initially in the garden
    );

    // Shed Room
    rooms["SHED"] = RoomClass(
        "You enter a small, dusty shed filled with various gardening tools and supplies. The air is thick with the smell of soil and wood. A single window allows a sliver of moonlight to illuminate the cobwebs in the corners.",
        "SHED",
        std::list<std::string>{"GARDEN"}, // Only accessible back to the Garden
        shedDoors, // Use the empty shed doors
        std::vector<ItemClass>{} // No items in the shed
    );

    // Hedge Maze Room
    rooms["HEDGE MAZE"] = RoomClass(
        "You find yourself in a sprawling hedge maze. Tall hedges tower around you, creating a sense of disorientation. The paths are winding, and the sound of rustling leaves fills the air. You sense that there might be hidden corners to explore.",
        "HEDGE MAZE",
        std::list<std::string>{"GARDEN", "MAZE EXIT"}, // Only accessible back to the Garden
        mazeExitDoors, // Use the empty maze doors
        hedgeMazeItems // items in the maze
    );

    rooms["HEDGE MAZE EXIT"] = RoomClass("You exit the hedge maze into a small clearing with a bird fountain, this place seems very calm, almost safe.", "HEDGE MAZE EXIT", std::list<string> {"HEDGE MAZE"}, mazeExitDoors, mazeExitItems);

    // Fountain Room
    rooms["FOUNTAIN"] = RoomClass(
        "You arrive at a beautifully ornate fountain, its waters sparkling in the sunlight. The sound of water gently cascading down creates a soothing atmosphere. Surrounding the fountain are blooming flowers and lush greenery, adding to the serenity of the space.",
        "FOUNTAIN",
        std::list<std::string>{"GARDEN"}, // Only accessible back to the Garden
        fountainDoors, // Use the empty fountain doors
        fountainItems // No items at the fountain
    );
    
    std::string startingRoom = "A";
    bool puzzleSolved = false;

    PlayerClass userPlayer = PlayerClass(rooms["FOYER"]);
    userPlayer.addItem(Candle1);
    userPlayer.addItem(studyCandle);
    userPlayer.addItem(candle3);

    while (true) {
        RoomClass& currentRoom_temp = userPlayer.getRoom(); //temp current room instance of roomClass to access room data
        
        UI.displayPrompt(currentRoom_temp.AmendDescription());
        //UI.displayPrompt(userPlayer.getRoomDescription());
        //currentRoom_temp.displayRoomItems(); //Displaying room items, TEMP function until can implement into UI class
        //std::cout << endl;
       // currentRoom_temp.displayAdjacentRooms(); //Displaying adjacent rooms, TEMP function until can implement into UI class
        UI.displayPrompt("\nYou cant contain your curiosity and have the urge to INSPECT the items in the room. (type 'INVENTORY' to open inventory. Type 'QUIT' to exit the game)\n"); //user input 
        std::string command = UI.userInput();

        // Boolean to track whether the kitchen door is open
        bool kitchenDoorOpen = false;

        // Check the command for the kitchen door
        if (command == "KITCHEN DOOR" && userPlayer.getRoomName() == "KITCHEN" && rooms.find("FOYER") != rooms.end()) {
            // Player is in the kitchen and wants to enter the foyer through the door
            if (!kitchenDoorOpen) {
                UI.displayPrompt("\nYou open the door to the foyer.\n");
                kitchenDoorOpen = true;  // Door remains open after first use
            }
            userPlayer.setRoom(rooms["FOYER"]);  // Move player to the foyer

            // Add "KITCHEN" as an option in the foyer room only if it’s not already there
            auto currentRoom_temp = rooms["FOYER"];
            std::list<std::string> updatedOptions = currentRoom_temp.GetRoomOption();

            // Check if "KITCHEN" is already in the options
            if (std::find(updatedOptions.begin(), updatedOptions.end(), "KITCHEN") == updatedOptions.end()) {
                updatedOptions.push_back("KITCHEN");
                currentRoom_temp.setRoomOption(updatedOptions);

                // Update the foyer room in the map
                rooms["FOYER"] = currentRoom_temp;
            }

            UI.displayPrompt("\nYou are now in the foyer. You can use the 'KITCHEN' command to return to the kitchen.\n");
        }
        else if (command == "KITCHEN DOOR" && userPlayer.getRoomName() == "FOYER") {
            // Allow access back to the kitchen if the door is open
            if (kitchenDoorOpen) {
                UI.displayPrompt("\nYou pass through the open door to the kitchen.\n");
                userPlayer.setRoom(rooms["KITCHEN"]);  // Move player back to the kitchen
            }
            else {
                UI.displayPrompt("\nThe door to the kitchen is locked from this side.\n");
            }
        }

        // Boolean to track whether the dining hall door is open
        bool diningHallDoorOpen = false;

        // Check the command for the dining hall door
        if (command == "DINING HALL DOOR" && userPlayer.getRoomName() == "DINING HALL" && rooms.find("LOUNGE") != rooms.end()) {
            // Player is in the dining hall and wants to enter the lounge through the door
            if (!diningHallDoorOpen) {
                system("cls");
                UI.displayPrompt("\nYou open the door to the lounge.\n");
                diningHallDoorOpen = true;  // Door remains open after first use
            }
            userPlayer.setRoom(rooms["LOUNGE"]);  // Move player to the lounge

            // Add "DINING HALL" as an option in the lounge room only if it’s not already there
            auto currentRoom_temp = rooms["LOUNGE"];
            std::list<std::string> updatedOptions = currentRoom_temp.GetRoomOption();

            // Check if "DINING HALL" is already in the options
            if (std::find(updatedOptions.begin(), updatedOptions.end(), "DINING HALL") == updatedOptions.end()) {
                updatedOptions.push_back("DINING HALL");
                updatedOptions.remove("DINING HALL DOOR"); // Remove the dining hall door as an option in the foyer 
                currentRoom_temp.setRoomOption(updatedOptions);

                // Update the lounge room in the map
                rooms["LOUNGE"] = currentRoom_temp;
            }

            UI.displayPrompt("\nYou are now in the lounge. You can use the 'DINING HALL' command to return to the dining hall.\n");
        }
        else if (command == "DINING HALL" && userPlayer.getRoomName() == "LOUNGE") {
            system("cls");
            // Allow access back to the dining hall if the door is open
            if (diningHallDoorOpen) {
                system("cls");
                UI.displayPrompt("\nYou pass through the open door to the dining hall.\n");
                userPlayer.setRoom(rooms["DINING HALL"]);  // Move player back to the dining hall
            }
            else {
                system("cls");
                UI.displayPrompt("\nThe door to the dining hall is locked from this side.\n");
            }
        }
        else if (command == "DINING HALL DOOR" && userPlayer.getRoomName() == "LOUNGE") {
            system("cls");
            UI.displayPrompt("The DINING HALL DOOR is locked from this side\n");
        }

        if (command == "CANDLE" && userPlayer.getRoomName() == "RITUAL ROOM") //user will type candle in input section to place a candle, only a valid input if they are in the RITUAL ROOM
        {
            if (userPlayer.getInventorySize() != 0)
            {
           
                if (userPlayer.inInventory("CANDLE","C1"))
                {
                    userPlayer.useItem("CANDLE","C1"); //Uses Candle from inventory, is removed
                    UI.displayPrompt("You have placed a candle\n");
                    currentRoom_temp.addCandle();
                    UI.displayPrompt(std::to_string(currentRoom_temp.getCandleValue()));// for testing purposes to see if candle is added to room
                    // Open the tunnel to the kitchen
                    UI.displayPrompt("As you place the candle, a hidden tunnel opens, leading to the kitchen!\n");

                    // Add "KITCHEN" to the list of accessible rooms from the ritual room
                    std::list<std::string> updatedOptions = currentRoom_temp.GetRoomOption();
                    updatedOptions.push_back("KITCHEN");
                    currentRoom_temp.setRoomOption(updatedOptions);

                    // Update the room in the map
                    rooms["RITUAL ROOM"] = currentRoom_temp;
                    continue;
                }
                else if (userPlayer.inInventory("CANDLE", "C2"))
                {
                     userPlayer.useItem("CANDLE", "C2");     //Uses the specified candle with its id to be used
                     UI.displayPrompt("You have placed a candle\n");
                     currentRoom_temp.addCandle();
                     UI.displayPrompt(std::to_string(currentRoom_temp.getCandleValue()));// for testing purposes to see if candle is added to room
                     UI.displayPrompt("As you place the candle, a portal is revealed!\n");
                        
                     std::list<std::string>updatedOptions = currentRoom_temp.GetRoomOption();
                     updatedOptions.push_back("PORTAL");
                     currentRoom_temp.setRoomOption(updatedOptions);
                     UI.displayPentacle(currentRoom_temp.getCandleValue());
                     //Update the room in the map
                     rooms["RITUAL ROOM"] = currentRoom_temp;
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
            system("cls");
            viewInventory(userPlayer); //Call view inventory function
            UI.displayPrompt("\n");
        }

        else if (command == "INSPECT") //If user wants to pick up item
        {
            system("cls");
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
                        system("cls");
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
                                    rooms[currentRoom_temp.GetName()] = currentRoom_temp;
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
                else if (command == "METAL SAFE")
                {
                    UI.displayPrompt("Enter the 4 digit code");
                    string safeInput = UI.userInput();

                    try {
                        int safeInputNum = std::stoi(safeInput);

                        if (safeInputNum == 8691)
                        {
                            UI.displayPrompt("You entered the correct passcode! Safe is now open and there's a key");

                            rooms["DINING HALL"].RemoveItem(metalSafe);
                            rooms["DINING HALL"].AddItem(diningHallKey);
                            rooms["DINING HALL"].displayRoomItems();
                            
                        }
                        else
                            UI.displayPrompt("You entered the wrong passcode. Try again");
                    }
                    catch (const std::invalid_argument& e) {
                        UI.displayPrompt("You entered the wrong passcode. Try again");
                    }
                }


                else if (currentRoom_temp.getRoomItemByName(itemName).getInteraction()->getIsPuzzle() == true) //If interaction is a puzzle, call overloaded runInteraction
                {
                    currentRoom_temp.getRoomItemByName(itemName).getInteraction()->runInteraction(userPlayer, galleryKey, mirrorKey, masterKey, mazeKey, mazeExitKey); //Clunky solution right now, considering using an extra if statement to confirm player is in upstairs or gallery to call this puzzle
                }
                else //Run interact sequence if not pick up able object
                {
                    currentRoom_temp.getRoomItemByName(itemName).getInteraction()->runInteraction();
                }
            }


        }
        else {
            //std::string current_room = userPlayer.getRoomName();
            std::list<std::string> validInputs = currentRoom_temp.GetRoomOption();
            if (std::find(validInputs.begin(), validInputs.end(), command) != validInputs.end()) //algorithm to parse command in valid room options
            {
                /*before you read: THIS IS A TEMPORARY FUNCTIONALITY FOR ROOM DETECTION THIS WILL BE REFACTORED WHEN WE DECIDE HOW TO BUILD OUR MAP
                TODO: setup hashmap for corresponding rooms, implement functionality to minimize conditional nesting*/
                if (rooms.find(command) != rooms.end()) {
                    system("cls");
                    userPlayer.setRoom(rooms[command]);
                }
                else if (command == "PORTAL") {
                    system("cls");
                    if (userPlayer.getRoom().GetName() == "UPSTAIRS") {
                        userPlayer.setRoom(rooms["FOYER"]);  // If user is upstairs, return to Room A via the portal
                        UI.displayPrompt("You step through the portal and find yourself back in the foyer (Room A).");
                    }
                    else {
                        userPlayer.setRoom(PORTAL);  // Move to the portal room first
                        UI.displayPrompt("You have entered the portal and now find yourself upstairs.");
                        userPlayer.setRoom(rooms["UPSTAIRS"]);  // Automatically move to the upstairs room
                    }
                }
                else if (command == "DOUBLE DOORS") {
                    std::list<std::string> options = { "PORTAL", "MIRROR ROOM 1", "MIRROR ROOM 2", "STORYTELLER'S ROOM", "GALLERY", "MASTER BEDROOM" };
                    handleDoors(userPlayer, currentRoom_temp, "MASTER BEDROOM", options, rooms);
                }
                else if (command == "DOOR") {
                    std::list<std::string> options = { "LOUNGE", "LIBRARY", "KITCHEN DOOR" };
                    handleDoors(userPlayer, currentRoom_temp, "LIBRARY", options, rooms);
                }
                else if (command == "GREATER LIBRARY DOOR")
                {
                    std::list<std::string> options = {"FOYER", "HIDDEN SECTION", "LIBRARY","GREATER LIBRARY"};
                    handleDoors(userPlayer, currentRoom_temp, "GREATER LIBRARY", options, rooms);
                }
                else if (command == "BOOKSHELF") {
                    std::list<std::string> options =  {"FOYER","HIDDEN SECTION", "GREATER LIBRARY DOOR"};
                    handleDoors(userPlayer, currentRoom_temp, "HIDDEN SECTION", options, rooms);
                    std::cout << "You place the book on the shelf. The Bookshelf begins to move, screeching across the wooden floor. It reveals a staircase leading down to the HIDDEN SECTION. \n\n";
                }
                else if (command == "BLOCKED HEDGE MAZE")
                {
                    std::list<std::string> options = { "SHED", "FOUNTAIN", "HEDGE MAZE"};
                    handleDoors(userPlayer, currentRoom_temp, "HEDGE MAZE", options, rooms);
                }
                else if (command == "MAZE EXIT")
                {
                    std::list<std::string> options = { "GARDEN", "HEDGE MAZE EXIT"};
                    handleDoors(userPlayer, currentRoom_temp, "HEDGE MAZE EXIT", options, rooms);
                }
                else if (command == "PUZZLE")
                {
                    system("cls");
                    if (!puzzleSolved)
                    {
                        UI.displayPrompt("The door is locked there seems to be a puzzle before entering. Solve this puzzle.\n");
                        UI.displayPrompt("The secret word is DIDDY\n");
                        std::string puzzleAnswer = UI.userInput();

                        if (puzzleAnswer == "DIDDY") {
                            UI.displayPrompt("You solved the puzzle you can now enter the study\n");
                            puzzleSolved = true;
                            currentRoom_temp.setRoomOption(std::list<std::string>{"LIBRARY", "STUDY"});
                            rooms[currentRoom_temp.GetName()] = currentRoom_temp; //update room in map
                        }
                        else {
                            UI.displayPrompt("That is not the correct answer. The door remains locked.\n");
                        }

                    }
                }
            }
            else
            { //catch invalid input NOTE - in the future we will refactor to utilize UI class input validation
                system("cls");
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


void GameControllerClass::handleDoors(PlayerClass& player, RoomClass& currentRoom, const std::string& targetRoom, const std::list<std::string>& newRoomOptions,std::unordered_map<std::string,RoomClass>& rooms)
{
    system("cls");
    std::vector<Door>& doors = currentRoom.GetDoors();
  
    for (int i = 0; i < doors.size(); i++) {
        if (doors[i].getIsLocked()) {
            if (player.getInventorySize() != 0) {

                std::string playerKey = player.searchForKey(doors[i].getDoorKeyID());


                if (doors[i].getDoorKeyID() == playerKey)
                {
                    player.useKey(playerKey); //Uses correct key from inventory
                    UI.displayPrompt("You unlock the door with the key in your pocket, you can now traverse to the " + targetRoom + ".\n");
                    currentRoom.unlockDoor(i); //unlocks door, sets description to different openDoor description through
                    doors[i].unlockDoor();
                    currentRoom.setRoomOption(newRoomOptions); //set options to new, this is TEMPORARY solution and there will be refactor which includes function within room class to find the option to modify instead of setting it explicity
                    player.setRoom(currentRoom); //set room
                    break;
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
            //player.setRoom(rooms[targetRoom]);
            //currentRoom_temp = userPlayer.getRoom();
        }

    
    }

}




