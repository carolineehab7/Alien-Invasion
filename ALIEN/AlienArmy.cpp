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

AlienArmy::AlienArmy() {

}

AlienArmy::AlienArmy(int M_ArrSize) {
	Monsters_Arr = new AM * [M_ArrSize];
	monstersCounter = 0;
	for (int i = 0; i < M_ArrSize; ++i) {
		Monsters_Arr[i] = NULL;
		Empty_Monst_Index.enqueue(i);
		Mcount++;
	}
}
AS* AlienArmy::pickAS() {
	AS* ASptr;
	AS_LIST.dequeue(ASptr);
	return ASptr;
}
AM* AlienArmy::pickAM() {
	return Monsters_Arr[M_ArrSize--];
}

//AD** AlienArmy::pickAD() {
//	AD *front;
//	AD_LIST.dequeue(front);
//
//}

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
	//if (!(AS_LIST.length || AD_LIST.isEmpty() || Mcount = 0) {
		cout << "============== Alien Army Alive Units ==============" << endl;

		cout << AS_LIST.length << " AS [ ";

		Node<AS*>* Temp = AS_LIST.getfrontPtr();  // Temp Points to the Head

		while (Temp) {
			cout << Temp->getItem()->getID() << " ";
			Temp = Temp->getNext();
		}
		cout << " ]" << endl;

		////////////////////////////////////////////////////////////////////////

		cout << monstersCounter << " AM [ ";
		for (int i = 0; i < M_ArrSize; ++i) {
			if (Monsters_Arr[i] != NULL) {
				cout << Monsters_Arr[i]->getID() << ", ";
			}
		}

		cout << " ]" << endl;

		////////////////////////////////////////////////////////////////////////

		cout << AD_LIST.length << " AD [ ";

		Node<AD>* Temp2 = AD_LIST.getFrontPTR();  // Temp Points to the Head

		while (Temp2) {
			cout << Temp2->getItem().getID() << " ";
			Temp2 = Temp2->getNext();
		}

		cout << " ]" << endl;
	//}

	

}


AlienArmy::~AlienArmy() {

}
