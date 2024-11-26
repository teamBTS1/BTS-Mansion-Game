#define NOMINMAX
#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "../BTS Mansion Game/PlayerClass.cpp"
#include "../BTS Mansion Game/ItemClass.cpp"
#include "../BTS Mansion Game/RoomClass.cpp"
#include "../BTS Mansion Game/Door.cpp"
#include "../BTS Mansion Game/Puzzle.cpp"


#undef max
#undef min





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
		TEST_METHOD(BTS_RoomNav)
		{
			Logger::WriteMessage("Test basic navigation between unlocked rooms");

			std::unordered_map<std::string, RoomClass> rooms; //hashmap for all rooms
			rooms["FOYER"] = RoomClass("you are in the foyer","FOYER",std::list<std::string>{"LOUNGE"});//foyer declaration
			rooms["LOUNGE"] = RoomClass("you are in the lounge","LOUNGE",std::list<std::string>{"FOYER"}); //loounge declaration
			PlayerClass player;

			player.setRoom(rooms["FOYER"]);//setting room to foyer


			// Start in Foyer
			Assert::AreEqual(std::string("FOYER"), player.getRoomName(), L"Player should start in Foyer"); //checking if the room is foyer when it should be foyer

			// Move to Lounge
			player.setRoom(rooms["LOUNGE"]);//setting room to lounge
			Assert::AreEqual(std::string("LOUNGE"), player.getRoomName(), L"Player should now be in Lounge"); //checking if room is lounged when it should be lounge
		}
		

		TEST_METHOD(BTS_SanityPillTest) {

			std::unordered_map<std::string, RoomClass> rooms; //hashmap for all rooms
			rooms["FOYER"] = RoomClass("you are in the foyer", "FOYER", std::list<std::string>{"LOUNGE"});//foyer declaration

			//declare player
			PlayerClass player;
			player.setRoom(rooms["FOYER"]);
			// Initial sanity
			player.setSanity(50);  
			//creating and using pills
			ItemClass sanityPill("BOTTLE OF PILLS", "A sanity pill.", 30, true, true);
			player.addItem(sanityPill);

			Logger::WriteMessage("Testing if sanity pills properly increase sanity by 30");

			std::vector<ItemClass> myInventory = player.getInventory(); 
			int inventorySize = player.getInventorySize();

			
			if (myInventory[0].getName() == "BOTTLE OF PILLS")
				{
					player.setSanity(std::max(0, std::min(100, player.getSanity() + myInventory[0].getValue())));
					player.useItem("BOTTLE OF PILLS");
				}

			

			//ensuring that sanity does increase after using sanity pills
			Assert::AreEqual(80, player.getSanity(), L"Sanity should increase by 30");

			//sanity pills are gone after use 
			Assert::IsFalse(player.inInventory("BOTTLE OF PILLS"), L"Sanity pill should be removed from inventory");

		}

		TEST_METHOD(BTS_UnlockDoor) {
			Logger::WriteMessage("Test that key unlocks door");
			// Create locked door
			Door lockedDoor(true, "RUSTYKEY", "A door blocks the path", "OLDDOOR");
			// Create key
			ItemClass RustyKey("Rusty Key", "A Key", "RUSTYKEY", true, true);
			// Create a player and add the key to their inventory
			PlayerClass player;
			player.addItem(RustyKey);

			// Verify the door is locked at first
			Assert::IsTrue(lockedDoor.getIsLocked(), L"The door should be locked initially.");

			// Use the key 
			if (player.inInventory("Rusty Key")) {
				std::string keyId = player.searchForKey(lockedDoor.getDoorKeyID());
				if (keyId == lockedDoor.getDoorKeyID()) {
					lockedDoor.unlockDoor();
					player.useItem("Rusty Key");
				}
			}

			//verify key is gone and door is open
			Assert::IsFalse(lockedDoor.getIsLocked(), L"The door should be unlocked after using the key.");
			Assert::IsFalse(player.inInventory("Rusty Key"), L"The key should be removed from the inventory after use.");
		}

		TEST_METHOD(BTS_RemoveItemsFromRoom) {
			Logger::WriteMessage("Removing an item from a room.");

			// Create items
			ItemClass Book("BOOK", "An old book");
			ItemClass Key("KEY", "A rusty key");
			ItemClass Pills("PILLS", "Some Pills");

			// Create room with items
			std::vector<ItemClass> initialItems = { Book, Key, Pills };
			std::vector<Door> Doors = {};

			std::unordered_map<std::string, RoomClass> rooms; 
	
			rooms["FOYER"] = RoomClass("You enter the foyer \n", "FOYER", std::list<std::string>{"LOUNGE"}, Doors, initialItems); //declare room

			// Verify initial items
			Assert::IsTrue(3 == rooms["FOYER"].getItemsLength(), L"Room should initially have 3 items.");
			std::vector<ItemClass>& items = rooms["FOYER"].getItems();
			Assert::IsTrue(items[0].getName() == "BOOK", L"Book in room");
			Assert::IsTrue(items[1].getName() == "KEY", L"Key in room");
			Assert::IsTrue(items[2].getName() == "PILLS", L"Pills in room");

			// Remove the book
			rooms["FOYER"].RemoveItem(Book);

			// Make sure there is one less item
			Assert::IsTrue(2 == rooms["FOYER"].getItemsLength(), L"Room should have 2 items after removal.");
			Assert::IsTrue(items[0].getName() == "KEY", L"Key should still be in the room.");
			Assert::IsTrue(items[1].getName() == "PILLS", L"Pills should still be in the room.");
		}


		TEST_METHOD(BTS_AdjacentRoomsTest) {
			Logger::WriteMessage("Testing adjacent room options");

			// Create a RoomClass instance
			std::list<std::string> initialOptions = { "KITCHEN", "HALLWAY" };
			RoomClass Library("A cozy library", "Living Room", initialOptions);

			// Verify initial room options
			std::list<std::string> retrievedOptions = Library.GetRoomOption();
			Assert::IsTrue(2 == retrievedOptions.size(), L"Initial room options count should be 2.");


			Assert::IsTrue(std::find(retrievedOptions.begin(), retrievedOptions.end(), "KITCHEN") != retrievedOptions.end(), L"Kitchen should be an option.");
			Assert::IsTrue(std::find(retrievedOptions.begin(), retrievedOptions.end(), "HALLWAY") != retrievedOptions.end(), L"Hallway should be an option.");
			Assert::IsFalse(std::find(retrievedOptions.begin(), retrievedOptions.end(), "FOYER") != retrievedOptions.end(), L"Foyer should not be an option.");

			// Add a new room option
			std::list<std::string> updatedOptions = retrievedOptions;
			updatedOptions.push_back("BEDROOM");
			Library.setRoomOption(updatedOptions);

			// Verify updated room options
			retrievedOptions = Library.GetRoomOption();
			Assert::IsTrue(3 == retrievedOptions.size(), L"Room options count should be 3 after adding a new option.");
			Assert::IsTrue(std::find(retrievedOptions.begin(), retrievedOptions.end(), "BEDROOM") != retrievedOptions.end(), L"Bedroom should be an option.");
		}

	};
}
