#pragma once
#include <iostream>
#include<string>
#include "EarthArmy.h"
using namespace std;
class Units;

class ES : public Units {
private:

public:
	ES(int id, string type, int jt, int health, int power, int AC);
	void attack();
};

