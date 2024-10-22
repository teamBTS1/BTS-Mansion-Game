#include "Puzzle.h"

Puzzle::Puzzle()
{
	

}

Puzzle::Puzzle(std::string description)
{
	
	
}

Puzzle::Puzzle(ItemClass reward)
{
	
}

Puzzle::Puzzle(ItemClass reward, std::string description)
{
	_reward = reward;
	_description = description;
	_isSolved = false;
}

std::string Puzzle::getDescription()
{
	return _description;
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
