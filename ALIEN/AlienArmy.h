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
	LinkedQueue<AS*> AS_List;
	Dequeue AD_List;
	LinkedQueue<int> Empty_Monst_Index;
	AM** Monsters_Arr;

public:

	AlienArmy(int M_ArrSize) {
		Monsters_Arr = new AM * [M_ArrSize];
		for (int i = 0; i < M_ArrSize; ++i) {
			Monsters_Arr[i] = NULL;
			Empty_Monst_Index.enqueue(i);
		}
	}

	bool addUnit(Units* U) {

		if (U->getType() == "AS")
			return AS_List.enqueue(dynamic_cast<AS*>(U));

		else if (U->getType() == "AD")
			return AD_List.frontenqueue(*dynamic_cast<AD*>(U));

		else if (U->getType() == "AM") {

			if (Empty_Monst_Index.isEmpty())
				return false;
			int j;
			Empty_Monst_Index.peek(j);
			Empty_Monst_Index.dequeue(j);
			Monsters_Arr[j] = dynamic_cast<AM*>(U);
			return true;
		}
		else
			return false;

	}

	////////////////////////////////////////////////////////////////////////

	void printAM() {

		for (int i = 0; i < M_ArrSize; ++i) {
			cout<<Monsters_Arr[i]->getID() << " ";
		}

	}

	////////////////////////////////////////////////////////////////////////
	


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
	

