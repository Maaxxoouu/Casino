
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <unistd.h>
#include <random>

class Player{
    public:
        Player();
        std::string name;
        std::string getName();
        int getBal();
        void setBal(int);

        void save(const std::string& filename);
        bool load(const std::string& filename);

        bool hasWonSlotMachine;
        bool hasWonGuessNumber;
        bool hasWonRoulette;
    
        // Inventory inventaire; // pour la collection de cartes

    private:
        int balance;
};