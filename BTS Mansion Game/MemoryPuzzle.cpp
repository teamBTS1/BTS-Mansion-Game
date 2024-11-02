#include "MemoryPuzzle.h"

MemoryPuzzle::MemoryPuzzle() {
	_description = " ";
	_isSolved = false;
}

MemoryPuzzle::MemoryPuzzle(std::string puzzleName) {
	_description = puzzleName;
	_isSolved = false;
}




void MemoryPuzzle::runPuzzle() {

	UserInterfaceClass ui; //Creating ui for i/o
	std::string input; //Input from user

	int startingLength = 2; 
	int finalLength = 3;
	bool toContinue = true;

	ui.displayPrompt("You place your hand on the tank, they are testing your memory, you must recite the memories that they tell you");

	for (int i = startingLength; i <= finalLength && toContinue; i++) {
		std::string sequence = randomLetterString(i); 

		toContinue = displayLetters(sequence,ui);


	}

	if (toContinue) {
		_isSolved = true; 
	}
	else {

	}

}

std::string MemoryPuzzle::randomLetterString(int length)
{
	std::string sequence;
	srand(static_cast<unsigned>(time(0)));
	for (int i = 0; i <= length; i++) {
		char letter = 'A' + rand() % 26;
		sequence += letter; 
	}

	return sequence; 
}

bool MemoryPuzzle::displayLetters(std::string& sequence, UserInterfaceClass ui) {
	std::string input;

	std::this_thread::sleep_for(std::chrono::milliseconds(800));

	for (int i = 0; i < sequence.length(); i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
		std::cout << sequence[i] << " "; 
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	system("cls");

	ui.displayPrompt("Recite the memory");
	input = ui.userInput();

	if (input == sequence) {
		ui.displayPrompt("The memories react");  
	}
	else {
		ui.displayPrompt("eeeeeeeThe memories stop reacting");
		return false;
	}



}