#include "RandGen.h"
#include "Game.h"

RandGen::RandGen(Game* p)
{
	gameptr = p;
	IDA = 2000;
	IDE = 1;
}
void RandGen::createUnit() {
	int jt = gameptr->getTime();
	int A = rand() % (100 - 1 + 1) + 1;
	if (A <= Prob) {
		int healthE = rand() % (maxHE - minHE + 1) + minHE;
		int powerE = rand() % (maxPE - minPE + 1) + minPE;
		int attckCapE = rand() % (maxCE - minCE + 1) + minCE;
		int healthA = rand() % (maxHA - minHA + 1) + minHA;
		int powerA = rand() % (maxPA - minPA + 1) + minPA;
		int attckCapA = rand() % (maxCA - minCA + 1) + minCA;

		for (int i = 0; i <= N; i++) {

			int B = rand() % (100 - 1 + 1) + 1;
			if (B <= eS) {
				ES* es1 = new ES(IDE, "ES", jt, healthE, powerE, attckCapE);
				IDE++;
				gameptr->getEarthArmyptr()->addUnit(es1);
			}
			else if (B <= eS + eT) {
				ET* et1 = new ET(IDE, "ET", jt, healthE, powerE, attckCapE);
				IDE++;
				gameptr->getEarthArmyptr()->addUnit(et1);
			}
			else if (B <= eS + eT + eG) {
				EG* eg1 = new EG(IDE, "EG", jt, healthE, powerE, attckCapE);
				IDE++;
				gameptr->getEarthArmyptr()->addUnit(eg1);
			}
			else if (B <= eS + eT + eG + HU_PER) {
				HealUnit* HU = new HealUnit(IDE, "HU", jt, healthE, powerE, attckCapE);
				IDE++;
				gameptr->getEarthArmyptr()->addUnit(HU);
			}


			if (B < aS) {
				AS* as1 = new AS(IDA, "AS", jt, healthA, powerA, attckCapA);
				IDA++;
				gameptr->getAlienArmyptr()->addUnit(as1);
			}
			else if (B < aS + aD) {
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

int RandGen::getN() {
	return N;
}
int RandGen::getProb() {
	return Prob;
}
int RandGen::getES() {
	return eS;
}
int RandGen::getET() {
	return eT;
}
int RandGen::getEG() {
	return eG;
}
int RandGen::getAS() {
	return aS;
}
int RandGen::getAM() {
	return aM;
}
int RandGen::getAD() {
	return aD;
}

//Getters of Earth Power, Health & Attcak Capacity
int RandGen::getminPE() {
	return minPE;
}
int RandGen::getmaxPE() {
	return maxPE;
}
int RandGen::getminHE() {
	return minHE;
}
int RandGen::getmaxHE() {
	return maxHE;
}
int RandGen::getminCE() {
	return minCE;
}
int RandGen::getmaxCE() {
	return maxCE;
}

//Getters of Aliens Power, Health & Attcak Capacity
int RandGen::getminPA() {
	return minPA;
}
int RandGen::getmaxPA() {
	return maxPA;
}
int RandGen::getminCA() {
	return minCA;
}
int RandGen::getmaxCA() {
	return maxCA;
}
int RandGen::getminHA() {
	return minHA;
}
int RandGen::getmaxHA() {
	return maxHA;
}

void RandGen::setHU_PER(int hu) {
	HU_PER = hu;
}
int RandGen::getHU_PER() {
	return HU_PER;
}
