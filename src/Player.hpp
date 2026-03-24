
#pragma Once

#include <iostream>

class Player{
    public:
        Player(std::string n);
        std::string name;
        double balance;
        void addMoney();
        void betMoney();
};