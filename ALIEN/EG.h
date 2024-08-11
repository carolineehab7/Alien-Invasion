#pragma once
#include <iostream>
#include"Units.h"
using namespace std;
class Game;



class EG :public Units {
private:

public:
	EG(int id, string type, int jt, int health, int power, int AC);
	EG();
	int getScore();
	void attack();
};
