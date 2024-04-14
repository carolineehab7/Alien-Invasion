#include "AlienArmy.h"
#include <iostream>
using namespace std;

AlienArmy::AlienArmy(int M_ArrSize) {
	Monsters_Arr = new AM * [M_ArrSize];
	for (int i = 0; i < M_ArrSize; ++i) {
		Monsters_Arr[i] = NULL;
		Empty_Monst_Index.enqueue(i);
	}
}
bool AlienArmy::addUnit(Units* U) {
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
void AlienArmy::printAM() {
	for (int i = 0; i < M_ArrSize; ++i) {
		cout << Monsters_Arr[i]->getID() << " ";
	}
}
