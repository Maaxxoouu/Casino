
#pragma once

#include "Games.hpp"
// Creation d'une classe Roulette pour eviter de surcharger le main
class Roulette : public Games{
    public:
        Roulette(int balance);
        int Play() override;
};