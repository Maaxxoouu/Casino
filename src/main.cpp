#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <algorithm> //pour std::find
#include <iterator> //pour std::begin, std::end

#include "jeux/SlotMachine.hpp"
#include "Player.hpp"

int main(int argc, char *argv[]) {

    std::cout<<"Quel est votre nom ?"<<std::endl;
    std::cout<<" "<<std::endl;
    std::string n;
    std::cin>>n;
    Player joueur = Player(n);
    std::cout<<"*************** BIENVENUE AU CASINO "<<joueur.name<<"! ***************"<<std::endl;
    std::cout<<" "<<std::endl;
    

    int jouer = 1;

    while(jouer){
        std::cout<<"Vous avez actuellement "<<joueur.balance<<" euros"<<std::endl;
        std::cout<<"A quoi voulez-vous jouer ?"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"0. Sortir du Casino"<<std::endl;
        std::cout<<"1. [7.7.7] Slot Machine"<<std::endl;
        std::cout<<"2. Deviner le chiffre entre 1 et 5"<<std::endl;
        std::cout<<"3. Roulette"<<std::endl;
        std::cout<<"4. Achat de boosters Pokemon"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"Veuillez entrer [0], [1], [2], [3] ou [4]"<<std::endl;

        int a,b;
        std::cin>>a;
        std::cout<<a<<std::endl;
        if (a == 0){
            jouer = 0;  
        /*}else if (a == 1){
            SlotMachine Jeu1 = SlotMachine(balance);
            balance = Jeu1.Jouer();*/
        }
    }

  

    return 0;
}
