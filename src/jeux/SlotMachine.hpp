
#pragma once

#include "Games.hpp"

class SlotMachine : public Games{
    public:
        SlotMachine(int balance);
        int Play() override;
    
    /*private:
        int bal;*/
};