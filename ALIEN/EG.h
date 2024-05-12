#pragma once
#include <iostream>
#include"Units.h"
#include <cmath>
#include "AD.h"
#include"AM.h"
//#include"StackADT.h"
// //#include"Dequeue.h"
//#include"priQueue.h"
using namespace std;


class EG :public Units {
private:
	
public:
	EG(int id, string type, int jt, int health, int power, int AC);
	EG();
	int getScore();
	void attack();
};
