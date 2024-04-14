#pragma once
#include <iostream>
#include<string>
#include "Units.h"
#include "EarthArmy.h"
using namespace std;

class ES : public Units {
private:

public:
	ES(int id, string type, int jt, int health, int power, int AC);
	void attack();
};

