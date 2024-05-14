#include "HealUnit.h"
#include "Game.h"
#include <cmath>
#include <iostream>

using namespace std;

HealUnit::HealUnit() {

}

HealUnit::HealUnit(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}


void HealUnit::attack() {
	int oldhealth;
	int oldhealth2;
	Game* ptrg = NULL;
	while (!(gm->getHL_LIST().isEmpty())) {
		LinkedQueue<ET*>TEMP_ET;
		LinkedQueue<ES*>TEMP_ES;
		HealUnit* HU = gm->removefromHeal();


		if (!(ptrg->getES_UML().isEmpty())) {
			ES* ptr = gm->removefromES_uml();
			if (gm->getTime() - ptr->getES_UML_TIME() <= 10) {
				oldhealth = ptr->getHealth();
				int healthImprov = (getPower() * (getHealth() / 100)) / sqrt(ptr->getHealth());
				ptr->setHealth(healthImprov);
				if (((ptr->getHealth() / oldhealth) * 100) > 20) {
					gm->getEarthArmyptr()->addUnit(ptr);

				}
				else
					gm->KilledListfunc(ptr);
			}

		}
		else {
			ET* ptr2 = gm->removefromET_uml();
			if (gm->getTime() - ptr2->getET_UML_TIME() <= 10) {
				oldhealth2 = ptr2->getHealth();
				int improv= (getPower() * (getHealth() / 100)) / sqrt(ptr2->getHealth());
				ptr2->setHealth(improv);

				if (((ptr2->getHealth() / oldhealth2) * 100) > 20) {
					gm->getEarthArmyptr()->addUnit(ptr2);

				}
				else
					gm->KilledListfunc(ptr2);
			}

		}
		while (!TEMP_ES.isEmpty()) {
			ES* m = NULL;
			TEMP_ES.dequeue(m);
			gm->addtoES_UML(m);


		}
		while (!TEMP_ET.isEmpty()) {
			ET* T = NULL;
			TEMP_ET.dequeue(T);
			gm->addtoET_UML(T);
		}


	}




}
