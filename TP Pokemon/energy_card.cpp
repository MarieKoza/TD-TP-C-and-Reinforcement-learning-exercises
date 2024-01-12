#include "headers/energy_card.h"

#include <iostream>
#include <string>

using namespace std;

EnergyCard::EnergyCard(string type) : Card("Energy"), energyType(type) {}

void EnergyCard::displayInfo() {
    cout << "Card Name: " << cardName << endl;
    cout << "Energy Type: " << energyType << endl;
}