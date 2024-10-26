#pragma once
#ifndef MONSTERCLASS_H
#define MONSTERCLASS_H

#include "UserInterfaceClass.h"
#include <string>
#include <thread> //Thread, atomic, functional, and chrono used for timer implementation
#include <atomic>
#include <functional>
#include <chrono>

class MonsterClass
{
private:
	int duration;
	//std::function<void()> callBack; //Stores a function that runs when timer is triggered
	std::atomic<bool> timerTriggered;
	std::atomic<bool> stopFlag;
	std::atomic<bool> gameOverFlag; //Checks if monster killed player and game over
	std::atomic<bool> grabFlag; //Checks if in monster grab sequence
	std::thread timerThread;

public:
	MonsterClass(); //Constructors
	MonsterClass(int duration);

	void onTimerTriggered(); //Function for callback when timer is triggered

	void start(); //Starts timer
	void stop(); //Stops timer
	void reset(); //Resets timer

	bool isTriggered() const; //Checks if timer has been triggered (hits 0)
	
	bool isGameOver() const; //Checks if game over has been triggered
	void setIsGameOver(bool state); //sets game over flag

	bool isGrab() const; //Checks if player currently grabbed by monster

	void join(); //Joins thread after timer done

	~MonsterClass();
};



#endif