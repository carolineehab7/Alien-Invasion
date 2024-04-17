#pragma once
#include <iostream>
#include"Units.h"


class EG :public Units {
private:
	
public:
	EG(int id, string type, int jt, int health, int power, int AC);
	EG();
	int getScore();
	//	EG operator < (EG* obj1);
	void attack();
};
