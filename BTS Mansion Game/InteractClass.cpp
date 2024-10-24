#include "InteractClass.h"
// Constructor
InteractClass::InteractClass() {
    inputMessage = "";
    interactMessage = "";
    interacted = false;
    isPuzzle = false;
}

InteractClass::InteractClass(std::string inMssg, std::string interactMssg) {
    inputMessage = inMssg;
    interactMessage = interactMssg;
    interacted = false;
    isPuzzle = false;
}

InteractClass::InteractClass(std::string inMssg, std::string interactMssg, GalleryPuzzle puzz) { //Constructor for gallery puzzle
    inputMessage = inMssg;
    interactMessage = interactMssg;
    interacted = false;
    puzzle = puzz;
    isPuzzle = true;
}

InteractClass::InteractClass(std::string inMssg, std::string interactMssg, MirrorPuzzle puzz) { //constructor for mirror puzzle
    inputMessage = inMssg;
    interactMessage = interactMssg;
    interacted = false;
    mPuzzle = puzz;
    isPuzzle = true;
}

// Function to set input message
void InteractClass::setInputMessage(const std::string& message) {
    inputMessage = message;
}

// Function to set output message
void InteractClass::setOutputMessage(const std::string& message) {
    interactMessage = message;
}

bool InteractClass::getIsPuzzle()
{
    return isPuzzle;
}


// Function to interact with item or object
void InteractClass::runInteraction() {
    UserInterfaceClass ui;
    //input interaction message;

    //simulate user input demonstrate
    if (isPuzzle == true)
    {
        if (puzzle.isSolved() == false)
        {
            ui.displayPrompt(inputMessage);
            if (ui.userInput() == "YES")
            {
                puzzle.runPuzzle();
            }
            else
            {
                ui.displayPrompt("You walk away.");
            }
        }
        else
        {
            ui.displayPrompt("This item seems dormant...");
        }
    }
    else {
        ui.displayPrompt(inputMessage);
        ui.displayPrompt("Enter action (INTERACT): ");
        ui.userInput();

        if (ui.getCurrentInput() == "INTERACT")
        {
            //output interaction message
            ui.displayPrompt(interactMessage);
        }
        else {
            ui.displayPrompt("You walk away.");
        }
    }
    
}

void InteractClass::runInteraction(PlayerClass& player, ItemClass& galleryItm, ItemClass& mirrorItm, ItemClass& masterItm) { //Function to run an interaction with items and picking up
    UserInterfaceClass ui;
    //input interaction message;
    //simulate user input demonstrate
    if (isPuzzle == true) //Check if interaction is a puzzle
    {
        if (puzzle.isSolved() == false) //Is the puzzle solved
        {
            if (puzzle.getDescription() == "Gallery Puzzle") //if in gallery puzzle execute gallery puzzle
            {
                ui.displayPrompt(inputMessage);
                if (ui.userInput() == "YES")
                {
                    puzzle.runPuzzle();
                    if (puzzle.isSolved() == true)
                    {
                        PickUpItemClass pickup(galleryItm);
                        pickup.addToInventory(player);

                        std::vector <ItemClass>& inv = player.getInventory();
                        for (auto& item : inv)
                        {
                            if (item.getName() == "MIRROR HALF KEY")
                            {
                                player.removeItem(item.getName());
                                ui.displayPrompt("You put both halves of your key together to form the MASTER BEDROOM KEY!");
                                player.addItem(masterItm);
                                return;
                            }
                        }
                    }
                }
                else
                {
                    ui.displayPrompt("You walk away.");
                }
            }
            else if (mPuzzle.getDescription() == "Mirror Puzzle") //if in mirror puzzle execute mirror puzzle
            {
                mPuzzle.runPuzzle();
                if (mPuzzle.isSolved())
                {
                    ui.displayPrompt("You solved the Mirror Puzzle!");
                    PickUpItemClass pickup(mirrorItm);
                    pickup.addToInventory(player);
                    
                    std::vector <ItemClass>& inv = player.getInventory();
                    for (auto &item : inv)
                    {
                        if (item.getName() == "GALLERY HALF KEY")
                        {
                            player.removeItem(item.getName());
                            ui.displayPrompt("You put both halves of your key together to form the MASTER BEDROOM KEY!");
                            player.addItem(masterItm);
                            return;
                        }
                    }
                }
                else
                {
                    ui.displayPrompt("You failed to solve the mirror puzzle");
                }
            }
        }
        else
        {
            ui.displayPrompt("This item seems dormant...");
        }
    }
    else {
        ui.displayPrompt(inputMessage);
        ui.displayPrompt("Enter action (INTERACT): ");
        ui.userInput();

        if (ui.getCurrentInput() == "INTERACT")
        {
            //output interaction message
            ui.displayPrompt(interactMessage);
        }
        else {
            ui.displayPrompt("You walk away.");
        }
    }

}
//function to display object description
void InteractClass::displayDescription() {
    ui.displayPrompt(interactMessage); // uses userinterface class to display description 
}
//Function to Pickup an item
void InteractClass::pickupItem(const PickUpItemClass& item) {
    std::cout << "" << std::endl;
}
//function to use UserInterfaceClass
void InteractClass::useUserInterface() {
    //
}
