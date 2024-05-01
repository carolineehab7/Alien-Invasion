#include<iostream>
#include"Units.h"
#include"EG.h"
#include"ES.h"
#include"ET.h"
#include"ArrayStack.h"
#include"priQueue.h"
#include"priNode.h"
#include"EarthArmy.h"
#include"LinkedQueue.h"
#include"Node.h"
using namespace std;

EarthArmy::EarthArmy() {
	
;
}

bool EarthArmy::addUnit(Units* U) {

	if (U->getType() == "ES")
		ES_LIST.enqueue(dynamic_cast<ES*>(U));
	else if (U->getType() == "EG")
		EG_LIST.enqueue(dynamic_cast<EG*>(U),dynamic_cast<EG*>(U)->getScore());
	else if (U->getType() == "ET")
		ET_LIST.push(dynamic_cast<ET*>(U));
	else
		return false;
	return true;
}

ES* EarthArmy::pickES()
{
	ES* ESptr = new ES(); 
	if((ES_LIST.isEmpty()))
		ES_LIST.dequeue(ESptr);
	return ESptr;
}

EG* EarthArmy::pickEG()
{
	EG* EGptr = NULL;
	int pri = 1;
	if (!EG_LIST.isEmpty()) {
		EG_LIST.dequeue(EGptr, pri);
	}
	
	return EGptr;
}

ET* EarthArmy::pickET()
{
	ET* ETptr = NULL;
	if (!ET_LIST.isEmpty()) {
		ET_LIST.pop(ETptr);
	}
	return ETptr;
}


void EarthArmy::printEA() {

		Units* U;

		cout << "============== Earth Army Alive Units ==============" << endl;

		cout << ES_LIST.length << " ES [ ";
		ES_LIST.printLQ();

		cout << " ]" << endl;

		////////////////////////////////////////////////////////////////////////

		cout << EG_LIST.length << " EG [ ";
		EG_LIST.printPriQ();

		cout << " ]" << endl;

		////////////////////////////////////////////////////////////////////////

		cout << ET_LIST.getTop() + 1 << " ET [ ";
		ArrayStack<ET*> Temp3;
		ET* t;
		for (int i = 0; i < ET_LIST.getTop() + 1; ++i) {

			ET_LIST.peek(t);

			cout << t->getID() << ', ';

			ET_LIST.pop(t);
			Temp3.push(t);
		}
		cout << " ]" << endl;
		for (int i = 0; i < Temp3.getTop() + 1; ++i) {
			Temp3.peek(t);
			Temp3.pop(t);
			ET_LIST.push(t);
		}
	
}

	/*
	cout << ET_LIST.getTop()+1 << " ET [ ";
	
		for (int i = ET_LIST.getTop() + 1; i >= 0; --i) {
			cout << ET_LIST.getItems()->getID() << " ";
		}

	cout << " ]" << endl;
	*/

//}


EarthArmy::~EarthArmy() {

}