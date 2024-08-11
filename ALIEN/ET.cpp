#include "ET.h"
#include <iostream>
using namespace std;
#include"Game.h"

ET::ET(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
void ET::attack()
{
	AM** monster = gm->getAlienArmyptr()->getMonstersArr();
	LinkedQueue<ES*> esolider = gm->getEarthArmyptr()->getESList();
	LinkedQueue<AS*> asolider = gm->getAlienArmyptr()->getASList();
	int gg = gm->getAlienArmyptr()->getMonstersArrSize();
	LinkedQueue<AS*> templist;
	AM** templistAM = new AM * [gg];
	int tempCounter = 0;
	int Cap = this->AttackCapacity;

	if (gm->getAlienArmyptr()->getMonstersArrSize())
		return;

	if (gm->getMode() == 'I')
		cout << "ET Attacker " << this->ID << " [";

	while (Cap != 0)
	{
		if (gm->getAlienArmyptr()->getMonstersArrSize())
			break;

		int j = 0;
		double damage = (getHealth() * getPower() / 100) / sqrt(monster[j]->getHealth());

		if (gm->getMode() == 'I')
			cout << monster[j]->getID();

		if (monster[j]->getHealth() - damage == 0) {
			gm->KilledListfunc(monster[j]);
		}
		else
		{
			monster[j]->setHealth(monster[j]->getHealth() - damage);
			templistAM[tempCounter] = monster[j];
			tempCounter++;
		}
		j++;
		Cap--;
		if (gm->getMode() == 'I')
			cout << "\b\b" << "]";
	}
	for (int Z = 0; Z < gm->getAlienArmyptr()->getMonstersArrSize(); Z++) {
		if (monster[Z] = NULL) {
			for (int i = 0; i < tempCounter; i++) {
				monster[Z] = templistAM[i];
			}
		}
	}

	if (esolider.getlength() < (0.3 * asolider.getlength()))
	{
		while (Cap != 0)
		{
			if (gm->getAlienArmyptr()->getASList().isEmpty())
				break;

			Node<AS*>* NAS = asolider.getfrontPtr();
			AS* ASptr;
			asolider.dequeue(ASptr);
			double damage = (getHealth() * getPower() / 100) / sqrt(NAS->getItem()->getHealth());

			if (gm->getMode() == 'I')
				cout << ASptr->getID();

			if (NAS->getItem()->getHealth() - damage == 0) {
				gm->KilledListfunc(NAS->getItem());
			}
			else {
				NAS->getItem()->setHealth(NAS->getItem()->getHealth() - damage);
				templist.enqueue(NAS->getItem());
			}
			if (gm->getMode() == 'I')
				cout << "\b\b" << "]";
			Cap--;
		}
	}

	while (!templist.isEmpty())
	{
		AS* orgAS;
		templist.dequeue(orgAS);
		asolider.enqueue(orgAS);
	}
}

void ET::setET_UML_TIME(int y) {
	ET_UML_TIME = y;
}
int ET::getET_UML_TIME() {
	return ET_UML_TIME;
}




