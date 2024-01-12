#include "headers/card.h"

#include <iostream>
#include <string>

using namespace std;

Card::Card(string name) : cardName(name) {}

void Card::displayInfo() {
    cout << "Card Name: " << cardName << endl;
}