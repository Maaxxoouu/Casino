
#pragma once

#include "../Player/Player.hpp"
// Creation d'une classe Roulette pour eviter de surcharger le main
class Roulette{
    public:
        Roulette() = default;
        int Play(int, Player&);
};