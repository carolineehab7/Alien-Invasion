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

bool EarthArmy::addUnit(Units* U) {

	if (U->getType() == "ES")
		ES_LIST.enqueue(dynamic_cast<ES*>(U));
	else if (U->getType() == "EG")
		EG_LIST.enqueue(dynamic_cast<EG*>(U));
	else if (U->getType() == "ET")
		ET_LIST.push(dynamic_cast<ET*>(U));

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
