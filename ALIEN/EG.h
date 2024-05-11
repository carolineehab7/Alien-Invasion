#pragma once
#include <iostream>
#include"Units.h"
//#include"priQueue.h"
#include <cmath>
#include "AD.h"
//#include"Dequeue.h"
#include"AM.h"
//#include"StackADT.h"
using namespace std;


class EG :public Units {
private:
	
public:
	EG(int id, string type, int jt, int health, int power, int AC);
	EG();
	int getScore();
	void attack();
};
