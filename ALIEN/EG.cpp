#include "EG.h"
#include <iostream>
using namespace std;
#include"Game.h"


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
	AlienArmy* alienm = gm->getAlienArmyptr();
	AM** monsters = gm->getAlienArmyptr()->getMonstersArr();

	Dequeue templistAD;

	if (gm->getAlienArmyptr()->getMonstersArrSize() == 0 && gm->getAlienArmyptr()->getADList().isEmpty())
		return;

	if (gm->getMode() == 'I')
		cout << "EG Attacker " << this->ID << " [";

	int capacity = getAttackCapacity();
	int ADcount = capacity / 2 + capacity % 2;
	int AMcount = capacity / 2;
	int tempCounter = 0;

	LinkedQueue<AM*> templistAM;

	int i = 0;
	for (i = 0; i < ADcount; i + 2) {
		AM* AMptr;
		AD* ADptr;
		AD* ADB = NULL;

		if (gm->getAlienArmyptr()->getMonstersArrSize() == 0 && gm->getAlienArmyptr()->getADList().isEmpty())
			break;

		Node<AD*>* currAD = drones.getfrontPtr();
		Node<AD*>* backAD = drones.getbackPtr();

		bool check1 = drones.dequeue(ADptr);
		bool check2 = drones.backdequeue(*ADB);
		if (check1) {
			if (!currAD->getItem()->getattck()) {
				currAD->getItem()->setattck();
				int s = gm->getTime();
				currAD->getItem()->setTa(s);
			}
			/*if (!backAD->getItem()->getattck()) {
				backAD->getItem()->setattck();
				int s = gm->getTime();
				backAD->getItem()->setTa(s);
			}*/
			double frontDamage = (getHealth() * getPower() / 100) / sqrt(currAD->getItem()->getHealth());

			if (gm->getMode() == 'I')
				cout << ADptr->getID();

			/*double backDamage = (getHealth() * getPower() / 100) / sqrt(backAD->getItem()->getHealth());*/

			if (currAD->getItem()->getHealth() - frontDamage == 0) {
				gm->KilledListfunc(currAD->getItem());
			}
			else
			{
				templistAD.enqueue(currAD->getItem());
			}

			/*if (backAD->getItem()->getHealth() - backDamage == 0) {
				gm->KilledListfunc(backAD->getItem());
			}
			else
			{
				templistAD.enqueue(backAD->getItem());
			}*/


			if (i > ADcount)
			{
				AD* sAD;
				Node<AD*>* currSAD = drones.getfrontPtr();
				drones.dequeue(sAD);
				double DamageS = (getHealth() * getPower() / 100) / sqrt(currSAD->getItem()->getHealth());
				if (currSAD->getItem()->getHealth() - DamageS == 0) {
					gm->KilledListfunc(currSAD->getItem());
				}
				else
				{
					templistAD.enqueue(currSAD->getItem());
				}
			}
		}
		if (check2) {
			if (!backAD->getItem()->getattck()) {
				backAD->getItem()->setattck();
				int s = gm->getTime();
				backAD->getItem()->setTa(s);
			}
			double backDamage = (getHealth() * getPower() / 100) / sqrt(backAD->getItem()->getHealth());
			if (gm->getMode() == 'I')
				cout << ADptr->getID();
			if (backAD->getItem()->getHealth() - backDamage == 0) {
				gm->KilledListfunc(backAD->getItem());
			}
			else
			{
				templistAD.enqueue(backAD->getItem());
			}


		}


	}

	for (int j = 0; j < AMcount; j++)
	{
		AM* am = alienm->pickAM();

		if (!am->getattck()) {
			am->setattck();
			int s = gm->getTime();
			am->setTa(s);
		}
		double damage = (getHealth() * getPower() / 100) / sqrt(am->getHealth());
		if (gm->getMode() == 'I')
			cout << am->getID();

		if (am->getHealth() - damage == 0) {

			gm->KilledListfunc(am);
			am = nullptr;
		}
		else
		{
			templistAM.enqueue(am);
		}
	}

	while (!templistAD.isEmpty()) {
		Node<AD*>* tempAD = templistAD.getfrontPtr();
		AD* orgAD;
		templistAD.dequeue(orgAD);
		drones.enqueue(tempAD->getItem());
	}

	AM** monstersAfterAttack = new AM * [sizeof(monsters)];
	int monstersAfterAttackIndex = 0;

	for (int m = AMcount; m < sizeof(monsters); m++)
	{
		monstersAfterAttack[monstersAfterAttackIndex] = monsters[m];
		monstersAfterAttackIndex++;
	}

	for (int m = 0; m < AMcount; m++)
	{
		monstersAfterAttack[monstersAfterAttackIndex] = templistAM[m];
		monstersAfterAttackIndex++;
	}
	monsters = monstersAfterAttack;*/

}
//void EG::attack() {
//	Dequeue drones = gm->getAlienArmyptr()->getADList();
//	AM** monsters = gm->getAlienArmyptr()->getMonstersArr();
//	AM** templistAM = new AM*[sizeof(monsters)];
//	Dequeue templistAD;
//
//	int capacity = getAttackCapacity();
//	int ADcount = capacity / 2 + capacity % 2;
//	int AMcount = capacity / 2;
//	int tempCounter = 0;
//
//	int i = 0;
//	for (i = 0; i < ADcount; i+2) {
//		AM* AMptr;
//		AD* ADptr;
//		AD* ADB = nullptr;
//
//		Node<AD*>* currAD = drones.getfrontPtr();
//		Node<AD*>* backAD = drones.getbackPtr();
//		
//		drones.dequeue(ADptr);
//		drones.backdequeue(*ADB);
//
//		double frontDamage = (getHealth() * getPower() / 100) / sqrt(currAD->getItem()->getHealth());
//		double backDamage = (getHealth() * getPower() / 100) / sqrt(backAD->getItem()->getHealth());
//
//		if (currAD->getItem()->getHealth() - frontDamage == 0) {
//			gm->KilledListfunc(currAD->getItem());
//		}
//		else
//		{
//			templistAD.enqueue(currAD->getItem());
//		}
//
//		if (backAD->getItem()->getHealth() - backDamage == 0) {
//			gm->KilledListfunc(backAD->getItem());
//		}
//		else
//		{
//			templistAD.enqueue(backAD->getItem());
//		}
//	}
//
//	if (i > ADcount)
//	{
//		AD* sAD;
//		Node<AD*>* currSAD = drones.getfrontPtr();
//		drones.dequeue(sAD);
//		double DamageS= (getHealth() * getPower() / 100) / sqrt(currSAD->getItem()->getHealth());
//		if (currSAD->getItem()->getHealth() - DamageS == 0) {
//			gm->KilledListfunc(currSAD->getItem());
//		}
//		else
//		{
//			templistAD.enqueue(currSAD->getItem());
//		}
//	}
//
//	for (int j = 0; j < AMcount; j++)
//	{
//		double damage = (getHealth() * getPower() / 100) / sqrt(monsters[j]->getHealth());
//
//		if (monsters[j]->getHealth() - damage == 0) {
//			gm->KilledListfunc(monsters[j]);
//		}
//		else
//		{
//			templistAM[tempCounter] = monsters[j];
//			tempCounter++;
//		}
//	}
//	/*AM** newMonster = new AM * [sizeof(monsters) + tempCounter];
//	
//	for (int s = 0; s < sizeof(monsters); ++s) {
//		newMonster[s] = monsters[s];
//	}*/
//	while (!templistAD.isEmpty()) {
//	  Node<AD*>* tempAD = templistAD.getfrontPtr();
//		AD* orgAD;
//		templistAD.dequeue(orgAD);
//		drones.enqueue(tempAD->getItem());
//	}
//
//	monsters = templistAM;
//	/*while (!templistAM) {
//		Node<AM*>* tempAM = templistAM;
//		AM* orgAM;
//		templistAM.dequeue(orgAM);
//		monsters.enqueue(tempAM->getItem());
//	}*/
//	
//
//
//	
//}