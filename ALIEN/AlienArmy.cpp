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
	ADArr = new AD *[2];
	M_ArrSize = 100;    
	monstersCounter = 0;
	Monsters_Arr = new AM * [M_ArrSize];
	for (int i = 0; i < M_ArrSize; ++i) {
		Monsters_Arr[i] = NULL;
		Empty_Monst_Index.enqueue(i);

	}

}

AS* AlienArmy::pickAS() {
	AS* ASptr;
	AS_LIST.dequeue(ASptr);
	return ASptr;
}

AM* AlienArmy::pickAM() {
	if (monstersCounter == 0)
		return NULL;
	int ind = rand() % monstersCounter;
	AM* temp = Monsters_Arr[ind]; 
	Monsters_Arr[ind] = Monsters_Arr[monstersCounter - 1];
	monstersCounter--;

	return temp;
}

AD** AlienArmy::pickAD() {
	
	if (AD_LIST.length % 2 == 0) {
		AD* front = new AD();
		AD* rear = new AD();
		AD_LIST.dequeue(front);
		AD_LIST.backdequeue(*rear);
		ADArr[0] = front;
		ADArr[1] = rear;
	}
	return ADArr;
}

bool AlienArmy::addUnit(Units* U) {
	if (U->getType() == "AS")
	{
		return AS_LIST.enqueue(dynamic_cast<AS*>(U));
	}

	else if (U->getType() == "AD") {
			AD* ADUnit = dynamic_cast<AD*>(U);
			return AD_LIST.frontenqueue(ADUnit);
	}

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
				AS_LIST.printLQ();
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

				AD_LIST.printDE();

				cout << " ]" << endl;
			
		
	

}

LinkedQueue<AS*> AlienArmy::getASList()
{
	return AS_LIST;
}

Dequeue AlienArmy::getADList()
{
	return AD_LIST;
}

AM** AlienArmy::getMonstersArr()
{
	return Monsters_Arr;
}

int AlienArmy::getMonstersArrSize()
{
	return M_ArrSize;
}



AlienArmy::~AlienArmy() {

}
