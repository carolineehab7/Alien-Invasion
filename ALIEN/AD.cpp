#include "AD.h"
#include<string>
using namespace std;
#include"Game.h"

AD::AD() {

}
AD::AD(int id, string type, int jt, int health, int power, int AC) :Units(id, type, jt, health, power, AC) {

}

void AD::attack()
{

    if (gm->getAlienArmyptr()->getADList().length < 2) {
        return;
    }

    ArrayStack<ET*> Tanks = gm->getEarthArmyptr()->getETList();
    ArrayStack<ET*> TempETList;

    priQueue <EG*> Gunnery = gm->getEarthArmyptr()->getEGList();
    priQueue <EG*> TempEGList;


    int Cap = this->AttackCapacity;
    int oddEven = 0;

    while (Cap != 0) {

        AD* front = new AD();
        AD* rear = new AD();
        gm->getAlienArmyptr()->getADList().dequeue(front);
        gm->getAlienArmyptr()->getADList().backdequeue(*rear);

        if (oddEven % 2 != 0) { // Means that number is odd
            ET* et;
            if (gm->getEarthArmyptr()->getETList().pop(et)) {

                double damage = (getHealth() * getPower() / 100) / sqrt(et->getHealth());

                if (getHealth() - damage <= 0) {
                    gm->KilledListfunc(et);
                }

                else {
                    TempETList.push(et);
                }
                Cap--;
            }

        }

        else {// mean that number is even
            priNode<EG*>* CurrEG = Gunnery.getHead();
            EG* eg = nullptr;
            int s = eg->getScore();
            if (gm->getEarthArmyptr()->getEGList().dequeue(eg, s)) {

                double damage = (getHealth() * getPower() / 100) / sqrt(CurrEG->getItem(s)->getHealth());

                if (getHealth() - damage <= 0) {
                    gm->KilledListfunc(CurrEG->getItem(s));
                }

                else {
                    TempEGList.enqueue(CurrEG->getItem(s), s);
                }
                Cap--;
            }

        }
        oddEven++;
    }

    while (!(TempEGList.isEmpty())) {
        EG* EG = nullptr;
        int S = EG->getScore();
        TempEGList.dequeue(EG, S);
        Gunnery.enqueue(EG, S);
    }

    while (!(TempETList.isEmpty())) {
        ET* ET;
        TempETList.pop(ET);
        Tanks.push(ET);
    }
}
