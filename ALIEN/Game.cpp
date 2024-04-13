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
	int n, ES, ET, EG;
	
	inpfile.open(filename);
	if (!inpfile) {
		cout << "Unable to open file" << endl;
		return;
	}
	inpfile >> n >> ET;
	/*inpfile >> AS >> AM >> AD;
	inpfile >> Prob;
	inpfile >> minPE >> maxPE;
	inpfile >> minHE >> maxHE;
	inpfile >> minCE >> maxCE;
	inpfile >> minPA >> maxPA;
	inpfile >> minHA >> maxHA;
	inpfile >> minCA >> maxCA;*/

	RandGen.setN(n);
	
	inpfile.close();

}
