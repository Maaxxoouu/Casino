#pragma once
#include <string>
#include <iostream>

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
    Rarity getRarity() { return rarity; }
};