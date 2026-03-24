
#pragma Once

#include <iostream>

class Player{
    public:
        Player(std::string n);
        std::string name;
        double balance;
        void actualiserBalance(double bal);

        // Inventory inventaire; // pour la collection de cartes
};