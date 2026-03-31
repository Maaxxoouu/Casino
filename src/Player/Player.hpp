
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Player{
    public:
        Player();
        std::string name;
        std::string getName();
        int getBal();
        void setBal(int);

        void save(const std::string& filename);
        bool load(const std::string& filename);
    
        // Inventory inventaire; // pour la collection de cartes

    private:
        int balance;
};