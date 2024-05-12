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

	~Units();
};

//ostream& operator<<(ostream& op, Units* uni) {
//		op << uni->getID();
//		return op;
//	}

