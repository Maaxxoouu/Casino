
#pragma once

#include "../Player/Player.hpp"
// Creation d'une classe GuessNumber pour eviter de surcharger le main
class GuessNumber{
    public:
        GuessNumber() = default;
        int Play(int, Player&);
};