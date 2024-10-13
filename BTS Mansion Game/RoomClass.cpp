#include "RoomClass.h"



RoomClass::RoomClass()
{

}

RoomClass::RoomClass(std::string description, std::string name, std::list<std::string> options, std::vector<ItemClass> itemList)
{
	this->roomDescription = description;
	this->roomName = name;
	this->RoomOptions = options;
	items = itemList;
	this->itemsLength = items.size();
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

std::list<std::string> RoomClass::GetRoomOption() 
{
	return RoomOptions;
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

std::vector<ItemClass> RoomClass::getItems()
{
	return items;
}

void RoomClass::displayRoomItems()
{
	std::cout << "Items inside this room are: " << std::endl;
	for (int i = 0; i < itemsLength; i++)
	{
		std::cout << items[i].getName() << std::endl;
	}
}

void RoomClass::RemoveItem(ItemClass itm)
{

	itemsLength -= 1;
	/*
	for (int i = 0; i < itemsLength; i++)
	{
		if (items[i].getName() == itm.getName())
		{
			auto pos = items.begin() + i;
			items.erase(items.begin());

		}
	}
	*/
}

const int RoomClass::getItemsLength()
{
	return itemsLength;
}
