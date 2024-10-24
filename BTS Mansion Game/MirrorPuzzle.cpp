#include "MirrorPuzzle.h"

MirrorPuzzle::MirrorPuzzle()
{
	_description = "Mirror Puzzle";
	_isSolved = false;
}

MirrorPuzzle::MirrorPuzzle(std::vector <std::string> correctAns)
{
	_description = "Mirror Puzzle";
	_isSolved = false;
	correctAnswers = correctAns;
}

void MirrorPuzzle::runPuzzle()
{
	UserInterfaceClass ui;
	for (int i = 0; i < 3; i++) //Needs 3 differences, so 3 iterations
	{
		ui.displayPrompt("Enter word: ");
		answers.push_back(ui.userInput());
	}

	if (answers == correctAnswers)
	{
		_isSolved = true;
	}
	else
	{
		
	}
	
	for (int i = 0; i < 3; i++)
	{
		answers.pop_back(); //Resetting vector
	}
}