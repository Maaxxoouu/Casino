#pragma once

#include "Card.hpp"

class PokemonCard : public Card {
private:
    int hp;
    int atk;
    std::string type;

public:
    PokemonCard(std::string n, Rarity r, int p, int h, int a, std::string t) 
        : Card(n, r, p), hp(h), atk(a), type(t) {}

    void display() override {
        std::cout << "[" << type << "] " << name << " - HP: " << hp << " - ATK: " << atk
                  << " (Rarete: " << getRarityString() << ")" << std::endl;
    }
};