#pragma once
#ifndef USERINTERFACECLASS_H
#define USERINTERFACECLASS_H

#include <string>

class UserInterfaceClass
{
	/*User interface class is responsible for displaying messsages into the console and taking user input, it will also store elements such as the menu etc.*/
private:
	std::string current_input;
public:
	UserInterfaceClass();
	void displayPrompt(const std::string& prompt) const; 
	//display prompt will display any stinrg "prompt" given to the function
	void displayMenu() const;
	/*displays menu for the start of the game, will be in format of:
	Title
	===Main Menu===
	START Game
	QUIT
	===============
	Words in all caps will be input options for this game, please enter an option:*/

	std::string userInput();
	// will parse commands from user

	void setCurrentInput(std::string& uInput);
	// sets current input to whatever was entered by ueser through userInput() function

	std::string getCurrentInput() const;
	// gets current input to whatever was entered by user through userInput() function

	bool isValidInput(const std::string[]) const;
	// will compare user input to valid options (passed through as array of strings) and will return boolean variable according to whether user input is present in array or not

	void waitForInput() const;
	// waits for user press enter to progress certain multilined dialogue
};

#endif

