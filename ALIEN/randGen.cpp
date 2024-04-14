#include "RandGen.h"

RandGen::RandGen()
{

}
int RandGen::GenRandNum(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    int randnum = dis(gen);
    return randnum;
}
Units* RandGen:: createUnit (int A,int n, int prob, int es, int et, int eg, int as, int ad,
    int am, int B, int minHealth, int maxHealth, int minPower,
    int maxPower, int minAttckCap, int maxAttckCap, int jt) {
    A = GenRandNum(1, 100);
    int idE = GenRandNum(0, 999);
    int idA = GenRandNum(2000, 2999);
    int health =GenRandNum(minHealth, maxHealth);
    int power = GenRandNum(minPower, maxPower);
    int attckCap = GenRandNum(minAttckCap, maxAttckCap);
    if (A <= prob) {
            B = GenRandNum(1, 100);
            if (es + et + eg > 0) {
                if (B < es) {
                    ES * eS =new ES(idE, "ES", jt, health, power, attckCap);
                    return eS ;
                }
                else if (B < es + et) {
                    ET(idE, "ET", jt, health, power, attckCap);
                    return;
                }
                else {
                    EG(idE, "EG", jt, health, power, attckCap);
                    return;
                }
            }
            else {

                if (B < as) {
                    AS(idA, "AS", jt, health, power, attckCap);
                    return;
                }
                else if (B < as + ad) {
                    AD(idA, "AD", jt, health, power, attckCap);
                    return;
                }
                else {
                    AM(idA, "AM", jt, health, power, attckCap);
                    return;
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



