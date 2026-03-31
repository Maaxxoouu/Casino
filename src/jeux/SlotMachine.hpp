
#pragma once

#include "Games.hpp"
// Creation d'une classe SlotMachine pour eviter de surcharger le main
class SlotMachine : public Games{
    public:
        SlotMachine(int balance);
        int Play() override;
};