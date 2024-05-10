#include "ES.h"

ES::ES()
{
}

ES::ES(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {	

}
void ES::attack() {
	LinkedQueue<AS*> alians = gm->getAlienArmyptr()->getASList();
	LinkedQueue<AS*>templist;
	for (int i = 0; i < getAttackCapacity(); i++) {

		Node<AS*>* currAS = alians.getfrontPtr();
		AS* ASptr;
		alians.dequeue(ASptr);
		double damage = (getHealth() * getPower()/100) / sqrt(currAS->getItem()->getHealth());
		if (currAS->getItem()->getHealth()-damage == 0) {
			gm->KilledListfunc(currAS->getItem());
		}
		else
			templist.enqueue(currAS->getItem());
	}
	while (!templist.isEmpty()) {
		Node<AS*>* tempAS = templist.getfrontPtr();
		AS* orgAS;
		templist.dequeue(orgAS);
		alians.enqueue(tempAS->getItem());
}



