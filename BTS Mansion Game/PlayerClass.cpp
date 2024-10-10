#include "PlayerClass.h"

PlayerClass::PlayerClass()
{
	numCandles = 0;
	sanityMeter = 100;
}

PlayerClass::PlayerClass(RoomClass room)
{
	numCandles = 0;
	sanityMeter = 100;
	currentRoom = room; //Setting default values
}

int PlayerClass::getCandles()
{
	return numCandles; //Returning number of candles
}

void PlayerClass::addCandle()
{
	numCandles += 1; //Adding 1 to num of candles
}

int PlayerClass::getSanity()
{
	return sanityMeter; //Getting sanity meter
}

void PlayerClass::setSanity(int sanityValue)
{
	sanityMeter = sanityValue; //Setting sanity meter
}

RoomClass PlayerClass::getRoom()
{
	return currentRoom; //Returns current room
}

std::string PlayerClass::getRoomName()
{
	return currentRoom.GetName();
}

std::string PlayerClass::getRoomDescription()
{
	return currentRoom.GetDescription();
}

void PlayerClass::setRoom(RoomClass room)
{
	currentRoom = room; //Sets current room
}

std::vector<ItemClass>& PlayerClass::getInventory() //Returns reference to inventory for direct modification and use (Like using a key or sanity pill)
{
	return Inventory; //Returns direct reference to inventory for modification and use (adding to inventory, key, etc)
}

std::vector<ItemClass> PlayerClass::viewInventory() const
{
	return Inventory; //Returns non modifiable copy of inventory for display
}

int PlayerClass::getInventorySize() const
{
	return Inventory.size(); //Returns size of inventory
}

void PlayerClass::useItem(ItemClass item)
{
	//Functionality not complete
}

ItemClass PlayerClass::getItem(std::string n)
{ //Searches through array for specified item n, if not found returns a default unknownItem so devs can know verify through if statements if a valid item was found
	ItemClass unknownItem("Unknown", "Item not found");
	for (int i = 0; i < Inventory.size(); i++)
	{
		if (Inventory[i].getName() == n)
		{
			return Inventory[i]; //Returns copy of item for displaying in UI class
		}
		else
		{
			return unknownItem; //Returns unknown item to show item not found
		}
	}
}