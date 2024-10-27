#include "MonsterClass.h"
#include <cstdlib>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

MonsterClass::MonsterClass()
{
	duration = 60;
	timerTriggered = false;
	stopFlag = false;
}

MonsterClass::MonsterClass(int dur)
{
	duration = dur;
	timerTriggered = false;
	stopFlag = false;
}

void MonsterClass::onTimerTriggered() //Runs when timer finishes
{
	grabFlag = true; //Setting grabFlag to true
	
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
	stop(); //Stop any previous threads
	stopFlag = false; //Reset stop flag
	timerTriggered = false; //reset trigger status
	timerThread = std::thread([this]() { //Creates thread that when it hits the end of timer, to run the onTimerTriggered member function
		std::this_thread::sleep_for(std::chrono::seconds(duration));
		if (!stopFlag) {
			timerTriggered = true;
			onTimerTriggered();
		}
	});
}

void MonsterClass::stop()
{
	stopFlag = true;
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