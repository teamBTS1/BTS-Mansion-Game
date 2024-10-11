#pragma once
#ifndef DOOR_H
#define DOOR_H


//#include "PlayerClass.h"
#include <string>
#include <list>
#include "ItemClass.h"

class Door
{
	
private:
	bool isLocked; //Holds whether the door is unlocked or locked
	std::string doorKeyID; //Key id for door, key that unlocks door will have same key id in item class
	std::string openDoorDescription;
public:
	Door(); //Default constructor (unlocked door)
	Door(bool locked, std::string id, std::string newDescription); //Constructor (locked door), takes in param of new description of room after the door is unlocked

	bool getIsLocked(); //Returns if door is locked

	std::string getDoorKeyID(); //Returns key id for door
	void setDoorKeyID(std::string id); //Sets key id for door

	void unlockDoor(std::list<ItemClass> inventory); //Searches whole inventory of player for corresponding key, then unlocks if has it
	//Doesn't unlock if doesn't have correct key, takes key out of inventory cause of direct reference

	std::string returnOpenDoorDescription(); // takes in string of door description that is open that replaces description of room to one when dooor is unlocked
};

#endif

