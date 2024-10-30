#include "RoomClass.h"
#include <sstream>



RoomClass::RoomClass()
{

}

RoomClass::RoomClass(std::string description, std::string name, std::list<std::string> options)
{
	this->hasPuzzle = false;
	this->roomDescription = description;
	this->roomName = name;
	this->RoomOptions = options;
}

RoomClass::RoomClass(std::string description, std::string name, std::list<std::string> options, std::vector<Door>& doors)
{
	this->hasPuzzle = false;
	this->roomDescription = description;
	this->roomName = name;
	this->RoomOptions = options;
	roomDoors = doors;
}

RoomClass::RoomClass(std::string description, std::string name, std::list<std::string> options, std::vector<Door>& doors, std::vector<ItemClass> itemList)
{
	this->hasPuzzle = false;
	this->roomDescription = description;
	this->roomName = name;
	this->RoomOptions = options;
	roomDoors = doors;
	items = itemList;
	this->itemsLength = items.size();
}


RoomClass::RoomClass(std::string description, std::string name, std::list<std::string> options, std::vector<ItemClass> itemList)
{
	this->hasPuzzle = false;
	this->roomDescription = description;
	this->roomName = name;
	this->RoomOptions = options;
	items = itemList;
	this->itemsLength = items.size();
}


RoomClass::RoomClass(std::string description, std::string name, std::list<std::string> options, bool ritual)
{
	/*this will default to true in the declaration, we just need another constructor so we can set this rooms status to ritual
	*/
	this->hasPuzzle = false;
	this->roomDescription = description;
	this->roomName = name;
	this->RoomOptions = options;
	this->isRitual = ritual;
	this->isRitual = false; //default value of room, will be modified in ritual room constuctor
	this->candles = 0; // default value for candles is 0

}

int RoomClass::getCandleValue()
{
	return candles;
}


void RoomClass::addCandle()
{
	this->candles += 1;
}

bool RoomClass::returnRitualStatus()
{
	return isRitual;
}

std::vector<Door>& RoomClass::GetDoors()
{
	return roomDoors;
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

void RoomClass::unlockDoor(int doorIndex)
{
	if (doorIndex >= 0 && doorIndex < roomDoors.size() && roomDoors[doorIndex].getIsLocked()) {
		roomDoors[doorIndex].unlockDoor(); 
		setRoomDescription(roomDoors[doorIndex].returnOpenDoorDescription());
	}
}

void RoomClass::ReplaceDescription(std::string newDescription)
{
}

std::string preventCutoff(const std::string& text)
{
	std::istringstream words(text);
	std::string word;
	std::string wrappedText;
	
	int currentWidth = 0; 

	while (words >> word) {
		if (currentWidth + word.length() > 100) {
			wrappedText += "\n"; 
			currentWidth = 0;
		}
		wrappedText += word + " ";
		currentWidth += word.length() + 1;
	}
	return wrappedText; 
}

std::string RoomClass::AmendDescription()
{
	std::string returnMeString = this->roomDescription; //string to be returned as "full" description

	for (int i = 0; i < itemsLength; i++)
	{
		/* First for loop to iterate through all item descriptions to add to string
		*/
		if (itemsLength == 0) {
			break;
		}
		if (i == 0){
			returnMeString += " This room contains " + items[i].getDescription();
		}
		else if (i != itemsLength - 1) {
			returnMeString += ", " + items[i].getDescription();
		}
		else {
			returnMeString += " and " + items[i].getDescription() + ".";
		}
	
	}

	auto i = 0;
	for (const std::string& room : RoomOptions)
	{
		/* Second for loop to iterate through all item descriptions to add to string
		*/
		if (RoomOptions.size() == 0) {
			break;
		}
		if (RoomOptions.size() == 1) {
			returnMeString += " Adjacent to these rooms are " + room + ". ";
			break;
		}
		if (i == 0) {
			returnMeString += " Adjacent to these rooms are " + room + " ";
		}
		else if (i != RoomOptions.size()-1) {
			returnMeString += ", " + room ;
		}
		else {
			returnMeString += " and " + room + ". ";
		}
		i += 1;

	}
	return preventCutoff(returnMeString);

	/*
	std::string puzzleDesc = roomPuzzle.getDescription();
	if (puzzleDesc.size() != 0) {
		returnMeString += "Curiously, a " + this->roomPuzzle.getDescription() + " seems to join you in the room";
	}*/ //what to do foor puzzles? They get passed in as items as opposed to being a member variable of the room

	

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

void RoomClass::AddItem(ItemClass itm)			//Add an item into the room
{
	items.push_back(itm);
	itemsLength++;
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

void RoomClass::setPuzzle(Puzzle puzzle)
{
	roomPuzzle = puzzle;
	hasPuzzle = true;
}

Puzzle RoomClass::getPuzzle()
{
	return roomPuzzle;
}
