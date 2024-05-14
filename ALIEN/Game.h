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
	ArrayStack<HealUnit*> HL_LIST;
	priQueue <ES*> ES_Maintain;
	LinkedQueue<ET*> ET_Maintain;
	char Mode;
	Units* unitptr;
	bool battlewin = false;

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
	char getMode(); 
	LinkedQueue<ET*>getET_UML();
	priQueue <ES*>getES_UML();
	ArrayStack<HealUnit*>getHL_LIST();
	void addtoHeal(HealUnit*);
	void addtoES_UML(ES*);
	void addtoET_UML(ET*);
	ES* removefromES_uml();
	ET* removefromET_uml();
	HealUnit* removefromHeal();
	~Game();
};

