#pragma once
#include<iostream>
#include "Units.h"
#include"AS.h"
#include"AM.h"
#include"AD.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include "Dequeue.h"
using namespace std;

class AlienArmy {

private:

	int M_ArrSize;
	LinkedQueue<AS*> AS_LIST;
	Dequeue AD_LIST;
	LinkedQueue<int> Empty_Monst_Index;
	AM** Monsters_Arr;
	int Mcount;

public:
	AlienArmy();
	int monstersCounter;
	AlienArmy(int M_ArrSize);
	bool addUnit(Units* U);
	AS* pickAS();
	AM* pickAM();
	AD** pickAD();
	void printAA();
	~AlienArmy();

};
