#include "RandGen.h"
#include "Game.h"

RandGen::RandGen()
{
	IDA = 2000;
	IDE = 1;
}
Units* RandGen::createUnit(int A, int n, int prob, int B, int jt, int es, int et, int eg, int as, int ad,
	int am, int minHealthE, int maxHealthE, int minPowerE, int maxPowerE, int minAttckCapE, int maxAttckCapE,
	int minHealthA, int maxHealthA, int minPowerA, int maxPowerA, int minAttckCapA, int maxAttckCapA) {
	int A = rand() % (100 - 1 + 1) + 1;
	if (A <= prob) {
		int healthE = rand() % (maxHealthE - minHealthE + 1) + minHealthE;
		int powerE = rand() % (maxPowerE - minPowerE + 1) + minPowerE;
		int attckCapE = rand() % (maxAttckCapE - minAttckCapE + 1) + minAttckCapE;
		int healthA = rand() % (maxHealthA - minHealthA + 1) + minHealthA;
		int powerA = rand() % (maxPowerA - minPowerA + 1) + minPowerA;
		int attckCapA = rand() % (maxAttckCapA - minAttckCapA + 1) + minAttckCapA;
		for (int i = 0; i <= n; i++) {
			int B = rand() % (100 - 1 + 1) + 1;
			if (B < es) {
				ES* es1 = new ES(IDE, "ES",jt, healthE, powerE, attckCapE);
				IDE++;
				gameptr->getEarthArmyptr()->addUnit(es1);
			}
			else if (B < es + et) {
				ET* et1 = new ET(IDE, "ET", jt, healthE, powerE, attckCapE);
				IDE++;
				gameptr->getEarthArmyptr()->addUnit(et1);
			}
			else {
				EG* eg1 = new EG(IDE, "EG", jt, healthE, powerE, attckCapE);
				IDE++;
				gameptr->getEarthArmyptr()->addUnit(eg1);
			}

			if (B < as) {
				AS* as1 = new AS(IDA, "AS", jt, healthA, powerA, attckCapA);
				IDA++;
				gameptr->getAlienArmyptr()->addUnit(as1);
			}
			else if (B < as + ad) {
				AD* ad1 = new AD(IDA, "AD", jt, healthA, powerA, attckCapA);
				IDA++;
				gameptr->getAlienArmyptr()->addUnit(ad1);
			}
			else {
				AM* am1 = new AM(IDA, "AM", jt, healthA, powerA, attckCapA);
				IDA++;
				gameptr->getAlienArmyptr()->addUnit(am1);
			}

		}
	}

}




void RandGen::setN(int n) {
	N = n;
}
void RandGen::setProb(int p) {
	Prob = p;
}
void RandGen::setES(int es) {
	eS = es;
}
void RandGen::setET(int et) {
	eT = et;
}
void RandGen::setEG(int eg) {
	eG = eg;
}
void RandGen::setAS(int as) {
	aS = as;
}
void RandGen::setAM(int am) {
	aM = am;
}
void RandGen::setAD(int ad) {
	aD = ad;
}

//Setters of Earth Power, Health & Attcak Capacity
void RandGen::setminPE(int min_pe) {
	minPE = min_pe;
}
void RandGen::setmaxPE(int max_pe) {
	maxPE = max_pe;
}
void RandGen::setminHE(int min_he) {
	minHE = min_he;
}
void RandGen::setmaxHE(int max_he) {
	maxHE = max_he;
}
void RandGen::setminCE(int min_ce) {
	minCE = min_ce;
}
void RandGen::setmaxCE(int max_ce) {
	maxCE = max_ce;
}

//Setters of Aliens Power, Health & Attcak Capacity
void RandGen::setminPA(int min_pa) {
	minPA = min_pa;
}
void RandGen::setmaxPA(int max_pa) {
	maxPA = max_pa;
}
void RandGen::setminCA(int min_ca) {
	minCA = min_ca;
}
void RandGen::setmaxCA(int max_ca) {
	maxCA = max_ca;
}
void RandGen::setminHA(int min_ha) {
	minHA = min_ha;
}
void RandGen::setmaxHA(int max_ha) {
	maxHA = max_ha;
}



