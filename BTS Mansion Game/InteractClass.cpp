#include "InteractClass.h"
// Constructor
InteractClass::InteractClass() {
    inputMessage = "";
    interactMessage = "";
}

InteractClass::InteractClass(std::string inMssg, std::string interactMssg) {
    inputMessage = inMssg;
    interactMessage = interactMssg;
}

// Function to set input message
void InteractClass::setInputMessage(const std::string& message) {
    inputMessage = message;
}

// Function to set output message
void InteractClass::setOutputMessage(const std::string& message) {
    interactMessage = message;
}



// Function to interact with item or object
void InteractClass::runInteraction() {
    UserInterfaceClass ui;
    //input interaction message;
    ui.displayPrompt(inputMessage);
    //simulate user input demonstrate
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

