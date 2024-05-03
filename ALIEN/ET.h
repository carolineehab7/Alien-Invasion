#pragma once
#include <iostream>
#include "Units.h"
using namespace std;


class ET :public Units {
private:

public:
	ET(int id, string type, int jt, int health, int power, int AC);
	void attack();

};