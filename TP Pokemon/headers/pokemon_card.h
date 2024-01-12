#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "card.h"

using namespace std;

class PokemonCard : public Card{
    public :
        PokemonCard(string name, string type, string family, int evolution, int hp, int costEnergy, string attackDescription, int attackDamage, int costEnergy2, string attackDescription2, int attackDamage2);
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        int stockEnergy;
        vector<tuple<int, string, int> > attacks;
        void displayInfo();

        void attachEnergyCard(int indexEnergy);
        
};

#endif

/*int costEnergy;
        int costEnergyactual;
        string attackDescription;
        int attackDamage;
        */