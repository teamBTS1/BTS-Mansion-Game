#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../BTS Mansion Game/PlayerClass.cpp"
#include "../BTS Mansion Game/ItemClass.cpp"
#include "../BTS Mansion Game/RoomClass.cpp"
#include "../BTS Mansion Game/Door.cpp"
#include "../BTS Mansion Game/Puzzle.cpp"




/**
 * 	Player class automated testing (sample to get started)
 *    methods manage primarily the player's inventory and location
 *      with a nod to players sanity
 *  This test section will focus on a few of the item management methods
 * 
 * Methods (not a complete list)
 * 	PlayerClass();
 * 	void addItem(ItemClass item); //gives user item in their inventory
 *  std::vector<ItemClass>& getInventory(); //Returns whole array of direct reference to inventory  
 *      (Question - why would you give the ability to mutate this?)
 *  std::vector<ItemClass> viewInventory() const; //Returns a copy of inventory array for displaying in UI class
 *  int getInventorySize() const; //Returns size of inventory
 *  void useItem(ItemClass item); //Check if consumable, then if true, remove from inventory and display effect of item
 *  void useItem(std::string itemName); //Overload of useItem that takes the name of an item as a string rather than passing in an item object
 *  ItemClass getItem(std::string n); //Returns copy of specific item from inventory for inspection displayed by UI class
 *  void removeItem(std::string n); //removes item from inventory
 *  bool inInventory(std::string name) const;  //returns true or false of an items existence in inventory
 * 
 * 	ItemClass(); //Constructors
 *  ItemClass(std::string n, std::string desc); //Constructor for an unknownItem (dev use)
 * 	std::string getName(); //Return item name
 */

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BTSMansionGameAutomatedTest
{
	TEST_CLASS(BTSMansionGameAutomatedTest)
	{
	public:
		
		TEST_METHOD(BTS_Room_Test)
		{
			Logger::WriteMessage("Create a room and verify their names, descriptions, and ritual room status\n");

			std::list<std::string> opts = { "HALLWAY" }; //Room options
			RoomClass bathroom("Stinky bathroom", "BATHROOM", {"HALLWAY"}, false);
			


			Assert::IsTrue(bathroom.GetName() == "BATHROOM", L"Returned wrong name for BATHROOM!"); //Verifying name, desc, ritual room status
			Assert::IsTrue(bathroom.GetDescription() == "Stinky bathroom", L"Returned wrong name for description!");
			Assert::IsTrue(bathroom.GetRoomOption() == opts, L"Returned wrong list of room options!");
			Assert::IsTrue(bathroom.returnRitualStatus() == false, L"Should return false not true!");

			std::string st;
			if (bathroom.returnRitualStatus() == false) { st = "false"; }
			else { st = "true"; }

			std::string message = "Room Name: " + bathroom.GetName() + "\tDescriptions: " + bathroom.GetDescription() + "\tRitual Room Status: " + st + "\n";
			Logger::WriteMessage(message.c_str());
			auto it = opts.begin();
			std::string msg = "Room options: " + *it;
			Logger::WriteMessage(msg.c_str());
		}
		/*
		TEST_METHOD(BTS_Interact_Test)
		{
			Logger::WriteMessage("Creating a few interactions\n");
			InteractClass statue("Statue", "The statue glows");

			Assert::IsTrue(statue.getIsPuzzle() == false, L"Statue should not be a puzzle!");
		}
		*/
		TEST_METHOD(BTS_PlayerConstructor_Test)
		{
			Logger::WriteMessage("Hello from BTS_PlayerConstructor_Test\n");
		}

		TEST_METHOD(BTS_ItemBasicTests)
		{
			Logger::WriteMessage("Create a few items and verify they are created\n");
			ItemClass blank();  // item name & description should be blank
			ItemClass cat("cat", "hairy thing");
			ItemClass dog("dog", "furry thing");
			ItemClass secondDog("dog", "the second furry thing");
			std::string message = "item Names ... cat: " + cat.getName() + "\tdog: " + dog.getName() + "\tseconddog: " + secondDog.getName() + "\n";
			Logger::WriteMessage(message.c_str());
			Assert::IsTrue(cat.getName() == "cat", L"Returned the wrong name for the cat!");
			Assert::IsTrue(dog.getName() == "dog", L"Returned the wrong name for the cat!");
			Assert::IsTrue(secondDog.getName() == "dog", L"Returned the wrong name for the cat!");  // verify can create two items with same name

			// now that we created the items - add them to the player inventory
			Logger::WriteMessage("Add three animals to player inventory\n");
			PlayerClass player;
			player.addItem(cat);
			player.addItem(dog);
			player.addItem(secondDog);

			Logger::WriteMessage("Verify three items are in the player's inventory\n");
			Assert::IsTrue(player.getInventorySize() == 3);

			Logger::WriteMessage("Verify three items are in the player's inventory\n");
	
			message = "Player inventory: " + catItemNames(player.getInventory());
			Logger::WriteMessage(message.c_str());

			Logger::WriteMessage("Verify cat and dog are in the inventory, but a fox is not\n");
			Assert::IsTrue(player.inInventory("cat"), L"cat was not found in the player's inventory!");
			Assert::IsTrue(player.inInventory("dog"), L"dog was not found in the player's inventory!");
			Assert::IsFalse(player.inInventory("fox"), L"a fox was found lurking in the player's inventory!");

		}

		// Edge case - try to use an item that doesn't exist - initially with an empty inventory, than with a couple of items in it
		TEST_METHOD(BTS_UsingNonExistentItemsTest)
		{
			Logger::WriteMessage("Try to use an item with nothing in the player inventory\n");
			PlayerClass player;
			std::string message = "Player inventory: " + catItemNames(player.getInventory());
			Logger::WriteMessage(message.c_str());
			// first verify no fox exists in the inventory, also checking that inInventory works with an empty vector
			Assert::IsFalse(player.inInventory("fox"), L"a fox was found lurking in the player's inventory!");
			player.useItem("fox");  // then try to use the fox

			Logger::WriteMessage("Create a few items and verify they are created\n");
			ItemClass cat("1", "the first whole number");
			ItemClass dog("2", "the second whole number");
			ItemClass secondDog("-3", "negative is good too");
			ItemClass garbage("x3Zabc19hut000", "random combo of stuff");
			player.addItem(garbage);
			player.addItem(secondDog);
			player.addItem(dog);
			player.addItem(cat);
			message = "Player inventory: " + catItemNames(player.getInventory());
			Logger::WriteMessage(message.c_str());
		}

		// helper function to concatentate items in the players inventory
		std::string catItemNames(vector<ItemClass> itemList) {
			std::string catString = "+";
			for (int iterator = 0; iterator < itemList.size(); iterator++) {
				catString = catString + itemList[iterator].getName() + " ";
			}
			catString = catString += "\n";
			return catString;
		}
	};
}
