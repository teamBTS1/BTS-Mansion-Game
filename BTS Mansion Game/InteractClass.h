#pragma once
#ifndef InteractClass_H
#define InteractClass_H

#include<iostream>
#include<string>
using namespace std;
class InteractClass
{
private:
	string inputMessage;
	string outputMessage;
public:
	//Constructor
	InteractClass();

	// Funtion to set input message 
	void setInputMessage(const string& message);
	// function to set output message 
	void setOutputMessage(const string& message);
	// function for input from player
	void getUserInput();
	// function to output message
	void displayInput();
	//function to interact with object or statue
	void runInteraction();

	//Only write declarations here, actual code will be in cpp file.
};
#endif 
