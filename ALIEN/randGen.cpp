#include "RandGen.h"
RandGen::RandGen()
{

}
Units* createUnit(int n, int prob, int es, int et, int eg, int as, int ad,
    int am, int B, int minHealth, int maxHealth, int minPower,
    int maxPower, int minAttckCap, int maxAttckCap, int jt) {
    RandGen rand;
    int A = rand.GenRandNum(1, 100);
    int id = rand.GenRandNum(0, 999);
    int health = rand.GenRandNum(minHealth, maxHealth);
    int power = rand.GenRandNum(minPower, maxPower);
    int attckCap = rand.GenRandNum(minAttckCap, maxAttckCap);
    if (A <= prob) {
        for (int i = 0; i <= n; i++) {
            int B = rand.GenRandNum(1, 100);
            if (B <= es) {

            }
            else if (B <= (es + et)) {

            }
            //generate EG
            else {              

            }

            if (B <= as) {

            }
            else if (B <= (as + am)) {

            }
            //generate AD
            else {                 

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
    ES = es;
}
void RandGen::setET(int et) {
    ET = et;
}
void RandGen::setEG(int eg) {
    EG = eg;
}
void RandGen::setAS(int as) {
    AS = as;
}
void RandGen::setAM(int am) {
    AM = am;
}
void RandGen::setAD(int ad) {
    AD = ad;
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

int RandGen::GenRandNum(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    int randnum = dis(gen);
    return randnum;
}

