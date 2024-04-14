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

class RandGen
{
private:
	Game* gameptr;
	int N, Prob;
	int ES, ET, EG;
	int AS, AM, AD;
	int maxPE, minPE;
	int maxHE, minHE;
	int maxCE, minCE;
	int maxPA, minPA;
	int maxHA, minHA;
	int maxCA, minCA;

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
	

	Units* createUnit(int A, int n, int prob, int es, int et, int eg, int as, int ad,
		int am, int B, int minHealth, int maxHealth, int minPower,
		int maxPower, int minAttckCap, int maxAttckCap, int jt);
	int GenRandNum(int min, int max);
	
};

