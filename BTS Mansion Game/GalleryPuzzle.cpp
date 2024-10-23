#include "GalleryPuzzle.h"
#include "InteractClass.h"
#include "UserInterfaceClass.h"

GalleryPuzzle::GalleryPuzzle()
{
	_description = " ";
	_isSolved = false;
}

GalleryPuzzle::GalleryPuzzle(std::vector <ItemClass> ports, std::vector <ItemClass> answer)
{
	_description = "Gallery Puzzle";
	_isSolved = false;
	portraits = ports;
	answers = answer;
}

void GalleryPuzzle::runPuzzle()
{
	UserInterfaceClass ui;
	std::vector <ItemClass> userPortraits;
	std::string input;
	int answerCount = 0;
	int correctAnswerCount = 0;

	while (answerCount != 1) // 1 for now because of initial implementation
	{
		ui.displayPrompt("The portraits inside the room are: ");
		for (auto portrait : portraits) //Displaying all portraits
		{
			ui.displayPrompt(portrait.getName());
		}

		ui.displayPrompt("Choose which portrait to touch.");
		input = ui.userInput();

		for (auto portrait : portraits) //Looping to check if a valid portrait entered
		{
			if (portrait.getName() == input)
			{
				userPortraits.push_back(portrait); //Adding to user answer vector
				answerCount++; //Incrementing the amount of answers made

				//ui.displayPrompt(userPortraits[0].getName());

				if (answers.at(answerCount - 1).getName() == userPortraits.at(answerCount - 1).getName()) //Checking if portrait is correct order
				{
					correctAnswerCount++;
				}
			}
			else {
				ui.displayPrompt("That is not one of the portraits!");
			}
		}		
	}

	if (correctAnswerCount == 1) //Puzzle solved
	{
		ui.displayPrompt("You successfully solved the Storyteller's Poem!");
		_isSolved = true;
	}
	else {
		ui.displayPrompt("You failed to solve the Storyteller's Poem!");
	}
}