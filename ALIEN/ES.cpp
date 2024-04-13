#pragma once
#include <iostream>
using namespace std;
#include "Units.h"
#include "Units.cpp"
#include<string>
#include "ES.h"
#include "EarthArmy.h"
#include"EarthArmy.cpp"
ES::ES(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
void ES::attack() {}