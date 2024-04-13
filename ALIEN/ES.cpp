#pragma once
#include <iostream>
using namespace std;
#include "Units.h"
#include<string>
#include "ES.h"
#include "EarthArmy.h"
ES::ES(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
void ES::attack() {}