#pragma once
#include <iostream>
using namespace std;

class Units
{	
protected:
	int ID;
	string Type;
	int JoinTime;
	int Health;
	int Power;
	int AttackCapacity;
	int Ta;		//(First Attacked Time)
	int Td;		//(Destruction Time)
	int Df;		//(First Attack Delay)
	int Dd;		//(Destruction Delay)
	int Db;		//(Battle Time)
	int UAP;	//Unit Attack Power
	
public:
	Units();
	Units(int id, string type,int JT, int health, int power, int AC);
	void setID(int);
	void setType(string);
	void setJoinTime(int);
	void setHealth(int);
	void setPower(int);
	void setAttackCapacity(int);
	int getID();
	string getType();
	int getJoinTime();
	int getHealth();
	int getPower();
	int getAttackCapacity();
	virtual void attack() = 0;
	void setTa(int);
	void setTd(int);
	void setDf(int);
	void setDd(int);
	void setDb(int);
	void setUAP(int);
	int getTa();
	int getTd();
	int getDf();
	int getDd();
	int getDb();
	int getUAP();

	~Units();
};

//ostream& operator<<(ostream& op, Units* uni) {
	//	op << uni->getID();
	//	return op;
	//}