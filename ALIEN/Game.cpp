#include "Game.h"
#include "RandGen.h"
#include <fstream>
#include <iostream>
#include "LinkedQueue.h"

using namespace std;
//Game::Game():{
//
//}


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
	inpfile >> minPE >> maxPE >> minHE >> maxHE >> minCE >> maxCE;
	inpfile >> minPA >> maxPA >> minHA >> maxHA >> minCA >> maxCA;

	randGenObj.setN(n);
	randGenObj.setES(ES);
	randGenObj.setET(ET);
	randGenObj.setEG(EG);
	randGenObj.setAM(AM);
	randGenObj.setAS(AS);
	randGenObj.setAD(AD);
	randGenObj.setProb(prob);

	inpfile.close();

}
