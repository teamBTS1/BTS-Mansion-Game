#pragma once

#ifndef GREATERLIBRARYPUZZLE_H
#define GREATERLIBRARYPUZZLE_H

#include "Puzzle.h"
#include "ItemClass.h"
#include "PickUpItemClass.h"
#include "PlayerClass.h"
#include "UserInterfaceClass.h"
#include <string>
#include <vector>

class GreaterLibraryPuzzle : public Puzzle {
private:
	std::string answer;

public:
	GreaterLibraryPuzzle(); //Default constructor
	GreaterLibraryPuzzle(std::string ans); //Default constructor

	void runPuzzle(); //Runs puzzle
};

#endif