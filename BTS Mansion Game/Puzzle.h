#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H

#include "ItemClass.h"
#include <string>

class Puzzle
{
	/*Parent class for puzzles that can be solved by the player.
	* Included functionality should ideally only be anything that is used by all puzzles.
	* For any functionality to be used by only one puzzle, a child class that inherits from this one should be used.
	*/

protected:
	bool _isSolved;//Stores whether the puzzle has been solved
	ItemClass _reward;//Item reward for completing puzzle
	std::string _description;//String for storing puzzle description


public:
	Puzzle();//Base constructor
	Puzzle(std::string descrpition);//Constructor that takes puzzle description as an argument
	Puzzle(ItemClass reward);//Constructor used when puzzle rewards an item and has no description
	Puzzle(ItemClass reward, std::string description);//Constructor that takes puzzle description and item reward as arguments
	std::string getDescription();//Returns description of the puzzle
	bool isSolved();//Check whether the puzzle has been solved yet or not
	void solve();//Solve the puzzle

};

#endif