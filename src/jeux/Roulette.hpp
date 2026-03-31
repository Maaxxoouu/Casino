
#pragma once

#include "Games.hpp"

class Roulette : public Games{
    public:
        Roulette(int balance);
        int Play() override;
};