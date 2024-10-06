#include "Door.h"

Door::Door()
{
	isLocked = false;
	doorKeyID = " ";
}

Door::Door(bool locked, std::string id)
{
	isLocked = locked;
	doorKeyID = id;
}

bool Door::getIsLocked()
{
	return isLocked;
}

std::string Door::getDoorKeyID()
{
	return doorKeyID;
}

void Door::setDoorKeyID(std::string id)
{
	doorKeyID = id;
}

void Door::unlockDoor(PlayerClass& player)
{
	for (int i = 0; i < player.getInventorySize(); i++)
	{
		if (player.getInventory()[i].getKeyID() == doorKeyID)
		{
			isLocked = false;
		}
	}
}