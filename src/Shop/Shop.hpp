#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <random>
#include <unistd.h>

#include "../Player/Player.hpp"
#include "PokemonCard.hpp"
#include "CardFactory.hpp"

class Shop {
private:
    int boosterPrice;
    int NbOfCardPerBooster;

public:
    Shop(int price = 200); // Prix par défaut d'un booster

    int buyAndOpenBooster(Player& player);
};