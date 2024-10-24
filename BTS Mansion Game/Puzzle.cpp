#include "Puzzle.h"

Puzzle::Puzzle()
{
	_reward = nullptr;
	_description = "No description.";
	_isSolved = false;
}

Puzzle::Puzzle(std::string description)
{
	_reward = nullptr;
	_description = description;
	_isSolved = false;
}

Puzzle::Puzzle(ItemClass *reward)
{
	_reward = reward;
	_isSolved = false;
	
}

Puzzle::Puzzle(ItemClass *reward, std::string description)
{
	*_reward = *reward;
	_description = description;
	_isSolved = false;
	
}

std::string Puzzle::getDescription()
{
	return _description;
}

ItemClass Puzzle::getReward()
{
	return _reward;
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

void Puzzle::solve(std::vector<ItemClass>* inventory)
{
	if (!_isSolved)
	{
		_isSolved = true;
		if (_reward != nullptr)
		{
			inventory->push_back(*_reward);
		}
	}
	else
	{
		/*Ideally this part of the method should never be entered.
		* We might want to implement some sort of error handling, like throwing an exception, but that might not be necessary right now.
		*/
	}
}

