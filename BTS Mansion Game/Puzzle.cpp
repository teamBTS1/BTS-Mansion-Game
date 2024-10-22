#include "Puzzle.h"

Puzzle::Puzzle()
{
	_isSolved = false;
}

bool Puzzle::isSolved()
{
	return _isSolved;
}

void Puzzle::solve()
{
	if (!_isSolved)
	{
		_isSolved = true;
	}
	else
	{
		/*Ideally this part of the method should never be entered.
		* We might want to implement some sort of error handling, like throwing an exception, but that might not be necessary right now.
		*/
	}
}
