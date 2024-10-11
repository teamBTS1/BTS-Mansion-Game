#include "Door.h"

Door::Door()
{
	isLocked = false;
	doorKeyID = " ";
}

Door::Door(bool locked, std::string id, std::string newDescription)
{
	isLocked = locked;
	doorKeyID = id;
	openDoorDescription = newDescription;
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

void Door::unlockDoor(std::list<ItemClass> inventory)
{
	for (auto item : inventory)
	{
		if (item.getKeyID() == doorKeyID)
			isLocked = false;
	}
}


std::string Door::returnOpenDoorDescription()
{
	return openDoorDescription;
}