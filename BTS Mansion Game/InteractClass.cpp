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

InteractClass::InteractClass(std::string inMssg, std::string interactMssg, GalleryPuzzle puzz) {
    inputMessage = inMssg;
    interactMessage = interactMssg;
    interacted = false;
    puzzle = puzz;
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

void InteractClass::runInteraction(PlayerClass& player, ItemClass& itm) { //Function to run an interaction with items and picking up
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
                if (puzzle.isSolved() == true)
                {
                    PickUpItemClass pickup(itm);
                    pickup.addToInventory(player);
                }
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
