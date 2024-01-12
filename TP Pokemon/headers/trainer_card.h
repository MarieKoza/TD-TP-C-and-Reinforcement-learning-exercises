#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

class TrainerCard : public Card{
    public :
        TrainerCard(string name, string trainerEffect);
        string trainerEffect;
        void displayInfo();
        void effect();
};


#endif