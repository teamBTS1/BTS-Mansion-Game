#include "GreaterLibraryPuzzle.h"

GreaterLibraryPuzzle::GreaterLibraryPuzzle()
{
	_description = " ";
	_isSolved = false;
	answer = { " " };
}

GreaterLibraryPuzzle::GreaterLibraryPuzzle(std::string solution)
{
	_description = "Greater Library Puzzle";
	_isSolved = false;
	answer = solution;
}

void GreaterLibraryPuzzle::runPuzzle()
{
	UserInterfaceClass ui; //To handle i/o
	std::string input; //input from user

	ui.displayPrompt("Enter the combination: ");
	input = ui.userInput();

	if (input == answer)
	{
		ui.displayPrompt("You input the correct word, finding a key inside which you grab before seeing a poison dart ready to fire at you which you narrowly dodge. You obtained the STUDY KEY!");
		_isSolved = true; //Puzzle is solved
	}
	else
	{
		ui.displayPrompt("That word doesn't seem to unlock the lock.");
		//Puzzle is not solved
	}
}