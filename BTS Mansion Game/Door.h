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
public:
	Door(); //Default constructor (unlocked door)
	Door(bool locked, std::string id); //Constructor (locked door)

	bool getIsLocked(); //Returns if door is locked

	std::string getDoorKeyID(); //Returns key id for door
	void setDoorKeyID(std::string id); //Sets key id for door

	void unlockDoor(std::list<ItemClass> inventory); //Searches whole inventory of player for corresponding key, then unlocks if has it
	//Doesn't unlock if doesn't have correct key, takes key out of inventory cause of direct reference
};

#endif

