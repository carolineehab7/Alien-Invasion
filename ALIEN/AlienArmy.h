#pragma once
#include<iostream>
#include "Units.h"
#include "Dequeue.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include"AS.h"
#include"AM.h"
#include"AD.h"
using namespace std;

class AlienArmy {

private:

	int M_ArrSize;
	LinkedQueue<AS*> AS_LIST;
	Dequeue AD_LIST; 

	LinkedQueue<int> Empty_Monst_Index;
	AM** Monsters_Arr;
	AD** ADArr;

public:
	
	AlienArmy();
	int monstersCounter;
	bool addUnit(Units* U);
	AS* pickAS();
	AM* pickAM();
	AD** pickAD();
	void printAA();
	LinkedQueue<AS*> getASList();
	Dequeue getADList();
	AM** getMonstersArr();
	int getMonstersArrSize();
	~AlienArmy();

};
