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










	/*
	void printAA() {

		cout << "============== Alien Army Alive Units ==============" << endl;

		cout << AS_List.getLength() << " AS [";
		for (int i = 0; i < AS_List.getLength(); ++i) {
			AS* y;
			AS_List.peek(y);

			cout << y->getID() << ',';

			AS_List.dequeue(y);
			AS_List.enqueue(y);
		}
		cout << "]" << endl;

		/////////////////////////////////////////////////////////////////////////

		cout << AD_List.getLength() << " EG [";
		for (int i = 0; i < AD_List.getLength(); ++i) {
			AD* s;
			AD_List.peek(*s);

			cout << s->getID() << ',';

			AD_List.dequeue(*s);
			AD_List.enqueue(*s);
		}
		cout << "]" << endl;

		/////////////////////////////////////////////////////////////////////////

	}
	*/
	

