#include "Game.h"
#include "RandGen.h"
#include <fstream>
#include <iostream>
#include "LinkedQueue.h"

using namespace std;
Game::Game() {
	Time_step = 1;
	KilledList = new LinkedQueue<Units*>;


}

bool Game::KilledListfunc(Units* killunit) {
	return KilledList->enqueue(killunit);
}

void Game::LoadFromFile() {
	int n, prob, ES, ET, EG, AS, AM, AD;
	int maxPE, minPE, maxHE, minHE, maxCE, minCE;
	int maxPA, minPA, maxHA, minHA, maxCA, minCA;
	ifstream inpfile;
	inpfile.open("Input_Sample.txt");

	if (!inpfile) {
		cout << "Unable to open file" << endl;
		return;
	}
	inpfile >> n >> ES >> ET >> EG >> AS >> AM >> AD >> prob;
	inpfile >> minPE;
	inpfile.ignore();
	inpfile >> maxPE >> minHE;
	inpfile.ignore();
	inpfile >> maxHE >> minCE;
	inpfile.ignore();
	inpfile >> maxCE;
	inpfile >> minPA;
	inpfile.ignore();
	inpfile >> maxPA >> minHA;
	inpfile.ignore();
	inpfile >> maxHA >> minCA;
	inpfile.ignore();
	inpfile >> maxCA;

	randGenPtr->setES(ES);
	randGenPtr->setET(ET);
	randGenPtr->setEG(EG);
	randGenPtr->setAM(AM);
	randGenPtr->setAS(AS);
	randGenPtr->setAD(AD);
	randGenPtr->setProb(prob);
	randGenPtr->setminPE(minPE);
	randGenPtr->setmaxPE(maxPE);
	randGenPtr->setminHE(minHE);
	randGenPtr->setmaxHE(maxHE);
	randGenPtr->setminCE(minCE);
	randGenPtr->setmaxCE(maxCE);
	randGenPtr->setminPA(minPA);
	randGenPtr->setmaxPA(maxPA);
	randGenPtr->setminHA(minHA);
	randGenPtr->setmaxHA(maxHA);
	randGenPtr->setminCA(minCA);
	randGenPtr->setmaxCA(maxCA);
	//randobj.setN(n);
	//randobj.setES(ES);
	//randobj.setET(ET);
	//randobj.setEG(EG);
	//randobj.setAM(AM);
	//randobj.setAS(AS);
	//randobj.setAD(AD);
	//randobj.setProb(prob);
	//randobj.setminPE(minPE);
	//randobj.setmaxPE(maxPE);
	//randobj.setminHE(minHE);
	//randobj.setmaxHE(maxHE);
	//randobj.setminCE(minCE);
	//randobj.setmaxCE(maxCE);
	//randobj.setminPA(minPA);
	//randobj.setmaxPA(maxPA);
	//randobj.setminHA(minHA);
	//randobj.setmaxHA(maxHA);
	//randobj.setminCA(minCA);
	//randobj.setmaxCA(maxCA);

	inpfile.close();
}
RandGen* Game::getRandGenptr() {
	return randGenPtr;
}
EarthArmy* Game::getEarthArmyptr() {
	return EA;
}
AlienArmy* Game::getAlienArmyptr() {
	return AA;
}
void Game::PrintALL() {
	getEarthArmyptr()->printEA();
	getAlienArmyptr()->printAA();
	printKillList();
}
void Game::printKillList() {
	cout << "============== Killed/Destructed Units ==============" << endl;
	cout << KilledList->length << " Units" << " [";
	Node<Units*>* head = KilledList->getfrontPtr();
	while (head)
	{
		cout << head->getItem()->getID();
		if (head->getNext())
			cout << ", ";
		head = head->getNext();
	}
	cout << " ]" << endl;
}
void Game::TestCode() {
	LinkedQueue<Units*>* TempList;
	TempList = new LinkedQueue<Units*>;
	LoadFromFile();
	while (Time_step<50)
	{

		int X = rand() % (100 - 1 + 1) + 1;

		if (X > 0 && X < 10) {
			getEarthArmyptr()->addUnit(getEarthArmyptr()->pickES());
		}
		else if (X > 10 && X < 20) {
			KilledListfunc(getEarthArmyptr()->pickET());
		}
		else if (X > 20 && X < 30) {
			EG* p = getEarthArmyptr()->pickEG();
			p->setHealth(p->getHealth() / 2);
			getEarthArmyptr()->addUnit(p);

		}
		else if (X > 30 && X < 40) {
			for (int i = 0; i < 5; i++) {
				AS* s = getAlienArmyptr()->pickAS();
				s->setHealth((s->getHealth() - 1));
				TempList->enqueue(s);
				getAlienArmyptr()->addUnit(s);
			}
		}
		else if (X > 40 && X < 50) {
			AM* temp;
			getAlienArmyptr()->addUnit([Monsters_Arr[i]]);
			temp = Monster_Arr[M_ArrSize--];
			Monster_Arr[M_ArrSize] = Monsters_Arr[i];
			[Monsters_Arr[i] = temp;
		}
		else if (X > 50 && X < 60) {
			
		}
		PrintALL();
		cout << "Press any key to move to next timestep";
		Time_step++;
	}

}

Game::~Game() {
	delete KilledList;
}
