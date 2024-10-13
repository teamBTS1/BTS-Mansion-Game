#include "PickUpItemClass.h"

PickUpItemClass::PickUpItemClass()
{
	//Default constructor
}

PickUpItemClass::PickUpItemClass(ItemClass item)
{
	itemToBePickedUp = item; //Constructor
}

ItemClass PickUpItemClass::getItemToBePickedUp()
{
	return itemToBePickedUp; //Returns item to be picked up
}

void PickUpItemClass::setItemToBePickedUp(ItemClass item)
{
	itemToBePickedUp = item; //Sets item to be picked up
}

void PickUpItemClass::addToInventory(PlayerClass& player, RoomClass& room)
{
	player.getInventory().push_back(itemToBePickedUp); //Getting player inventory direct reference and adding inventory item to vector array
	room.RemoveItem(itemToBePickedUp);
}