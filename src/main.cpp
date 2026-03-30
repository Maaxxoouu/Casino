#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <algorithm> //pour std::find
#include <iterator> //pour std::begin, std::end

#include "jeux/SlotMachine.hpp"
#include "Player.hpp"
#include "Mascotte/Mascotte.hpp"
#include "PlayAgain.hpp"

int main(int argc, char *argv[]) {

    std::cout<<"Quel est votre nom ?"<<std::endl;
    std::string n;
    std::cin>>n;
    Player joueur = Player(n);
    std::cout<<" "<<std::endl;

    Mascotte M = Mascotte();

    std::cout<<"*************** BIENVENUE AU CASINO "<<joueur.name<<" ! ***************"<<std::endl;
    std::cout<<" "<<std::endl;
    
    std::cout<<"Vous avez actuellement "<<joueur.balance<<" euros"<<std::endl;

    int jouer = 1;

    while(jouer){
        M.display();
        std::cout<<"A quoi voulez-vous jouer ?"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"-1. Activer/Desactiver la mascotte"<<std::endl;
        std::cout<<"0. Sortir du Casino"<<std::endl;
        std::cout<<"1. [7.7.7] Slot Machine"<<std::endl;
        std::cout<<"2. Deviner le chiffre entre 1 et 5"<<std::endl;
        std::cout<<"3. Roulette"<<std::endl;
        std::cout<<"4. Achat de boosters Pokemon"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"Veuillez entrer [-1], [0], [1], [2], [3] ou [4]"<<std::endl;

        int a;
        std::cin>>a;

        if (a == 0){
            std::cout<<"Au revoir !"<<std::endl;
            jouer = 0;
        }else if (a == -1){
            M.toggle();
        }else if (a == 1){
            int keep_playing = 1;
            while (keep_playing){
                SlotMachine Jeu1 = SlotMachine(joueur.balance);
                joueur.balance = Jeu1.Play();
                std::cout<<"Vous avez actuellement "<<joueur.balance<<" euros"<<std::endl;
                PlayAgain rejouer = PlayAgain("Slot Machine", joueur.balance);
                keep_playing = rejouer.Dialog();
            }
        }



        if (joueur.balance == 0){
            jouer = 0;
        }
    }

  

    return 0;
}
