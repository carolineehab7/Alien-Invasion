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
istream operator >> () {

}
template <typename T>
class Game
{
private:
	ifstream inpfile;
	EarthArmy EA;
	AlienArmy AA;
public:
	Game();
	LinkedQueueADT<T>killedlist();

	void LoadFromFile(string filename);
	
	istream &operator >>();
	
};

