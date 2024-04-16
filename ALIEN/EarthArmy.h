#pragma once
#include<iostream>
#include"Units.h"
#include"EG.h"
#include"ES.h"
#include"ET.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"priNode.h"
using namespace std;

class EarthArmy {

private:
	LinkedQueue<ES*>* ES_LIST;
	priQueue <EG*>* EG_LIST;
	ArrayStack<ET*>* ET_LIST;

public:
	EarthArmy();
	bool addUnit(Units* U);
	ES* pickES();
	EG* pickEG();
	ET* pickET();
	void printEA();
	~EarthArmy();

};