#pragma once
#include "Puzzle.h"
#include "UserInterfaceClass.h"
#include <string>
#include <vector>
#include <iostream>
#include <thread>


class ChantPuzzle : public Puzzle
{
private:

public:
	ChantPuzzle();
	ChantPuzzle(std::string puzzleName);

	void runPuzzle();

	
};


