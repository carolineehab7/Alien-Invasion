#include "EG.h"
#include <iostream>
using namespace std;

EG::EG(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}
double EG::getScore(int power, int health) {
	return (power * 0.8 + health * 0.2);
}
EG EG ::operator < (EG* obj1) {
	getScore(this->Power, this->Health) < getScore(obj1->Power, obj1->Health);
}
void EG::attack() {

}