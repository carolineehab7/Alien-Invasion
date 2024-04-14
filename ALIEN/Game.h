#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include "EarthArmy.h"
#include "AlienArmy.h"
#include "QueueADT.h"
#include "LinkedQueue.h"
#include "RandGen.h"

using namespace std;

class Game
{
private:
	int Time_step;
	ifstream inpfile;
	EarthArmy EA;
	AlienArmy AA;
	RandGen randGenObj;
	LinkedQueue<Units*>*KilledList;
public:
	Game();
	bool KilledListfunc(Units* killunit);
	void LoadFromFile(string filename);
	RandGen* getRandGenptr();
	EarthArmy* getEarthArmyptr();
	AlienArmy* getAlienArmyptr();

	~Game();
	
	
};

