#include "InteractClass.h"
// Constructor
InteractClass::InteractClass() : inputMessage(""), outputMessage("") {}

// Function to set input message
void InteractClass::setInputMessage(const std::string& message) {
    inputMessage = message;
}

// Function to set output message
void InteractClass::setOutputMessage(const std::string& message) {
    outputMessage = message;
}

// Function to get input from the user
void InteractClass::getUserInput() {
    std::cout << inputMessage << std::endl;
    std::getline(std::cin, inputMessage); // get user input
}

// Function to display the output message
void InteractClass::displayInput() {
    std::cout << outputMessage << std::endl;
}

// Function to interact (combine input/output operations)
void InteractClass::runInteraction() {
    getUserInput();
    displayInput();
}
