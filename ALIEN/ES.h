#pragma once
#include <iostream>
#include "Units.h"
#include<string>
using namespace std;
class Game;



class ES : public Units {
private:

public:
	ES();
	ES(int id, string type, int jt, int health, int power, int AC);
	void attack();
};

