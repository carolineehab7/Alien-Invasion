#include "EG.h"

EG::EG(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}

EG::EG()
{
}

int EG::getScore() {
	int Score = getHealth() * getPower();
	return Score;
}


void EG::attack() {
	Dequeue drones = gm->getAlienArmyptr()->getADList();
	AM** monsters = gm->getAlienArmyptr()->getMonstersArr();

	priQueue<AM*>templistAM;
	priQueue<AD*>templistAD;

	
	int ADcount = getAttackCapacity() / 2 + getAttackCapacity() % 2;
	int AMcount = getAttackCapacity() / 2;

	for (int i = 0; i < ADcount; i+2) {
		Node<AD*>* currAD = drones.getfrontPtr();
		Node<AD*>* backAD = drones.getbackPtr();
		AM* AMptr;
		AD* ADptr;
		AD* ADB;
		drones.dequeue(ADptr);
		drones.backdequeue(*ADB);
		double damage = (getHealth() * getPower() / 100) / sqrt(currAD->getItem()->getPower());
		double damage2 = (getHealth() * getPower() / 100) / sqrt(backAD->getItem()->getPower());
		if (getHealth() - damage == 0) {
			gm->KilledListfunc(currAD->getItem());
		}
		else
			templistAD.enqueue(currAD->getItem(),);
	}


	for (int j = 0; j < AMcount; j++)
	{
		double damage = (getHealth() * getPower() / 100) / sqrt(monsters[j]->getHealth());
		if (getHealth() - damage == 0) {
			gm->KilledListfunc(monsters[j]);
		}
		else
			templistAM.enqueue(monsters[j], );
	}
	AM** newmonster = new AM*[sizeof(monsters)+ templistAM.length];
	for (int s = 0; s < sizeof(monsters); ++s) {
		newmonster[s] = monsters[s];
	}
	while (!templistAD.isEmpty()) {
		priNode<AD*>* tempAD = templistAD.getHead();
		AD* orgAD;
		templistAD.dequeue(orgAD,);
		drones.enqueue(tempAD->getItem(),);
	}
	while (!templistAM.isEmpty()) {
		priNode<AM*>* tempAM = templistAM.getHead();
		AM* orgAM;
		templistAM.dequeue(orgAM);
		monsters.enqueue(tempAM->getItem());
	}
	


	
}