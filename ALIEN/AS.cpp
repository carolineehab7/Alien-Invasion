#pragma once
#include <iostream>
using namespace std;
#include "Units.h"
#include<string>
#include"AlienArmy.h"
#include"AlienArmy.CPP"
#include "AS.h"
AS::AS(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
void AS::attack() {}