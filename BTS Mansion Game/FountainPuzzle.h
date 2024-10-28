#pragma once

#ifndef FOUNTAINPUZZLE_H
#define FOUNTAINPUZZLE_H

#include "Puzzle.h"
#include "UserInterfaceClass.h"
#include <string>
#include <vector>


class FountainPuzzle : public Puzzle {
private:
	std::string answer1;
	std::string answer2;
	std::string answer3;
	std::string answer4;

public:
	FountainPuzzle(); //Default constructor
	FountainPuzzle(std::string ans1, std::string ans2, std::string ans3, std::string ans4);

	void runPuzzle(); //Runs puzzle
};

#endif