#pragma once
#ifndef ROOMCLASS_H
#define ROOMCLASS_H


#include <array>
#include "Door.h"
#include "ItemClass.h"


class RoomClass
{
	//Class to represent an in-game location.
private:
	Door door;


public:
	Door getDoor();


};

#endif