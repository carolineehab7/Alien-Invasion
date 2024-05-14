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

    if ((gm->getEarthArmyptr()->getETList().isEmpty() && gm->getEarthArmyptr()->getEGList().isEmpty()))
        return;

    if(gm->getMode()=='I')
    cout << "AD Attacker " << this->ID << " [";

    while (Cap != 0) {

        if (gm->getEarthArmyptr()->getETList().isEmpty() && gm->getEarthArmyptr()->getEGList().isEmpty())
            break;

        if (oddEven % 2 != 0) {
            ET* et;
            if (gm->getEarthArmyptr()->getETList().pop(et)) {

                if (gm->getMode() == 'I')
                cout << et->getID();

                double damage = (getHealth() * getPower() / 100) / sqrt(et->getHealth());

                et->setHealth(et->getHealth()-damage);

                if (et->getHealth() - damage <= 0) {
                    gm->KilledListfunc(et);
                }

                else {
                    TempETList.push(et);
                }
                Cap--;
            } //end if attack

        } //end if odd

        else {// mean that number is even
            priNode<EG*>* CurrEG = Gunnery.getHead();
            EG* eg = nullptr;
            int s = eg->getScore();
            if (gm->getEarthArmyptr()->getEGList().dequeue(eg, s)) {

                if (gm->getMode() == 'I')
                cout << eg->getID()<<", ";

                double damage = (getHealth() * getPower() / 100) / sqrt(CurrEG->getItem(s)->getHealth());

                eg->setHealth(eg->getHealth()-damage);

                if (eg->getHealth() - damage <= 0) {
                    gm->KilledListfunc(CurrEG->getItem(s));
                }

                else {
                    TempEGList.enqueue(CurrEG->getItem(s), s);
                }
                Cap--;
            }

        }
        if (gm->getMode() == 'I')
        cout << "\b\b" << "]";
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
            gm->addtoET_UML(ET);
        }
        // ❤ 
        else {
            TempETList.pop(ET);
            Tanks.push(ET);
        }
    }
}

//void AD::operator=(AD& ad)
//{
//    this->AttackCapacity = ad.AttackCapacity;
//    this->ID = ad.ID;
//    this->Health = ad.Health;
//    this->Power = ad.Power;
//}
