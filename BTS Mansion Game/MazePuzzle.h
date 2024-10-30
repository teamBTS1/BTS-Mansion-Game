#pragma once

#ifndef MAZEPUZZLE_H
#define MAZEPUZZLE_H

#include "Puzzle.h"
#include "UserInterfaceClass.h"
#include <string>
#include <vector>


class MazePuzzle : public Puzzle {
private:
	std::vector <std::string> correctSequence;

public:
	MazePuzzle(); //Default constructor
	MazePuzzle(std::vector<std::string> seq);

	void runPuzzle(); //Runs puzzle
};

#endif#pragma once
