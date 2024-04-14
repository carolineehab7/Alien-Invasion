#include "RandGen.h"

RandGen::RandGen()
{
    ida =2000;
    ide = 1;
}
Units* RandGen::createUnit(int A, int n, int prob, int es, int et, int eg, int as, int ad,
    int am, int B, int minHealth, int maxHealth, int minPower,
    int maxPower, int minAttckCap, int maxAttckCap, int jt) {
    if (ide < 999 && ida < 2999) {
        for (int i = 0; i <= n; i++) {
            int A = rand() % (100 - 1 + 1) + 1;
            int health = rand() % (maxHealth - minHealth + 1) + minHealth;
            int power = rand() % (maxPower - minPower + 1) + minPower;
            int attckCap = rand() % (maxAttckCap - minAttckCap + 1) + minAttckCap;
            if (A <= prob) {
                int B = rand() % (100 - 1 + 1) + 1;
                if (es + et + eg > 0) {

                    if (B < es) {
                        ES* es1 = new ES(ide, "ES", jt, health, power, attckCap);
                        ide++;
                        return es1;
                    }
                    else if (B < es + et) {
                        ET* et1 = new ET(ide, "ET", jt, health, power, attckCap);
                        ide++;
                        return et1;
                    }
                    else {
                        EG* eg1 = new EG(ide, "EG", jt, health, power, attckCap);
                        ide++;
                        return eg1;
                    }
                }
                else {

                    if (B < as) {
                        AS* as1 = new AS(ida, "AS", jt, health, power, attckCap);
                        ida++;
                        return as1;
                    }
                    else if (B < as + ad) {
                        AD* ad1 = new AD(ida, "AD", jt, health, power, attckCap);
                        ida++;
                        return ad1;
                    }
                    else {
                        AM* am1 = new AM(ida, "AM", jt, health, power, attckCap);
                        ida++;
                        return am1;
                    }
                }
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



