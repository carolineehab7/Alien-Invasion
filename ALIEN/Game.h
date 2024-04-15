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
	EarthArmy* EA;
	AlienArmy* AA;
	RandGen* randGenPtr;
	LinkedQueue<Units*>* KilledList;
public:
	Game();
	bool KilledListfunc(Units* killunit);
	void LoadFromFile();
	RandGen* getRandGenptr();
	EarthArmy* getEarthArmyptr();
	AlienArmy* getAlienArmyptr();
	void TestCode();

	~Game();


};

