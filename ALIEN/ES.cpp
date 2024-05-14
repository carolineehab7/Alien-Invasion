#include "ES.h"
#include <iostream>
#include"LinkedQueue.h"
#include"AS.h"
using namespace std;
#include"Game.h"

ES::ES()
{
}

ES::ES(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {	

}
void ES::attack() {
	LinkedQueue<AS*> alians = gm->getAlienArmyptr()->getASList();
	LinkedQueue<AS*>templist;

	if (gm->getAlienArmyptr()->getASList().isEmpty())
		return;

	int Cap = this->AttackCapacity;


	while (Cap != 0) {

		Node<AS*>* currAS = alians.getfrontPtr();
		AS* ASptr;
		if (gm->getAlienArmyptr()->getASList().isEmpty())
			break;
		bool check = alians.dequeue(ASptr);
		if (check) {
			if (!ASptr->getattck()) {
				ASptr->setattck();
				int firstAtime = gm->getTime();
				ASptr->setTa(firstAtime);
			}
			double damage = (getHealth() * getPower() / 100) / sqrt(currAS->getItem()->getHealth());

			if (gm->getMode() == 'I')
				cout << ASptr->getID();

			ASptr->setHealth(ASptr->getHealth() - damage);

			if (currAS->getItem()->getHealth() - damage == 0) {
				gm->KilledListfunc(currAS->getItem());
			}
			else {
				templist.enqueue(currAS->getItem());
			}
		}
		Cap--;
	}
		
		while (!templist.isEmpty()) {
			Node<AS*>* tempAS = templist.getfrontPtr();
			AS* orgAS;
			templist.dequeue(orgAS);
			alians.enqueue(tempAS->getItem());
		}
	


}
