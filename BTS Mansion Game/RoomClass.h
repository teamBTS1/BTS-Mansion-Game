#pragma once
#ifndef ROOMCLASS_H
#define ROOMCLASS_H


#include <list>
#include <string>
#include "Door.h"
#include "ItemClass.h"



class RoomClass
{
	//Class to represent an in-game location.
private:
	Door roomDoor;
	std::string roomDescription; //Variable that stores a description of the room
	std::string roomName; //Variable that stores the name of the room
	//Need a way to indicate direction of room connections - not sure if that should be done here or in another class
	std::list<RoomClass> connectedRooms; //List of rooms that are connected to the room instance.
	std::list<std::string> RoomOptions; //list of room options in string
	std::list<ItemClass> items; //List of items that are contained in the room.

	


public:
	RoomClass(); //Default constructor
	RoomClass(std::string description, std::string name, std::list<std::string> options); //Constructor that takes name and description as input.
	RoomClass(std::string description, std::string name, std::list<std::string> options, Door& door); //constructor that takes name, description, room options and Door
	Door GetDoor(); //Returns the door associated with the room
	std::string GetDescription(); //Returns a description of the room
	void setRoomDescription(std::string newDescription); //sets room description
	std::string GetFullDescription(); //Returns the full description of the room as a concatenated string, including all items and connecting rooms.
	std::string GetName(); //Returns the name of the room
	std::list<std::string> GetRoomOption(); // returns options of room as list of strings
	void setRoomOption(std::list<std::string> options); // sets room options/overrides current room options
	std::string SetName(std::string name); // sets name of room
	void unlockDoor(); //unlocks door
	void ReplaceDescription(std::string newDescription); //Replaces the room description with a new one.
	void AmendDescription(std::string addition); //Adds the inputted string to the end of the room description.



};

#endif