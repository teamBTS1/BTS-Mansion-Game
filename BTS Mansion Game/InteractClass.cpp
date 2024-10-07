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
    ui.displayPrompt("You have seen a statue with intresting marks "); // uses userinterface class to display description 
}
//Function to Pickup an item
void InteractClass::pickupItem(const PickUpItemClass& item) {
    std::cout << "" << std::endl;
}
// funtion to handle interaction proccess with statue in room A
void InteractClass::interactWithStatue() {
    int choice;
    do {
        std::cout << "You are in front of a statue , what do you want to do??\n";
        std::cout << "1.Read the description\n";
        std::cout << "2.Interact with Statue\n";
        std::cout << "3.Exit the interaction\n";
        std::cout << "Enter your choice (1 ,2, or 3):";
        std::cin >> choice;

        //Input validation and loop for correct choice
        if (choice == 1) {
            displayDescription();
        }
        else if (choice == 2)
        {
            runInteraction();
        }
        else if (choice == 3) {
            std::cout << "Exiting the interaction\n";
        }
        else
        {
            std::cout << "Invalid Choice try again" << std::endl;
        }
    } while (choice != 3);// keep looping until user selects exit 
}
//function to use UserInterfaceClass
void InteractClass::useUserInterface() {
    //
}

