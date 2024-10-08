#include "RoomClass.h"



RoomClass::RoomClass()
{
}

RoomClass::RoomClass(std::string description)
{
}



RoomClass::RoomClass(std::string description, Door &door)
{
}



RoomClass::RoomClass(std::string description, bool isLockedRoom)
{
}


Door RoomClass::GetDoor()
{
	return roomDoor;
}

std::string RoomClass::GetDescription()
{
	return roomDescription;
}

std::string RoomClass::GetFullDescription()
{
	return std::string();
}

std::string RoomClass::GetName()
{
	return roomName;
}

void RoomClass::ReplaceDescription(std::string newDescription)
{
}

void RoomClass::AmendDescription(std::string addition)
{
}


