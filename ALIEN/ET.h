#pragma once
using namespace std;
#include "Units.h"
#include <iostream>
#include "EarthArmy.h"
class ET:public	Units {
private:

public:
	ET(int id, string type, int jt, int health, int power, int AC);
	void attack();
};
