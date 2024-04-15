#include<iostream>
#include"Units.h"
#include"EG.h"
#include"ES.h"
#include"ET.h"
#include"LinkedQueue.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"priNode.h"
#include"EarthArmy.h"
using namespace std;
EarthArmy::EarthArmy() {

}

bool EarthArmy::addUnit(Units* U) {

	if (U->getType() == "ES")
		ES_LIST.enqueue(dynamic_cast<ES*>(U));
	else if (U->getType() == "EG")
		EG_LIST.enqueue(dynamic_cast<EG*>(U),1);
	else if (U->getType() == "ET")
		ET_LIST.push(dynamic_cast<ET*>(U));

}

ES* EarthArmy::pickES()
{
	ES* ESptr;
	ES_LIST.dequeue(ESptr);
	return ESptr;
}

EG* EarthArmy::pickEG()
{
	EG* EGptr;
	int pri = 1;
	EG_LIST.dequeue(EGptr,pri);
	return EGptr;
}

ET* EarthArmy::pickET()
{
	ET* ETptr;
	ET_LIST.pop(ETptr);

	return ETptr;
}



void EarthArmy::printEA() {

	cout << "============== Earth Army Alive Units ==============" << endl;
	cout << ES_LIST.length << " ES [ ";
	ES_LIST.print();
	cout << " ]" << endl;

 ////////////////////////////////////////////////////////////////////////

	cout << EG_LIST.length << " EG [ ";
	EG_LIST.print();
	cout << " ]" << endl;

 ////////////////////////////////////////////////////////////////////////

	cout << ET_LIST.getTop() << " ET [ ";
	ET_LIST.print();
	cout << " ]" << endl;

}
EarthArmy::~EarthArmy() {

}