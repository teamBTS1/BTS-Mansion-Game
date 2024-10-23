#pragma once
#ifndef InteractClass_H
#define InteractClass_H

#include<iostream>
#include<string>

#include "PickUpItemClass.h" //Include header for PickUpItemClass
#include "UserInterfaceClass.h" // Included header for UserInterFaceClass
#include "Puzzle.h"
#include "GalleryPuzzle.h"

class InteractClass
{
private:
	std::string inputMessage;
	std::string interactMessage;
	bool interacted;
	bool isPuzzle;
	GalleryPuzzle puzzle;
	UserInterfaceClass ui; // UserInterfaceClass for input and output

public:
	//Constructor
	InteractClass();
	InteractClass(std::string inMssg, std::string intMssg); //Constructor taking input and interact message
	InteractClass(std::string inMssg, std::string intMssg, GalleryPuzzle puzz); //Constructor taking input and interact message and gallery puzzle
	// Funtion to set input message 
	void setInputMessage(const std::string& message);
	// function to set output message 
	void setOutputMessage(const std::string& message);
	//Function to return if a puzzle is in interaction or not
	bool getIsPuzzle();
	//function to interact with object or statue
	void runInteraction();
	void runInteraction(PlayerClass& player, ItemClass& itm);
	// function to display object description
	void displayDescription();
	// function to pick up an item
	void pickupItem(const PickUpItemClass& item);
	// function to use UserInterfaceClass
	void useUserInterface();
	// funtion to handle the interaction with statue
	void interactWithStatue();

	//Only write declarations here, actual code will be in cpp file.

};
#endif 
