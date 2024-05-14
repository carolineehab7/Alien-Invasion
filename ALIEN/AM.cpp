#include "AM.h"
#include <iostream>
using namespace std;
#include"Game.h"

AM::AM(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC)
{

}

void AM::attack()
{
	LinkedQueue<ES*> Searth = gm->getEarthArmyptr()->getESList();
	ArrayStack<ET*> Tearth = gm->getEarthArmyptr()->getETList();
	LinkedQueue<ES*> Stemplist;
	ArrayStack<ET*> Ttemplist;
	int Cap = this->AttackCapacity;

	if (gm->getEarthArmyptr()->getETList().isEmpty() && gm->getEarthArmyptr()->getESList().isEmpty())
		return;

	if (gm->getMode() == 'I')
		cout << "AM Attacker " << this->ID << " [";

	while (Cap != 0) {

		if (gm->getEarthArmyptr()->getETList().isEmpty() && gm->getEarthArmyptr()->getESList().isEmpty())
			break;

		Node<ES*>* NES = Searth.getfrontPtr();
		ET* Net;
		ES* sptr;
		Tearth.pop(Net);
		Searth.dequeue(sptr);

		double damage = (getHealth() * getPower() / 100) / sqrt(Net->getHealth());

		if (gm->getMode() == 'I')
			cout << Net->getID();

		double damage1 = (getHealth() * getPower() / 100) / sqrt(NES->getItem()->getHealth());

		if (gm->getMode() == 'I')
			cout << sptr->getID();

		if (Net->getHealth() - damage == 0) {
			gm->KilledListfunc(Net);
		}
		else
		{
			Net->setHealth(Net->getHealth() - damage);
			Ttemplist.push(Net);
		}

		if (NES->getItem()->getHealth() - damage1 == 0) {
			gm->KilledListfunc(NES->getItem());
		}
		else
		{
			NES->getItem()->setHealth(NES->getItem()->getHealth() - damage1);
			Stemplist.enqueue(NES->getItem());
		}
		Cap--;
		if (gm->getMode() == 'I')
			cout << "\b\b" << "]";
	}


	while (!Ttemplist.isEmpty()) {
		ET* tempET=nullptr;
		if (tempET->getHealth() > 0 && tempET->getHealth() < 20) {
			Ttemplist.pop(tempET);
			gm->addtoET_UML(tempET);
		}
		else {
			Ttemplist.pop(tempET);
			Tearth.push(tempET);
		}
	}
	
	while (!Stemplist.isEmpty()) {
		
		ES* orgES=nullptr;
		if (orgES->getHealth() > 0 && orgES->getHealth() < 20)
		{
			Stemplist.dequeue(orgES);
			gm->addtoES_UML(orgES);
		}
		else {
			Stemplist.dequeue(orgES);
			Searth.enqueue(orgES);
		}
	}
}