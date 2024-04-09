#pragma once
#include <iostream>
#include "EarthArmy.h"
#icnlude "AlienArmy.h"
#include "QueueADT.h"

using namespace std;

class Game
{
private:
	EarthArmy EA;
	AlienArmy AA;
public:
	Game();
	QueueADT killedlist();
};

