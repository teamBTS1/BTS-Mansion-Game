#include "RoomClass.h"



RoomClass::RoomClass()
{
}

RoomClass::RoomClass(std::string description, std::string name, std::list<std::string> options)
{
	this->roomDescription = description;
	this->roomName = name;
	this->RoomOptions = options;
}



RoomClass::RoomClass(std::string description, std::string name, std::list<std::string> options, Door& door)
{
	this->roomDescription = description;
	this->roomName = name;
	this->RoomOptions = options;
	roomDoor = door;
}


Door RoomClass::GetDoor()
{
	return roomDoor;
}

std::list<std::string> RoomClass::GetRoomOption() 
{
	return RoomOptions; 
}

void RoomClass::setRoomOption(std::list<std::string> options)
{
	RoomOptions = options; // temporary option in place, ideally we want a function to go through the current options and replace it with a passed variable we can determine as a member variable with is the room behind the door
}

std::string RoomClass::GetDescription()
{
	return roomDescription;
}

void RoomClass::setRoomDescription(std::string newDescription)
{
	roomDescription = newDescription;
}

std::string RoomClass::GetFullDescription()
{
	return std::string();
}

std::string RoomClass::GetName()
{
	return roomName;
}

void RoomClass::unlockDoor()
{
	setRoomDescription(roomDoor.returnOpenDoorDescription()); //change description state of room
}

void RoomClass::ReplaceDescription(std::string newDescription)
{
}

void RoomClass::AmendDescription(std::string addition)
{
}


