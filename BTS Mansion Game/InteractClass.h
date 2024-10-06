#pragma once
#ifndef InteractClass_H
#define InteractClass_H

#include<iostream>
#include<string>
#include "PickUpItemClass.h" //Include header for PickUpItemClass
class InteractClass
{
private:
	std::string inputMessage;
	std::string outputMessage;
public:
	//Constructor
	InteractClass();

	// Funtion to set input message 
	void setInputMessage(const std::string& message);
	// function to set output message 
	void setOutputMessage(const std::string& message);
	//function to interact with object or statue
	void runInteraction();
	// function to display object description
	void displayDescription();
	
	void pickupItem(const PickUpItemClass& item);
	//Only write declarations here, actual code will be in cpp file.
};
#endif 
