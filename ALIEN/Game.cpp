#include "Game.h"
#include "RandGen.h"
#include <fstream>
#include <iostream>
#include "LinkedQueue.h"

using namespace std;
Game::Game(){
	Time_step = 1;
	KilledList = new LinkedQueue<Units*>;
	
}

bool Game::Killedlist(Units *killunit) {
	KilledList->enqueue(killunit);
}

void Game::LoadFromFile(string filename) {
	int n, prob, ES, ET, EG, AS, AM, AD;
	int maxPE, minPE, maxHE, minHE, maxCE, minCE;
	int maxPA, minPA, maxHA, minHA, maxCA, minCA;
	
	inpfile.open(filename);
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
	inpfile>> maxCA;

	randGenObj.setN(n);
	randGenObj.setES(ES);
	randGenObj.setET(ET);
	randGenObj.setEG(EG);
	randGenObj.setAM(AM);
	randGenObj.setAS(AS);
	randGenObj.setAD(AD);
	randGenObj.setProb(prob);
	randGenObj.setminPE(minPE);
	randGenObj.setmaxPE(maxPE);
	randGenObj.setminHE(minHE);
	randGenObj.setmaxHE(maxHE);
	randGenObj.setminCE(minCE);
	randGenObj.setmaxCE(maxCE);
	randGenObj.setminPA(minPA);
	randGenObj.setmaxPA(maxPA);
	randGenObj.setminHA(minHA);
	randGenObj.setmaxHA(maxHA);
	randGenObj.setminCA(minCA);
	randGenObj.setmaxCA(maxCA);

	inpfile.close();
}
RandGen Game::*getRandGenptr() {
	return &randGenobj;
}
EarthArmy Game::*getEarthArmyptr() {
	return &EA;
}
AlienArmy Game::*getAlienArmyptr() {
	return &AA;
}

Game::~Game() {
	delete KilledList;
}
