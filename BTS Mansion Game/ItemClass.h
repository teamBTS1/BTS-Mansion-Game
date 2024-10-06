#pragma once
#ifndef ITEMCLASS_H
#define ITEMCLASS_H

#include <string>

class ItemClass
{
	
	//Only write declarations here, actual code will be in cpp file.
private:
	std::string name; //Stores item name
	std::string description; //Stores description of the item
	std::string keyID; //Stores ID of key items
	int value; //Value of any consumable (sanity pills heal amount)
	bool isConsumable; //Tracks whether item can be consumed or not

public:
	ItemClass(); //Constructors
	ItemClass(std::string n, std::string desc); //Constructor for a note
	ItemClass(std::string n, std::string desc, std::string id, bool consumable); //Constructor for a key
	ItemClass(std::string n, std::string desc, int val, bool consumable); //Constructor for a consumable

	std::string getName(); //Return item name
	void setName(std::string newName); //Sets item to a new name

	std::string getDescription(); //Return item description
	void setDescription(std::string newDescription); //Sets item description

	std::string getKeyID(); //Returns key ID
	void setKeyID(std::string id); //Sets key ID

	int getValue(); //Returns item value
	void setValue(int val); //Sets value of item
	
	bool getIsConsumable(); //Returns true/false if consumable or not
	void setIsConsumable(bool consumable); //Sets isConsumable to T/F

	void displayItem(); //Displays item and description
};

#endif