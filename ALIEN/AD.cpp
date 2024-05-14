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

    //int Cap = this->AttackCapacity; // Total AD Attack Capacity

    AD* front;
    AD* rear{};
    gm->getAlienArmyptr()->getADList().dequeue(front);
    gm->getAlienArmyptr()->getADList().backdequeue(*rear);

    int Cap1 = front->getAttackCapacity(); //Attack Capacity of Drone 1
    int Cap2 = rear->getAttackCapacity(); //Attack Capacity of Drone 2
    int TCap = Cap1 + Cap2; // Total Capacity of 2 Drones 
    int oddEven = 0;

    while (TCap != 0) {

        if (oddEven % 2 != 0) {
            ET* et;
            if (gm->getEarthArmyptr()->getETList().pop(et)) {

                double damage = (getHealth() * getPower() / 100) / sqrt(et->getHealth());

                et->setHealth(et->getHealth()-damage);

                if (et->getHealth() - damage <= 0) {
                    gm->KilledListfunc(et);
                }

                else {
                    TempETList.push(et);
                }
                TCap--;
            } //end if attack

        } //end if odd

        else {// mean that number is even
            priNode<EG*>* CurrEG = Gunnery.getHead();
            EG* eg = nullptr;
            int s = eg->getScore();
            if (gm->getEarthArmyptr()->getEGList().dequeue(eg, s)) {

                double damage = (getHealth() * getPower() / 100) / sqrt(CurrEG->getItem(s)->getHealth());

                eg->setHealth(eg->getHealth()-damage);

                if (eg->getHealth() - damage <= 0) {
                    gm->KilledListfunc(CurrEG->getItem(s));
                }

                else {
                    TempEGList.enqueue(CurrEG->getItem(s), s);
                }
                TCap--;
            }

        }

        oddEven++;
    } //end while

    while (!(TempEGList.isEmpty())) {
        EG* EG = nullptr;
        int S = EG->getScore();
        TempEGList.dequeue(EG, S);
        Gunnery.enqueue(EG, S);
    }

    while (!(TempETList.isEmpty())) {
        ET* ET{};
        if (ET->getHealth() > 0 && ET->getHealth() < 20) {
            TempETList.pop(ET);
            gm->getEarthArmyptr()->addtoET_UML(ET);
        }
        // ❤
        else {
            TempETList.pop(ET);
            Tanks.push(ET);
        }
    }
}
