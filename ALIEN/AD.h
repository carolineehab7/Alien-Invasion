#pragma once
#include <iostream>
#include <string>
#include "Units.h"
using namespace std;

class AD : public Units{
private:

public:
	AD(int id, string type, int jt, int health, int power, int AC);
	void attack();
};
