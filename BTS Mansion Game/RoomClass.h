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
	std::list<ItemClass> items; //List of items that are contained in the room.

	


public:
	RoomClass(); //Default constructor
	RoomClass(std::string description); //Constructor that only takes the description as input.
	RoomClass(std::string description, Door &door);
	RoomClass(std::string description, bool isLockedRoom);
	Door GetDoor(); //Returns the door associated with the room
	std::string GetDescription(); //Returns a description of the room
	std::string GetFullDescription(); //Returns the full description of the room as a concatenated string, including all items and connecting rooms.
	std::string GetName(); //Returns the name of the room
	void ReplaceDescription(std::string newDescription); //Replaces the room description with a new one.
	void AmendDescription(std::string addition); //Adds the inputted string to the end of the room description.



};

#endif