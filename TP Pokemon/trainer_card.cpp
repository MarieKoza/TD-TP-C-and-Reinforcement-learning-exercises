#include "headers/trainer_card.h"

#include <iostream>
#include <string>

using namespace std;

TrainerCard::TrainerCard(string name, string effect) : Card(name), trainerEffect(effect) {}

void TrainerCard::displayInfo() {
    cout << "Trainer Card - Name : " << cardName << ", Effect : " << trainerEffect << endl;
}

void TrainerCard::effect() {
    if (trainerEffect.compare("heal all your action pokemon")==0){
        

    }
}