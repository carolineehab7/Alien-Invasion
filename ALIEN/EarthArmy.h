#pragma once
#include<iostream>
#include"Units.h"
#include"EG.h"
#include"ES.h"
#include"ET.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"LinkedQueue.h"
using namespace std;

class EarthArmy {

private:
	LinkedQueue<ES*> ES_LIST;
	priQueue <EG*> EG_LIST;
	ArrayStack<ET*> ET_LIST;
	ArrayStack<ES*> HL_LIST;
	priQueue <ES*> ES_Maintain;
	LinkedQueue<ET*> ET_Maintain;

public:
	
	EarthArmy();
	bool addUnit(Units* U);
	ES* pickES();
	EG* pickEG();
	ET* pickET();
	LinkedQueue<ES*> getESList();
	priQueue <EG*> getEGList();
	ArrayStack<ET*> getETList();
	void addtoES_UML(ES*);
	void addtoET_UML(ET*);
	ES* removefromES_uml();
	ET* removefromET_uml();
	void printEA();
	~EarthArmy();

};