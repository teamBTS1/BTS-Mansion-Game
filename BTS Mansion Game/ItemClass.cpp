#include "ItemClass.h"
#include<iostream>
#include<string>

using namespace std;

/*
Item class gives provides the name and description
of the item when player picks it up and shown when player
looks in their inventory.
*/

	ItemClass::ItemClass()
	{
		name = " ";
		description = " ";
		keyID = " ";
		isConsumable = false;
		value = 0;
	}

	ItemClass::ItemClass(std::string n, std::string desc) 		//Constructor for a note
	{
		name = n;
		description = desc;
		keyID = " ";
		isConsumable = false;
		value = 0;
	}

	ItemClass::ItemClass(string n, string desc, string id, bool consumable) //Constructor for a key
	{
		name = n;
		description = desc;
		keyID = id;
		isConsumable = consumable;
		value = 0;
	}

	ItemClass::ItemClass(string n, string desc, int val, bool consumable) //Constructor for a consumable
	{
		name = n;
		description = desc;
		value = val;
		isConsumable = consumable;
		keyID = " ";
	}

	string ItemClass::getName()
	{
		return name; //Returns item name
	}

	void ItemClass::setName(string newName)
	{
		name = newName; //Sets item name
	}

	string ItemClass::getDescription()
	{
		return description; //Returns item description
	}

	void ItemClass::setDescription(string newDescription)
	{
		description = newDescription; //Sets item description
	}

	string ItemClass::getKeyID()
	{
		return keyID; //Returns key ID
	}

	void ItemClass::setKeyID(string id)
	{
		keyID = id; //Sets key ID
	}

	int ItemClass::getValue()
	{
		return value; //Returns value of item
	}

	void ItemClass::setValue(int val)
	{
		value = val; //Sets value of item
	}

	bool ItemClass::getIsConsumable()
	{
		return isConsumable; //Returns if an item is a consumable
	}

	void ItemClass::setIsConsumable(bool consumable)
	{
		isConsumable = consumable; //Sets if an item is a consumable
	}

	void ItemClass::displayItem()
	{
		cout << "Item: " << name << endl;
		cout << "Description: " << description << endl; //Displays item and description (for testing purposes, assuming UI class handles all input output)
	}
