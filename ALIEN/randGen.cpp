#include "RandGen.h"
RandGen::RandGen()
{

}
Units* createUnit(int n, int prob, int es, int et, int eg, int as, int ad,
    int am, int B, int minHealth, int maxHealth, int minPower,
    int maxPower, int minAttckCap, int maxAttckCap, int jt) {
    RandGen rand;
    int id = rand.GenRandNum(0, 999);
    int health = rand.GenRandNum(minHealth, maxHealth);
    int power = rand.GenRandNum(minPower, maxPower);
    int attckCap = rand.GenRandNum(minAttckCap, maxAttckCap);

    if (es + et + eg > 0) {
        if (B < es) {
            return new ES(id, "ES", jt, health, power, attckCap);
        }
        else if (B < es + et) {
            return new ET(id, "ET", jt, health, power, attckCap);
        }
        else {
            return new EG(id, "EG", jt, health, power, attckCap);
        }
    }
    else {
        if (B < as) {
            return new AS(id, "AS", jt, health, power, attckCap);
        }
        else if (B < as + ad) {
            return new AD(id, "AD", jt, health, power, attckCap);
        }
        else {
            return new AM(id, "AM", jt, health, power, attckCap);
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

