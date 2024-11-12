#include "MonsterClass.h"
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#pragma comment(lib, "winmm.lib")

MonsterClass::MonsterClass()
{
	duration = 60;
	timerTriggered = false;
	stopFlag = false;
}

MonsterClass::MonsterClass(int dur, GameControllerClass& myController)
{
	duration = dur;
	timerTriggered = false;
	stopFlag = false;
	currentGameController = &myController;
	timeRemaining = dur; 
}

void MonsterClass::onTimerTriggered() //Runs when timer finishes

{
	system("cls");
	if (currentGameController && currentGameController->inProtectedState()) {
		// If the player is in a protected state, skip the grab action
		return;
	}
	grabFlag = true; //Setting grabFlag to true
	

	//Play sound and display ascii art when grabbed
	
	UserInterfaceClass ui;
	ui.displayPrompt("A shadowy monster with elongated limbs grabs you, as the shadows encapsulating this monster consume you and all you can feel is its cold embrace.");
	PlaySound(TEXT("jumpscare.wav"), NULL, SND_FILENAME | SND_ASYNC);
	ui.displayPrompt(R"(
       ___,---.__          /'|`\          __,---,___
    ,-'    \`    `-.____,-'  |  `-.____,-'    //    `-.
  ,'        |           ~'\     /`~           |        `.
 /      ___//              `. ,'          ,  , \___      \
|    ,-'   `-.__   _         |        ,    __,-'   `-.    |
|   /          /\_  `   .    |    ,      _/\          \   |
\  |           \ \`-.___ \   |   / ___,-'/ /           |  /
 \  \           | `._   `\\  |  //'   _,' |           /  /
  `-.\         /'  _ `---'' , . ``---' _  `\         /,-'
     ``       /     \    ,='/ \`=.    /     \       ''
             |__   /|\_,--.,-.--,--._/|\   __|
             /  `./  \\`\ |  |  | /,//' \,'  \
           /   /     ||--+--|--+-/-|     \   \
           |   |     /'\_\_\ | /_/_/`\     |   |
            \   \__, \_     `~'     _/ .__/   /
             `-._,-'   `-._______,-'   `-._,-'
		)");


	ui.displayPrompt("You see a way out of its grasp for a brief moment, do you want to ESCAPE?");

	//can get input here and handle logic inside this function
}

void MonsterClass::start()
{

	UserInterfaceClass myUI;
	stop(); //Stop any previous threads
	stopFlag = false; //Reset stop flag
	timerTriggered = false; //reset trigger status
	timeRemaining = duration; // setting the time remaining to the total expected duration, initaliing it

	timerThread = std::thread([this]() { //Creates thread that when it hits the end of timer, to run the onTimerTriggered member function

		while (timeRemaining > 0 && !stopFlag) {

			if (currentGameController && currentGameController->inProtectedState()) //stops the timer if in protected
			{
				std::this_thread::sleep_for(std::chrono::seconds(1));
				continue;
			};


			std::this_thread::sleep_for(std::chrono::seconds(1));
			timeRemaining--; //lower the time left, keeps track while in protected state

			if (timeRemaining == 2 && !stopFlag) {
				std::cout << "The monster is approching, you must hide, hurry!" << endl; //if timer has less than 2 seconds, the user is notified to hide
			}
		}

		if (timeRemaining == 0 && !stopFlag) {
			timerTriggered = true;
			onTimerTriggered(); //trigger if time is up
		}
	});
}

void MonsterClass::stop()
{
	stopFlag = true;
	timeRemaining = duration; //when timer is reset, the duration is set equal to the time that was left
	if (timerThread.joinable())
	{
		timerThread.join();
	}
}

void MonsterClass::reset()
{
	start();
}

bool MonsterClass::isTriggered() const
{
	return timerTriggered;
}

bool MonsterClass::isGameOver() const
{
	return gameOverFlag;
}

void MonsterClass::setIsGameOver(bool state)
{
	gameOverFlag = state;
}

bool MonsterClass::isGrab() const
{
	return grabFlag;
}

void MonsterClass::join()
{
	if (timerThread.joinable())
	{
		timerThread.join();
	}
}
MonsterClass::~MonsterClass()
{
	stop();
}