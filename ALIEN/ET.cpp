#include "ET.h"
using namespace std;
#include "Units.h"
#include <iostream>
#include "EarthArmy.h"
ET::ET(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
void ET::attack() {}