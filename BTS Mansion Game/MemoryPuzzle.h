#pragma once

#include "Puzzle.h"
#include "UserInterfaceClass.h"
#include <string>
#include <vector>
#include <iostream>
#include <thread>


class MemoryPuzzle : public Puzzle  
{
private:

public:
	MemoryPuzzle();
	MemoryPuzzle(std::string puzzleName);

	void runPuzzle(); 

	std::string randomLetterString(int);
	bool displayLetters(std::string& sequence, UserInterfaceClass ui);
};

