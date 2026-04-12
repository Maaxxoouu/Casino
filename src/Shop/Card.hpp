#pragma once
#include <string>
#include <iostream>

// Création d'une classe mère pour les cartes si plus tard on souhaite ajouter différents types de cartes
// (En plus de pokemon, on pourrait avoir d'autres TCG, comme Yu-Gi-Oh, One Piece, Magic, etc..)

enum class Rarity { COMMON, RARE, EPIC, LEGENDARY };

class Card {
    protected:
        std::string name;
        Rarity rarity;
        int price;

    public:
    Card(std::string n, Rarity r, int p) : name(n), rarity(r), price(p) {}
    virtual ~Card() = default;

    virtual void display() = 0;
    
    std::string getName() { return name; }
    int getPrice() { return price; }
    //Rarity getRarity() { return rarity; }
    std::string getRarityString() const {
        switch(rarity) {
            case Rarity::COMMON: return "COMMUNE";
            case Rarity::RARE: return "RARE";
            case Rarity::EPIC: return "EPIQUE";
            case Rarity::LEGENDARY: return "LEGENDAIRE";
            default: return "INCONNU";
        }
    }
};