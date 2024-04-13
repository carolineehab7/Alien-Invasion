#include "Game.h"
#include <fstream>
#include <iostream>
using namespace std;
Game::Game() {

}


void Game::LoadFromFile(string filename) {
	inpfile.open(filename);
	if (!inpfile) {
		cout << "Unable to open file" << endl;
		return;
	}
	inpfile >> RandGen::setN(inpfile) >> ES >> ET >> EG;
	inpfile >> AS >> AM >> AD;
	inpfile >> Prob;
	inpfile >> minPE >> maxPE;
	inpfile >> minHE >> maxHE;
	inpfile >> minCE >> maxCE;
	inpfile >> minPA >> maxPA;
	inpfile >> minHA >> maxHA;
	inpfile >> minCA >> maxCA;

	inpfile.close();

}
