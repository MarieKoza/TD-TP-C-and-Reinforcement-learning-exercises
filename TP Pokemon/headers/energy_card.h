#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

class EnergyCard : public Card{
    public :
        EnergyCard(string energyType);
        string energyType; 
        void displayInfo();
};


#endif