
#pragma once

#include "Games.hpp"

class GuessNumber : public Games{
    public:
        GuessNumber(int balance);
        int Play() override;
};