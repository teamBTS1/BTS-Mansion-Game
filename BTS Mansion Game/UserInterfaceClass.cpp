/* #include "UserInterfaceClass.h"
#include <iostream>


void UserInterfaceClass::displayPrompt(const std::string& prompt) const
{
	std::cout << prompt << std::endl; //prints strng passed
}
void UserInterfaceClass::displayMenu() const
{
	std::cout << "***Welcome to the BTS Mansion Game!***" << std::endl; //No title yet, change in future and adjust for story building etc etc
    std::cout << "===== Main Menu =====" << std::endl;
    std::cout << "START Game" << std::endl;
    std::cout << "QUIT" << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "Words in all caps will be input options for this game, please enter an option: ";
}
std::string UserInterfaceClass::userInput() const
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void UserInterfaceClass::waitForInput() const {
    std::cin.ignore();  // Wait for the user to press Enter
}

bool UserInterFaceClass::isValidInput(const std::string& input, const std::string[] &) const
{
    //TODO: add logic
}

*/