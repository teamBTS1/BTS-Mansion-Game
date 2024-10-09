

#pragma once
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <string>
#include "UserInterfaceClass.h"


class GameControllerClass
{
	//Game controller class is responsible for driving the game, it will contain functions to start and end the game and utilizes the UserInterfaceClass to process inputs etc.

	private: 
	UserInterfaceClass UI;
	std::string backstory;

public:
	GameControllerClass(); 
	//constructor
	void startGame();
	//mbr function to start the game for user
	void showMenu();
	//mber function to show menu to user via UI object
	void gameLoop();
	//mber function which is responsible for driving the game; it is the main game loop where the users actions will be parsed and output will be displayed via UI object
	void displayBackstory();
	//function to display backstory to user
	void endGame();
	//mber function which will exit game loop if chosen
	void pickUpNoteSequence(); 
	//function that displays option to pick up note in room A
	void displayInventory();
	// shows inventory
	void viewInventory();
	//prompts to view inventory
};

#endif