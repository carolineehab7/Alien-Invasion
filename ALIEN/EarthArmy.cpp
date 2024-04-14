#include "EarthArmy.h"
#include <iostream>
using namespace std;

bool EarthArmy::addUnit(Units* U) {
	if (U->getType() == "ES")
		ES_List.enqueue(dynamic_cast<ES*>(U));
	else if (U->getType() == "EG")
		EG_List.enqueue(dynamic_cast<EG*>(U));
	else if (U->getType() == "ET")
		ET_List.push(dynamic_cast<ET*>(U));
}
