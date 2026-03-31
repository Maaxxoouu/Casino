
#pragma once

#include <iostream>

class Player{
    public:
        Player(std::string n);
        std::string name;
        std::string getName();
        int getBal();
        void setBal(int);
    
        // Inventory inventaire; // pour la collection de cartes

    private:
        int balance;
};