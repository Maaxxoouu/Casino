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
#include "Shop/Shop.hpp"
#include "Dialog/BuyAgain.hpp"


int main(int argc, char *argv[]) {

    Player joueur = Player();
    Mascotte M = Mascotte();

    SlotMachine slotGame = SlotMachine();
    GuessNumber guessGame = GuessNumber();
    Roulette rouletteGame = Roulette();
    Shop boutique(200); // Un booster coûte 100€

    int jouer = 1;
    int bal_temp, new_bal;

    std::cout<<"*************** BIENVENUE AU CASINO "<<joueur.getName()<<" ! ***************"<<std::endl;
    std::cout<<" "<<std::endl;
    
    std::cout<<"Vous avez actuellement "<<joueur.getBal()<<" euros"<<std::endl;

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
        std::cout<<"5. Visualiser son inventaire"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"Veuillez entrer [-1], [0], [1], [2], [3], [4] ou [5]"<<std::endl;

        int a;
        std::cin>>a;

        if (a == 0){
            joueur.save("../save.txt");
            joueur.inventaire.save("../inventory.txt");
            std::cout<<"Au revoir !"<<std::endl;
            jouer = 0;
        }
        
        else if (a == -1){
            M.toggle();
        }
        
        else if (a == 1){
            int keep_playing = 1;
            while (keep_playing){
                bal_temp = joueur.getBal();
                new_bal = slotGame.Play(bal_temp, joueur);
                joueur.setBal(new_bal);
                std::cout<<"Vous avez actuellement "<<new_bal<<" euros"<<std::endl;
                PlayAgain rejouer = PlayAgain("Slot Machine", new_bal);
                keep_playing = rejouer.Dialog();
            }  
        }
        
        else if (a == 2){
            if (joueur.hasWonSlotMachine){
                int keep_playing = 1;
                while (keep_playing){
                    bal_temp = joueur.getBal();
                    new_bal = guessGame.Play(bal_temp, joueur);
                    joueur.setBal(new_bal);
                    std::cout<<"Vous avez actuellement "<<new_bal<<" euros"<<std::endl;
                    PlayAgain rejouer = PlayAgain("Deviner le chiffre", new_bal);
                    keep_playing = rejouer.Dialog();
                }
            }else{
                std::cout<<" "<<std::endl;
                std::cout<<"Vous devez d'abord gagner a la Slot Machine !"<<std::endl;
                std::cout<<" "<<std::endl;
                usleep(2000000); // on attend 2 secondes pour pouvoir lire le dialogue
            }
            
        }else if (a == 3){
            if (joueur.hasWonGuessNumber){
                int keep_playing = 1;
                while (keep_playing){
                    bal_temp = joueur.getBal();
                    new_bal = rouletteGame.Play(bal_temp, joueur);
                    joueur.setBal(new_bal);
                    std::cout<<"Vous avez actuellement "<<new_bal<<" euros"<<std::endl;
                    PlayAgain rejouer = PlayAgain("Roulette", new_bal);
                    keep_playing = rejouer.Dialog();
                }
            }else{
                std::cout<<" "<<std::endl;
                std::cout<<"Vous devez d'abord gagner au jeu Deviner un chiffre !"<<std::endl;
                std::cout<<" "<<std::endl;
                usleep(2000000); // on attend 2 secondes pour pouvoir lire le dialogue
            }
        }else if (a == 4){
            if (joueur.hasWonRoulette){
                int keep_buying = 1;
                int bought;
                while (keep_buying) {
                    bought = boutique.buyAndOpenBooster(joueur);
                    if (bought){
                        BuyAgain buyAgain = BuyAgain(joueur.getBal());
                        keep_buying = buyAgain.Dialog();
                    }
                }
            }else{
                std::cout<<" "<<std::endl;
                std::cout<<"Vous devez d'abord gagner au jeu Roulette !"<<std::endl;
                std::cout<<" "<<std::endl;
                usleep(2000000); // on attend 2 secondes pour pouvoir lire le dialogue
            }
        }else if (a == 5){
            joueur.inventaire.showInventory();
            usleep(5000000);
        }


        if (joueur.getBal() == 0){ // GAME OVER
            joueur.save("../save.txt");
            joueur.inventaire.clear();
            joueur.inventaire.save("../inventory.txt");
            jouer = 0;
        }
    } 

    return 0;
}
