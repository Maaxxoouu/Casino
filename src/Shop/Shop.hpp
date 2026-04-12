#pragma once

#include <vector>
#include <memory>

#include "../Player/Player.hpp"

class Shop {
private:
    int boosterPrice;

    // Méthode qui génère UNE seule carte
    std::shared_ptr<Card> generateRandomCard();

public:
    Shop(int price = 200); // Prix par défaut d'un booster

    void buyAndOpenBooster(Player& player);
};