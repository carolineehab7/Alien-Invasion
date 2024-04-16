#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include "Game.h"
#include "Units.h"
#include"ES.h"
#include"EG.h"
#include"ET.h"
#include"AS.h"
#include"AD.h"
#include"AM.h"
class Game;

class RandGen
{
private:
	Game* gameptr;
	int N, Prob;
	int eS, eT, eG;
	int aS, aM, aD;
	int maxPE, minPE;
	int maxHE, minHE;
	int maxCE, minCE;
	int maxPA, minPA;
	int maxHA, minHA;
	int maxCA, minCA;
	int IDE, IDA;
public:
	RandGen();
	void setN(int n);
	void setProb(int p);
	void setES(int es);
	void setET(int et);
	void setEG(int eg);
	void setAS(int as);
	void setAM(int am);
	void setAD(int ad);

	void setminPE(int min_pe);
	void setmaxPE(int max_pe);
	void setminHE(int min_he);
	void setmaxHE(int max_he);
	void setminCE(int min_ce);
	void setmaxCE(int max_ce);

	void setminPA(int min_pa);
	void setmaxPA(int max_pa);
	void setminHA(int min_ha);
	void setmaxHA(int max_ha);
	void setminCA(int min_ca);
	void setmaxCA(int max_ca);

	int getN();
	int getProb();
	int getES();
	int getET();
	int getEG();
	int getAS();
	int getAM();
	int getAD();

	int getminPE();
	int getmaxPE();
	int getminHE();
	int getmaxHE();
	int getminCE();
	int getmaxCE();

	int getminPA();
	int getmaxPA();
	int getminHA();
	int getmaxHA();
	int getminCA();
	int getmaxCA();


	Units* createUnit(int n, int prob, int jt, int es, int et, int eg, int as, int ad,
		int am, int minHealthE, int maxHealthE, int minPowerE, int maxPowerE, int minAttckCapE, int maxAttckCapE,
		int minHealthA, int maxHealthA, int minPowerA, int maxPowerA, int minAttckCapA, int maxAttckCapA);


};

