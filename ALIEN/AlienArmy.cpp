#include<iostream>
#include"AlienArmy.h"
#include "Units.h"
#include"AS.h"
#include"AM.h"
#include"AD.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include "Dequeue.h"
using namespace std;

AlienArmy::AlienArmy(int M_ArrSize) {
	Monsters_Arr = new AM * [M_ArrSize];
	monstersCounter = 0;
	for (int i = 0; i < M_ArrSize; ++i) {
		Monsters_Arr[i] = NULL;
		Empty_Monst_Index.enqueue(i);
	}
}

bool AlienArmy::addUnit(Units* U) {
	if (U->getType() == "AS")
		return AS_LIST.enqueue(dynamic_cast<AS*>(U));

	else if (U->getType() == "AD")
		return AD_LIST.frontenqueue(*dynamic_cast<AD*>(U));

	else if (U->getType() == "AM") {

		if (Empty_Monst_Index.isEmpty())
			return false;
		int j;
		Empty_Monst_Index.peek(j);
		Empty_Monst_Index.dequeue(j);
		Monsters_Arr[j] = dynamic_cast<AM*>(U);
		++monstersCounter;
		return true;
	}
	else
		return false;
}

void AlienArmy::printAA() {

	cout << "============== Alien Army Alive Units ==============" << endl;
	cout << AS_LIST.length << " AS [ ";
	AS_LIST.print();
	cout << " ]" << endl;

 ////////////////////////////////////////////////////////////////////////

	cout << monstersCounter << " AM [ ";
	for (int i = 0; i < M_ArrSize; ++i) {
		if(Monsters_Arr[i]!=NULL){
		cout << Monsters_Arr[i]->getID() << " ";
		}
	}
	cout << " ]" << endl;

 ////////////////////////////////////////////////////////////////////////

	cout << AD_LIST.length << " AD [ ";
	AD_LIST.print();
	cout << " ]" << endl;
}
