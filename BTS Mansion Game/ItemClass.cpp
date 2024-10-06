#include "ItemClass.h"
#include<iostream>
#include<string>

using namespace std;

/*
Item class gives provides the name and description
of the item when player picks it up and shown when player
looks in their inventory.
*/

class Item
{
private: 
	string name;
	string description;

public: 
	Item()
	{
		name = " ";
		description = " ";
	}

	Item(string n, string des)
	{
		name = n;
		description = des;
	}

	string getName()
	{
		return name;
	}

	void setName(string newName)
	{
		name = newName;
	}

	string getDescription()
	{
		return description;
	}

	void setDescription(string newDescription)
	{
		description = newDescription;
	}

	void displayItem()
	{
		cout << "Item: " << name << endl;
		cout << "Description: " << description << endl;
	}
};