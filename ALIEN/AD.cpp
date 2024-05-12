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

    ArrayStack<ET*> Tanks = gm->getEarthArmyptr()->getETList();
    LinkedQueue<ET*> TempETList;

    priQueue <EG*> Gunnery = gm->getEarthArmyptr()->getEGList();
    LinkedQueue <EG*> TempEGList;

 
    int Cap = this->AttackCapacity;
    int oddEven = 0;
    
        //while (Cap != 0) {
        //    if (oddEven % 2) { // Means that number is odd
        //        if (dequeue(ET)){
        //  
        //                cap--;
        //        }

        //    }
        //    else {// mean that number is even

        //        if (dequeue(EG)) {
        //                cap--;
        //        }
        //    }
        //    oddEven++;
        //}
    
}

