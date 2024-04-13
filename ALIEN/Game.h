#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include "EarthArmy.h"
#include "AlienArmy.h"
#include "QueueADT.h"
#include "LinkedQueue.h"
#include "RandGen.h"

using namespace std;

class Game
{
private:
	ifstream inpfile;
	EarthArmy EA;
	AlienArmy AA;
	int N;
public:
	Game();
	//LinkedQueue<T>killedlist();
	 
	void LoadFromFile(string filename);
	
	//istream &operator >>();
	
};

