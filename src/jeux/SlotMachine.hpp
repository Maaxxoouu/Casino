
#pragma once

#include "../Player/Player.hpp"
// Creation d'une classe SlotMachine pour eviter de surcharger le main
class SlotMachine{
    public:
        SlotMachine() = default;
        int Play(int, Player&);
        void printResult(int, int, int);
};