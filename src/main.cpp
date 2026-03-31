#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <algorithm> //pour std::find
#include <iterator> //pour std::begin, std::end

#include "Player/Player.hpp"
#include "Mascotte/Mascotte.hpp"
#include "Jeux/SlotMachine.hpp"
#include "Jeux/GuessNumber.hpp"
#include "Jeux/Roulette.hpp"
#include "Dialog/PlayAgain.hpp"


int main(int argc, char *argv[]) {

    Player joueur = Player();
    Mascotte M = Mascotte();

    std::cout<<"*************** BIENVENUE AU CASINO "<<joueur.getName()<<" ! ***************"<<std::endl;
    std::cout<<" "<<std::endl;
    
    std::cout<<"Vous avez actuellement "<<joueur.getBal()<<" euros"<<std::endl;

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
            joueur.save("../save.txt");
            std::cout<<"Au revoir !"<<std::endl;
            jouer = 0;
        }else if (a == -1){
            M.toggle();
        }else if (a == 1){
            int keep_playing = 1;
            while (keep_playing){
                int bal_temp = joueur.getBal();
                SlotMachine Jeu1 = SlotMachine(bal_temp);
                bal_temp = Jeu1.Play();
                joueur.setBal(bal_temp);
                std::cout<<"Vous avez actuellement "<<bal_temp<<" euros"<<std::endl;
                PlayAgain rejouer = PlayAgain("Slot Machine", bal_temp);
                keep_playing = rejouer.Dialog();
            }
        }else if (a == 2){
            int keep_playing = 1;
            while (keep_playing){
                int bal_temp = joueur.getBal();
                GuessNumber Jeu2 = GuessNumber(bal_temp);
                bal_temp = Jeu2.Play();
                joueur.setBal(bal_temp);
                std::cout<<"Vous avez actuellement "<<bal_temp<<" euros"<<std::endl;
                PlayAgain rejouer = PlayAgain("Deviner le chiffre", bal_temp);
                keep_playing = rejouer.Dialog();
            }
        }else if (a == 3){
            int keep_playing = 1;
            while (keep_playing){
                int bal_temp = joueur.getBal();
                Roulette Jeu2 = Roulette(bal_temp);
                bal_temp = Jeu2.Play();
                joueur.setBal(bal_temp);
                std::cout<<"Vous avez actuellement "<<bal_temp<<" euros"<<std::endl;
                PlayAgain rejouer = PlayAgain("Roulette", bal_temp);
                keep_playing = rejouer.Dialog();
            }
        }



        if (joueur.getBal() == 0){
            joueur.save("../save.txt");
            jouer = 0;
        }
    }

  

    return 0;
}
