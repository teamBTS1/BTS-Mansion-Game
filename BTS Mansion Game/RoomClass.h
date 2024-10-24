#pragma once
#ifndef ROOMCLASS_H
#define ROOMCLASS_H


#include <list>
#include <string>
#include <vector>
#include <iostream>
#include "Door.h"
#include "ItemClass.h"
#include "Puzzle.h"

using namespace std;



class RoomClass
{
	//Class to represent an in-game location.
private:
	std::vector<Door> roomDoors; 
	bool isRitual; //bool value that determines whether room is ritual room, default value is false
	int candles; // Candle count, will only be used for the ritual room
	std::string roomDescription; //Variable that stores a description of the room
	std::string roomName; //Variable that stores the name of the room
	//Need a way to indicate direction of room connections - not sure if that should be done here or in another class
	std::list<RoomClass> connectedRooms; //List of rooms that are connected to the room instance.
	std::list<std::string> RoomOptions; //list of room options in string
	std::vector<ItemClass> items; //List of items that are contained in the room.
	int itemsLength;
	Puzzle roomPuzzle;
	


public:
	RoomClass(); //Default constructor
	RoomClass(std::string description, std::string name, std::list<std::string> options, std::vector<ItemClass> itemList);
	RoomClass(std::string description, std::string name, std::list<std::string> options, std::vector<Door>& doors);//Constructor that takes name and description as input.
	RoomClass(std::string description, std::string name, std::list<std::string> options, std::vector<Door>& doors, std::vector<ItemClass> itemList); //Constructor for door and itemlist
	RoomClass(std::string description, std::string name, std::list<std::string> options, bool isRitual); // Consturctor for ritual room
	RoomClass(std::string description, std::string name, std::list<std::string> options); //Basic constructor

	RoomClass(std::string description, std::vector<Door>& doors);
	RoomClass(std::string description, bool isLockedRoom);
	std::vector <Door>& GetDoors(); //Returns the door associated with the room
	void unlockDoor(int doorIndex); 
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
	ItemClass& getRoomItemByName(std::string name); //Returns item in room by name
	std::vector<ItemClass>& getItems(); //Gets list of items in room
	void displayRoomItems(); //Display room items
	void RemoveItem(ItemClass itm); //Removes item from inventory
	const int getItemsLength(); //Returns length of items vector
	void displayAdjacentRooms(); //Displays adjacent rooms
	void setPuzzle(Puzzle puzzle);
	Puzzle getPuzzle();

	void addCandle(); // adds candle to candle count in ritual room
	int getCandleValue(); // returns value of candles in ritual room, will be important for 
	bool returnRitualStatus(); //returns whether room is tirual room or not
};

#endif