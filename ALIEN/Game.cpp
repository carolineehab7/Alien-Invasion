#include "Game.h"
#include "RandGen.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include "LinkedQueue.h"

using namespace std;
Game::Game() {
	Time_step = 1;
	KilledList = new LinkedQueue<Units*>;
	randGenPtr = new RandGen(this);
	EA = new EarthArmy;
	AA = new AlienArmy;

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

	randGenPtr->setN(n);
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
void Game::PrintSilent() {
	cout << "Silent Mode" << endl;
	cout << "Simulation Starts..." << endl;
	cout << "Simulation ends, Output file is created" << endl;
}

void Game::PrintALL() {
	cout << "Current Timestep " << Time_step << endl;
	getEarthArmyptr()->printEA();
	getAlienArmyptr()->printAA();
	printKillList();
	cout << "Press any key to move to the next timestep" << endl;
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

	char Mode = 0;
	cout << "Select the Program Mode (S || I): ";
	cin >> Mode;

	while (Time_step<=50)
	{
		randGenPtr->createUnit(randGenPtr->getN(), randGenPtr->getProb(), Time_step, randGenPtr->getES(), randGenPtr->getET(), randGenPtr->getEG(),randGenPtr->getAS()
			, randGenPtr->getAD(), randGenPtr->getAM(), randGenPtr->getminHE(), randGenPtr->getmaxHE(), randGenPtr->getminPE(), randGenPtr->getmaxPE(),
			randGenPtr->getminCE(), randGenPtr->getmaxCE(), randGenPtr->getminHA(), randGenPtr->getmaxHA(), randGenPtr->getminPA(), randGenPtr->getmaxPA(),
			randGenPtr->getminCA(), randGenPtr->getmaxCA());
		
		int X = rand() % (100 - 1 + 1) + 1;

		if (X > 0 && X < 10) {
			EA->addUnit(EA->pickES());
		}
		else if (X > 10 && X < 20) {
			KilledListfunc(EA->pickET());
		}
		else if (X > 20 && X < 30) {
			EG* p = getEarthArmyptr()->pickEG();
			if (p)
			{
				p->setHealth(p->getHealth() / 2);
				getEarthArmyptr()->addUnit(p);
			}

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
			for (int i=0; i<5; i++)
				getAlienArmyptr()->pickAM();
		}
		else if (X > 50 && X < 60) {
			getAlienArmyptr()->pickAD();
		}

		if (Mode == 'I') {
			PrintALL();
		}
		else {
			PrintSilent();
		}
		
		Sleep(300);
		Time_step++;
		system("CLS");
		
	}

}

Game::~Game() {
	delete KilledList;
}
