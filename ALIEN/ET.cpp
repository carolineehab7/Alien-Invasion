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

		for (int j = 0; j < getAttackCapacity() ; j++)
		{
			double damage = (getHealth() * getPower() / 100) / sqrt(monster[j]->getHealth());

			if (monster[j]->getHealth() - damage == 0) {
				gm->KilledListfunc(monster[j]);
			}
			else  
			{
				templistAM[tempCounter] = monster[j];
				tempCounter++;
			} 
		}
 		for (int i = 0; i < tempCounter; i++) {
			templistAM[i] = monster[i];
		}
		
		if (esolider.getlength() < (0.3 * asolider.getlength()))
		{
			for (int i = 0; i < getAttackCapacity(); i++)
			{
				Node<AS*>* NAS = asolider.getfrontPtr();
				AS* ASptr;
				asolider.dequeue(ASptr);
				double damage = (getHealth() * getPower() / 100) / sqrt(NAS->getItem()->getHealth());
				if (NAS->getItem()->getHealth() - damage == 0) {
					gm->KilledListfunc(NAS->getItem());
				}
				else
					templist.enqueue(NAS->getItem());
		    }
	   }
}




