#include "Player.hpp"

Player::Player(std::string n){
    name = n;
    balance = 1000;
}

std::string Player::getName(){
    return name;
}

int Player::getBal(){
    return balance;
}

void Player::setBal(int newBal){
    balance = newBal;
}

