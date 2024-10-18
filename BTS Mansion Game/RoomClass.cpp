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

RoomClass::RoomClass(std::string description, std::string name, std::list<std::string> options, Door& door, std::vector<ItemClass> itemList)
{
	this->roomDescription = description;
	this->roomName = name;
	this->RoomOptions = options;
	roomDoor = door;
	items = itemList;
	this->itemsLength = items.size();
}


RoomClass::RoomClass(std::string description, std::string name, std::list<std::string> options, std::vector<ItemClass> itemList)
{
	this->roomDescription = description;
	this->roomName = name;
	this->RoomOptions = options;
	items = itemList;
	this->itemsLength = items.size();
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

std::vector<ItemClass>& RoomClass::getItems()
{
	return items;
}

ItemClass& RoomClass::getRoomItemByName(std::string name)
{
	for (int i = 0; i < itemsLength; i++)
	{
		
		if (name == items[i].getName())
		{
			return items[i];
		}

	}
	ItemClass unknownItem;
	return unknownItem;
}

void RoomClass::displayRoomItems()
{

	std::cout << "-----------" << endl;
	std::cout << "Items inside this room are: " << std::endl;
	std::cout << endl;
	for (int i = 0; i < itemsLength; i++)
	{
		std::cout << items[i].getName() << std::endl;
	}
	std::cout << endl;
}


void RoomClass::RemoveItem(ItemClass itm)
{
	for (auto it = items.begin(); it != items.end(); it++)
	{
		if (it->getName() == itm.getName())
		{
			items.erase(it);
			itemsLength--;
			return;
		}
	}
}

const int RoomClass::getItemsLength()
{
	return itemsLength;
}

void RoomClass::displayAdjacentRooms()
{
	std::cout << "Rooms you can go to: " << std::endl;
	std::cout << endl;
	for (const std::string& room : RoomOptions)
	{
		std::cout << room << std::endl;
	}
	std::cout << endl;
}