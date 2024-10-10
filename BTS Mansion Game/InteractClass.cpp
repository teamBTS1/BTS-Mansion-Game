#include "InteractClass.h"
// Constructor
InteractClass::InteractClass() {
    inputMessage = "What would you like to do: ";
    outputMessage = "You Have interacted with the statue!";
}
// Function to set input message
void InteractClass::setInputMessage(const std::string& message) {
    inputMessage = message;
}

// Function to set output message
void InteractClass::setOutputMessage(const std::string& message) {
    outputMessage = message;
}
// Function to interact with item or object
void InteractClass::runInteraction() {
    //input interaction message;
    std::cout << inputMessage << std::endl;
    //simulate user input demonstrate
    std::string action;
    std::cout << "Enter action (interact): ";
    std::cin >> action;
    //output interaction message
    std::cout << outputMessage << std::endl;

}
//function to display object description
void InteractClass::displayDescription() {
    ui.displayPrompt("You have seen a statue with interesting marks "); // uses userinterface class to display description 
}
//Function to Pickup an item
void InteractClass::pickupItem(const PickUpItemClass& item) {
    std::cout << "" << std::endl;
}
//function to use UserInterfaceClass
void InteractClass::useUserInterface() {
    //
}

