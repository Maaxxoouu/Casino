
#pragma once

#include "Games.hpp"
// Creation d'une classe GuessNumber pour eviter de surcharger le main
class GuessNumber : public Games{
    public:
        GuessNumber(int balance);
        int Play() override;
};