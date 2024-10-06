#include "UserInterfaceClass.h"
#include <iostream>

UserInterfaceClass::UserInterfaceClass()
{
    current_input = "";
}
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

void UserInterfaceClass::setCurrentInput(std::string& uInput)
{
    UserInterfaceClass::current_input = uInput; //set passed string to current input private member variable
}

std::string UserInterfaceClass::getCurrentInput() const
{
    return current_input; //returns string of current input private member variable
}

std::string UserInterfaceClass::userInput() 
{
    std::string input;
    std::getline(std::cin, input);
    this->setCurrentInput(input); //sets current input to this
    return input;
}

void UserInterfaceClass::waitForInput() const {
    std::cin.ignore();  // Wait for the user to press Enter
}

bool UserInterfaceClass::isValidInput(const std::string[]) const
{
    //TODO: add logic
    return true;
}
