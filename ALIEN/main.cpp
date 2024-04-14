#include <iostream>
#include <string>
#include "Game.h"
#include "RandGen.h"
#include "Units.h"
#include "EarthArmy.h"
#include "AlienArmy.h"

using namespace std;

int main() {
	int X;
	int TimeStep;
	RandGen generator;
	Game play("Input_sample.txt");
	while (TimeStep < 50) {
		X = rand() % (100) + 1;

	}


}