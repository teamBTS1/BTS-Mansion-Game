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


InteractClass* ItemClass::getInteraction()
{
    return interaction;
}

void ItemClass::setInteraction(InteractClass* interact)
{
    interaction = interact;
}
// Function to interact with item or object
void InteractClass::runInteraction() {
    //input interaction message;
    std::cout << inputMessage << std::endl;
    //simulate user input demonstrate
    std::string action;
    std::cout << "Enter action (INTERACT): ";
    std::cin >> action;
    if (action == "INTERACT")
    {
        //output interaction message
        std::cout << interactMessage << std::endl;
    }
    std::cout << "You walk away." << std::endl;

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

