#include "ET.h"
#include "Units.h"
#include <iostream>

using namespace std;

ET::ET(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
void ET::attack()
{
}
//void ET::attack(Game * gm) {
//	et->setAttackCapacity(ET_LIST.getCount());
//
//	if (am->getHealth() < et->getHealth())
//	{
//		g->KilledListfunc(am);
//	}
//	if(es)
//
//}

