#pragma once
#include <iostream>
#include <string>
using namespace std;
class Game;

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
	bool attck;
public:
	Game* gm;
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
	void setDf();
	void setDd();
	void setDb();
	void setUAP(int);
	int getTa();
	int getTd();
	int getDf();
	int getDd();
	int getDb();
	int getUAP();
	int getattck() ;
	void setattck() ;
	~Units();
};

//ostream& operator<<(ostream& op, Units* uni) {
	//	op << uni->getID();
	//	return op;
	//}