#include "headers/pokemon_card.h"

#include <iostream>
#include <string>

using namespace std;

PokemonCard::PokemonCard(string name, string type, string family, int evolution, int hp, int costEnergy, string attackDescription, int attackDamage,int costEnergy2, string attackDescription2, int attackDamage2) : 
Card(name), pokemonType(type), familyName(family),evolutionLevel(evolution), hp(hp), maxHP(hp), stockEnergy(0) {
    this -> attacks.push_back(make_tuple(costEnergy, attackDescription, attackDamage));
    this -> attacks.push_back(make_tuple(costEnergy2, attackDescription2, attackDamage2));
}

void PokemonCard::attachEnergyCard(int indexEnergy) {
    if (stockEnergy < 4) {
        stockEnergy++;
    } else {
        cout << "Maximum energy reached" << endl;
    }
}

void PokemonCard::displayInfo() {
    cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType << ", Evolution Level: " << evolutionLevel << " of the family " << familyName << ", HP: " << hp << endl;
}