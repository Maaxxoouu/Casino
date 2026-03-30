#include "Player.hpp"

Player::Player(std::string n){
    name = n;
    balance = 1000;
}

void Player::actualiserBalance(double bal){
    balance = bal;
}