#include "AM.h"

AM::AM(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC)
{

}

void AM::attack()
{
	LinkedQueue<ES*> Searth = gm->getEarthArmyptr()->getESList();
	ArrayStack<ET*> Tearth = gm->getEarthArmyptr()->getETList();  
	LinkedQueue<ES*> Stemplist;
	ArrayStack<ET*> Ttemplist;
	for (int i = 0; i < getAttackCapacity(); i++) {

		Node<ES*>* NES = Searth.getfrontPtr();
		Node<ET*>* NET = Tearth.getTop();
		ES* sptr ;
		ET* tptr = nullptr;
		Tearth.pop(tptr);
		Searth.dequeue(sptr);
		double damage = (getHealth() * getPower() / 100) / sqrt(NET->getItem()->getHealth());
		double damage = (getHealth() * getPower() / 100) / sqrt(NES->getItem()->getHealth());
		if (NET->getItem()->getHealth() - damage == 0) {
			gm->KilledListfunc(NET->getItem());
		}
		if (NES->getItem()->getHealth() - damage == 0) { 
			gm->KilledListfunc(NES->getItem());
		}
		else
			Stemplist.enqueue(NES->getItem());

	}
	while (!Ttemplist.isEmpty()) {
		Node<ET*>* tempET = Ttemplist.getTop();
		ET* orgET;
		Ttemplist.pop(orgET);
		Tearth.push(tempET->getItem());
	}
	while (!Stemplist.isEmpty()) {
		Node<ES*>* tempES = Stemplist.getfrontPtr();
		ES* orgES;
		Stemplist.dequeue(orgES);
		Searth.enqueue(tempES->getItem());
	}
}