#pragma once
#include <iostream>
using namespace std;
#include "QueueADT.h"
#include"Node.h"
#include"linkedQueue.h"
#include "Units.h"
#include"Units.cpp"
#include<string>
#include "EarthArmy.h"
class EG :public Units {
private:
	
public:
	EG(int id, string type, int jt, int health, int power, int AC);
	double getScore(int power, int health);
	EG operator < (EG* obj1);
	void attack();
};

inline std::ostream& operator<<(std::ostream& os, EG& eg) {
	os << eg.getID();
	return os;
}
