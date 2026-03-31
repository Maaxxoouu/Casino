#include "Player.hpp"

Player::Player(std::string n){
    name = n;
    balance = 1000;
}

std::string Player::getName(){
    return name;
}

double Player::getBal(){
    return balance;
}

void Player::setBal(double newBal){
    balance = newBal;
}

