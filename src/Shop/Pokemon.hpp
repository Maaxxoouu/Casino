#pragma once

#include "Card.hpp"

class PokemonCard : public Card {
private:
    int hp;
    std::string type;

public:
    PokemonCard(std::string n, Rarity r, int p, int h, std::string t) 
        : Card(n, r, p), hp(h), type(t) {}

    void display() override {
        std::cout << "[" << type << "] " << name << " - HP: " << hp 
                  << " (Rarity: " << (int)rarity << ")" << std::endl;
    }
};