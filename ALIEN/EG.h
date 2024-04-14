#pragma once
#include <iostream>
#include<string>
#include "QueueADT.h"
#include"Node.h"
#include"linkedQueue.h"
#include "Units.h"
#include "EarthArmy.h"
using namespace std;

class EG :public Units {
private:
	
public:
	EG(int id, string type, int jt, int health, int power, int AC);
	double getScore(int power, int health);
	EG operator < (EG* obj1);
	void attack();
};
