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
	AD** ADArr;
public:
	AlienArmy();
	int monstersCounter; // Number of AM in the Array
	bool addUnit(Units* U);
	AS* pickAS();
	AM* pickAM();
	AD** pickAD();
	LinkedQueue<AS*> getASList();
	Dequeue getADList();
	AM** getMonstersArr();
	int getMonstersArrSize();
	void printAA();
	void AttackEA();
	~AlienArmy();
};
