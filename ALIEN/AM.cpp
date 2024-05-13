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

	while (Cap != 0) {

		Node<ES*>* NES = Searth.getfrontPtr();
		ET* Net;
		ES* sptr ;
		Tearth.pop(Net);
		Searth.dequeue(sptr);
		double damage = (getHealth() * getPower() / 100) / sqrt(Net->getHealth());
		double damage1 = (getHealth() * getPower() / 100) / sqrt(NES->getItem()->getHealth());
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
	}
	while (!Ttemplist.isEmpty()) {
		ET* tempET;
		Ttemplist.pop(tempET);
		Tearth.push(tempET);
	}
	while (!Stemplist.isEmpty()) {
		Node<ES*>* tempES = Stemplist.getfrontPtr();
		ES* orgES;
		Stemplist.dequeue(orgES);
		Searth.enqueue(tempES->getItem());
	}
}