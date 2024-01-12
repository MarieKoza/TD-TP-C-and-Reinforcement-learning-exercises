#include "headers/player.h"

#include <iostream>
#include <string>

using namespace std;

Player::Player(string name) : playerName(name) {}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {
    actionCards.push_back((PokemonCard*) benchCards[index]);
    benchCards.erase(benchCards.begin() + index);
    cout << playerName << " is activating a Pokemon Card: " << benchCards[index]->cardName << endl;
}

void Player::displayBench() {
    cout << "Bench Cards for Player " << playerName << ":" << endl;
    for (int i = 0; i < benchCards.size(); i++) {
        benchCards[i]->displayInfo();
    }
}

void Player::displayAction() {
    cout << "Action Cards for Player  " << playerName <<":"<< endl;
    for (int i = 0; i < actionCards.size(); i++) {
        actionCards[i]->displayInfo();
    }
}

void Player::attachEnergyCard(int indexEnergy, int indexPokemon) {
    actionCards[indexPokemon]->attachEnergyCard(indexEnergy); 
    cout << playerName << " is attaching an Energy Card of type " << ((EnergyCard*) benchCards[indexEnergy])->energyType << " to the Pokemon " << actionCards[indexPokemon]->cardName << endl;
    benchCards.erase(benchCards.begin() + indexEnergy);
}

void Player::attack(int pokemonIndex, int attackIndex, Player &opponent, int opponentPokemonIndex){
    PokemonCard pokemonAttack = *actionCards[pokemonIndex];
    //cout << (get<0>(pokemonAttack.attacks[attackIndex])) - pokemonAttack.stockEnergy <<endl;
    if ((get<0>(pokemonAttack.attacks[attackIndex])) - pokemonAttack.stockEnergy >= 0){
        PokemonCard *opponentPokemon = opponent.actionCards[opponentPokemonIndex];
        int damage = get<2>(pokemonAttack.attacks[attackIndex]);
        opponentPokemon->hp -= damage;
        //output expected : Hadi attacking Germain’s Pokemon Bulbasaur with the Pokemon Pikachu with its attack: thunderbolt
        cout << playerName << " attacking " << opponent.playerName << "'s Pokemon " << opponentPokemon->cardName << " with the Pokemon " << pokemonAttack.cardName << " with its attack: " << get<1>(pokemonAttack.attacks[attackIndex]) << endl;
        cout << "Reducing " << damage << " from " << opponent.playerName << "'s Pokemon HP" << endl;
        if (opponentPokemon->hp <= 0) {
            opponent.actionCards.erase(opponent.actionCards.begin() + opponentPokemonIndex);
            cout << opponent.playerName << "'s Pokemon " << opponentPokemon->cardName << " has fainted" << endl;
        }
        else {
            cout << "Pokemon " << opponentPokemon->cardName << " is still alive " << endl;
        }
    }
    else {
        cout << "Not enough energy" << endl;
    }
}

void Player::useTrainer(int index) {
    TrainerCard* trainer = dynamic_cast <TrainerCard*> (benchCards[1]);
    //heal all your action pokemon
    if (trainer->trainerEffect.compare("heal all your action pokemon")==0){
        cout << playerName << " is using the Trainer Card to " << trainer->trainerEffect << endl;
        for (int i = 0; i < actionCards.size(); i++) {
            actionCards[i]->hp = actionCards[i]->maxHP;
        }
    }
}

void Player::displayInfo() {
    cout << "Player Name: " << playerName << endl;
}