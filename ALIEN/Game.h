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
class RandGen;

class Game
{
private:
	EarthArmy* EA;
	AlienArmy* AA;
	RandGen* randGenPtr;
	LinkedQueue<Units*>* KilledList;
	int Time_step;
	char Mode;

public:
	Game();
	bool KilledListfunc(Units* killunit);
	void LoadFromFile();
	RandGen* getRandGenptr();
	EarthArmy* getEarthArmyptr();
	AlienArmy* getAlienArmyptr();
	void printKillList();
	void createoutfile();
	void PrintSilent();
	void PrintALL();
	void Simulation();
	int getTime();
	char getMode() const;
	~Game();
};

