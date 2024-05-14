#include "AS.h"
#include <iostream>
using namespace std;
#include"Game.h"

AS::AS() {

}
AS::AS(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
void AS::attack() {
	LinkedQueue<ES*> earths = gm->getEarthArmyptr()->getESList();
	LinkedQueue<ES*> templist;

 int Cap = this->AttackCapacity;
	
	while (Cap != 0) {

		Node<ES*>* currES = earths.getfrontPtr();
		ES* ESptr;
	bool check=	earths.dequeue(ESptr);
	if (check) {
		if (!ESptr->getattck()) {
			ESptr->setattck();
			int s = gm->getTime();
			ESptr->setTa(s);
		}

		double damage = (getHealth() * getPower() / 100) / sqrt(currES->getItem()->getHealth());

		ESptr->setHealth(ESptr->getHealth() - damage);

		if (currES->getItem()->getHealth() - damage == 0) {
			gm->KilledListfunc(currES->getItem());
		}
		else {
			templist.enqueue(currES->getItem());

		}
	}
		Cap--;
	
	}

	while (!templist.isEmpty()) {
		Node<ES*>* tempES = templist.getfrontPtr();
		ES* orgES = nullptr;
		if (orgES->getHealth() > 0 && orgES->getHealth() < 20) {
			templist.dequeue(orgES);
			gm->addtoES_UML(orgES);
		}
		else {
			templist.dequeue(orgES);
			earths.enqueue(tempES->getItem());
		}
	}
}