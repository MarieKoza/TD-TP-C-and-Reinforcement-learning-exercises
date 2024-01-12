#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "pokemon_card.h"
#include "energy_card.h"
#include "trainer_card.h"

using namespace std;

class Player {
    public :
        Player(string name);
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;
        void addCardToBench(Card* card);
        void activatePokemonCard(int index);
        void displayBench();
        void displayAction();
        void attachEnergyCard(int indexEnergy, int indexPokemon); 
        void attack(int pokemonIndex, int attackIndex, Player &opponent, int opponentPokemonIndex);
        void useTrainer(int index);
        void displayInfo();

};

#endif