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
	int n, prob, ES, ET, EG, AS, AM, AD, HU_PER;
	int maxPE, minPE, maxHE, minHE, maxCE, minCE;
	int maxPA, minPA, maxHA, minHA, maxCA, minCA;
	ifstream inpfile;
	inpfile.open("Input_Sample.txt");

	if (!inpfile) {
		cout << "Unable to open file" << endl;
		return;
	}
	inpfile >> n >> HU_PER >> ES >> ET >> EG >> AS >> AM >> AD >> prob;
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
	randGenPtr->setHU_PER(HU_PER);
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
void Game::createoutfile() {
	int TD, ID, TJ, DF, Dd, Db;

	ofstream outfile("OutFile.txt");

	outfile << "TD " << "ID " << "Tj " << "Df " << "Dd " << "Db " << endl;
	//outfile<< 


}

LinkedQueue<ET*> Game::getET_UML() {
	return ET_Maintain;
}
priQueue <ES*> Game::getES_UML() {
	return ES_Maintain;
}
ArrayStack<HealUnit*> Game::getHL_LIST() {
	return HL_LIST;
}

void Game::addtoES_UML(ES* es_uml) {
	ES* esptr = NULL;
	int pri = 100 - es_uml->getHealth();
	esptr->setES_UML_TIME(getTime());
	ES_Maintain.enqueue(es_uml, pri);

}
void Game::addtoET_UML(ET* et_uml) {
	ET* etptr = NULL;
	etptr->setET_UML_TIME(getTime());
	ET_Maintain.enqueue(et_uml);
}

ES* Game::removefromES_uml() {
	ES* ESptr = new ES();
	int pri = 1;
	if (!ES_Maintain.isEmpty())
		ES_Maintain.dequeue(ESptr, pri);
	return ESptr;
}

ET* Game::removefromET_uml() {
	ET* ETptr = NULL;
	if (!ET_Maintain.isEmpty()) {
		ET_Maintain.dequeue(ETptr);
	}
	return ETptr;
}

void Game::addtoHeal(HealUnit* HU) {
	HL_LIST.push(HU);
}

HealUnit* Game::removefromHeal() {
	HealUnit* HUptr = new HealUnit();
	if (!HL_LIST.isEmpty()) {
		HL_LIST.pop(HUptr);
	}
	return HUptr;
}


int Game::getTime() {
	return Time_step;
}

char Game::getMode() 
{
	return Mode;
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

void Game::Simulation() {

	LinkedQueue<Units*>* TempList;
	TempList = new LinkedQueue<Units*>;
	LoadFromFile();
	cout << "Select the Program Mode (S || I): ";
	cin >> Mode;
	if (Mode == 'I') {
		bool  winA = false;
		bool winB = false;
		while (true) {

			randGenPtr->createUnit();

			int totalEA = this->EA->getETList().getCount() + this->EA->getESList().length + this->EA->getEGList().length;
			int totalAA = this->AA->getADList().length + this->AA->getASList().length + this->AA->getMonstersArrSize();

			if (totalEA == 0) {
				winA = true; 
				break;
			}

			else if (totalAA == 0) {
				winB = true;
				break;
			}

			EA->AttackAA();
			AA->AttackEA();

			PrintALL();
		}
		Sleep(300);
		//Time_step++;
		system("CLS");

	}
	else if (Mode == 'S') {
		PrintSilent();
		createoutfile();

	}

}


Game::~Game() {
	delete KilledList;
}
