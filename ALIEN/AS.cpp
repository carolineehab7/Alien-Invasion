#include "AS.h"

AS::AS() {

}
AS::AS(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
void AS::attack() {
	LinkedQueue<ES*> earths = gm->getEarthArmyptr()->getESList();
	LinkedQueue<ES*> templist;
	for (int i = 0; i < getAttackCapacity(); i++) {

		Node<ES*>* currES = earths.getfrontPtr();
		ES* ESptr;
		earths.dequeue(ESptr);
		double damage = (getHealth() * getPower()/100 ) / sqrt(currES->getItem()->getHealth());
		if (currES->getItem()->getHealth()-damage == 0) {
			gm->KilledListfunc(currES->getItem());
		}
		else
			templist.enqueue(currES->getItem());

	}
	while (!templist.isEmpty()) {
		Node<ES*>* tempES = templist.getfrontPtr();
		ES* orgES;
		templist.dequeue(orgES);
		earths.enqueue(tempES->getItem());
	}
}