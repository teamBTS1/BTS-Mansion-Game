#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H
class Puzzle
{
	/*Parent class for puzzles that can be solved by the player.
	* Included functionality should ideally only be anything that is used by all puzzles.
	* For any functionality to be used by only one puzzle, a child class that inherits from this one should be used.
	*/

protected:
	bool _isSolved;//Stores whether the puzzle has been solved

public:
	Puzzle();//Constructor
	bool isSolved();//Check whether the puzzle has been solved yet or not
	void solve();//Solve the puzzle

};

#endif