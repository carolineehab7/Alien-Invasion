#include <iostream>
#include <string>
#include "Game.h"
#include "RandGen.h"
#include "Units.h"
#include "EarthArmy.h"
#include "AlienArmy.h"
using namespace std;

ostream operator<<(ostream& op, Units* uni) {
	op << uni->getID();
}

int main() {
	Game p;
	p.TestCode();

	//p.ProgramMode();
	
}