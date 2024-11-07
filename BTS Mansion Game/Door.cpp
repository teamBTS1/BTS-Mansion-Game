#include "Door.h"

Door::Door()
{
	isLocked = false;
	doorKeyID = " ";
	doorName = "";
}

Door::Door(bool locked, std::string id, std::string newDescription, std::string name)
{
	isLocked = locked;
	doorKeyID = id;
	openDoorDescription = newDescription;
	doorName = name;
}

bool Door::getIsLocked()
{
	return isLocked;
}

std::string Door::getDoorName() {
	return doorName;
}


std::string Door::getDoorKeyID()
{
	return doorKeyID;
}

void Door::setDoorKeyID(std::string id)
{
	doorKeyID = id;
}

void Door::unlockDoor()
{
	isLocked = false;
}


std::string Door::returnOpenDoorDescription()
{
	return openDoorDescription;
}