#pragma once
#include <iostream>
#include "Units.h"
#include <string>
using namespace std;
class Game;


class ET :public Units {
private:
	int ET_UML_TIME;
public:
	ET(int id, string type, int jt, int health, int power, int AC);
	void attack();
	void setET_UML_TIME(int);
	int getET_UML_TIME();
}; 