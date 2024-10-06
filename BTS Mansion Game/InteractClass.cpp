#include "InteractClass.h"
// Constructor
InteractClass::InteractClass() {
    inputMessage = " ";
    outputMessage = " ";
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
    //output interaction message
    std::cout << outputMessage << std::endl;

}
void InteractClass::displayDescription() {
    std::cout << " " << std::endl;
}
void InteractClass::pickupItem(const PickUpItemClass& item) {
    std::cout << " " << std::endl;
}

