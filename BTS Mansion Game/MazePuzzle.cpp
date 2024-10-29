#include "MazePuzzle.h"

MazePuzzle::MazePuzzle()
{
	_description = " ";
	_isSolved = false;
	correctSequence = { " " };
}

MazePuzzle::MazePuzzle(std::vector<std::string> seq)
{
	_description = "Maze Puzzle";
	correctSequence = seq;
}

void MazePuzzle::runPuzzle()
{
	UserInterfaceClass ui; //ui for i/o
	std::vector<std::string> userSequence;
	
	for (int i = 0; i < correctSequence.size(); i++)
	{
		ui.displayPrompt(correctSequence.at(i)); //display each symbol in sequence
	}

	ui.displayPrompt("Enter the correct sequence of symbols...");

	for (int i = 0; i < correctSequence.size(); i++)
	{
		std::string input; 
		input = ui.userInput();
		userSequence.push_back(input);
	}

	if (correctSequence == userSequence)
	{
		_isSolved = true;
	}
	else
	{
		_isSolved = false;
	}
}