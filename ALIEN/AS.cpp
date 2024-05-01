#include "AS.h"
#include "Units.h"
#include <iostream>
using namespace std;

AS::AS() {

}
AS::AS(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
void AS::attack() {
}