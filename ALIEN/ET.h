#pragma once
#include <iostream>
#include "EarthArmy.h"
using namespace std;
class Units;

class ET :public	Units {
private:

public:
	ET(int id, string type, int jt, int health, int power, int AC);
	void attack();
};