#include "MonsterClass.h"

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
	UserInterfaceClass ui;
	ui.displayPrompt("A shadowy monster with elongated limbs grabs you, as the shadows encapsulating this monster consume you and all you can feel is its cold embrace.");
	/*
	ui.displayPrompt("You see a way out of its grasp for a brief moment, do you want to ESCAPE?");
	ui.userInput();
	if (ui.userInput() == "ESCAPE") 
	{
		ui.displayPrompt("You manage to follow the light out of the shadowy monster's grasp, returning to your previous room, knowing that if you're not quick it could easily happen again.");
	}
	else
	{
		ui.displayPrompt("DEAD");
	}
	*/
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
}

void MonsterClass::reset()
{
	start();
}

bool MonsterClass::isTriggered() const
{
	return timerTriggered;
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