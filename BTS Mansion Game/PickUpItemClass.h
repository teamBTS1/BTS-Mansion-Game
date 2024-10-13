#pragma once
#ifndef PICKUPITEMCLASS_H
#define PICKUPITEMCLASS_H

#include "ItemClass.h"
#include "PlayerClass.h"
#include "RoomClass.h"
#include <string>


class PickUpItemClass
{
		//Only write declarations here, actual code will be in cpp file.
private:
	ItemClass itemToBePickedUp; //Item to be picked up

public:
	PickUpItemClass(); //Constructors
	PickUpItemClass(ItemClass item);

	ItemClass getItemToBePickedUp(); //Return item to be picked up
	void setItemToBePickedUp(ItemClass item); //Set item to be picked up

	void addToInventory(PlayerClass &player, RoomClass &room); //adds item to inventory using direct reference
};

#endif