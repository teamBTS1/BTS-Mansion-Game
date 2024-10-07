#include "RoomClass.h"



RoomClass::RoomClass()
{
}

RoomClass::RoomClass(std::string description)
{
}

RoomClass::RoomClass(std::string description, Door door, RoomClass rooms[], ItemClass items[])
{
	
}

Door RoomClass::GetDoor()
{
	return roomDoor;
}

std::string RoomClass::GetDescription()
{
	return std::string();
}

std::string RoomClass::GetFullDescription()
{
	return std::string();
}

std::string RoomClass::GetName()
{
	return std::string();
}

void RoomClass::ReplaceDescription(std::string newDescription)
{
}

void RoomClass::AmendDescription(std::string addition)
{
}
