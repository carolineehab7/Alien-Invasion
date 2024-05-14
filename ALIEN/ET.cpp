#include "ET.h"
#include <iostream>
using namespace std;
#include"Game.h"

ET::ET(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
void ET::attack()
{
	AM** monster = gm->getAlienArmyptr()->getMonstersArr();
	LinkedQueue<ES*> esolider = gm->getEarthArmyptr() ->getESList();
	LinkedQueue<AS*> asolider = gm->getAlienArmyptr()->getASList();
	LinkedQueue<AS*> templist;
	AM** templistAM = new AM * [sizeof(monster)];
	int tempCounter = 0;
	int Cap = this->AttackCapacity;


		while(Cap !=0)
		{
			int j=0;
			double damage = (getHealth() * getPower() / 100) / sqrt(monster[j]->getHealth());

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
		}
		for (int Z = 0; Z < sizeof(monster); Z++) {
			if (monster[Z] = NULL) {
			for (int i = 0; i < tempCounter; i++) {
				monster[Z]= templistAM[i];
			}
			}
		}
		
		if (esolider.getlength() < (0.3 * asolider.getlength()))
		{
			while(Cap != 0)
			{
				Node<AS*>* NAS = asolider.getfrontPtr();
				AS* ASptr;
				asolider.dequeue(ASptr);
				double damage = (getHealth() * getPower() / 100) / sqrt(NAS->getItem()->getHealth());
				if (NAS->getItem()->getHealth() - damage == 0) {
					gm->KilledListfunc(NAS->getItem());
				}
				else
					NAS->getItem()->setHealth(NAS->getItem()->getHealth() - damage);
					templist.enqueue(NAS->getItem());
				Cap--;
		    }
	   }
		while (!templist.isEmpty())
		{
			Node<AS*>* tempAS = templist.getfrontPtr();
			AS* orgAS;
			templist.dequeue(orgAS);
			asolider.enqueue(tempAS->getItem());
		}
}
void ET::setET_UML_TIME(int y) {
	ET_UML_TIME = y;
}
int ET::getET_UML_TIME() {
	return ET_UML_TIME;
}




