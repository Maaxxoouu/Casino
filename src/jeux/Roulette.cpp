#include "Roulette.hpp"

int Roulette::Play(int balance, Player &joueur){
    std::random_device rd; //On initialise la seed
    std::mt19937 gen(rd()); //On choisit le moteur
    std::uniform_int_distribution<> distr(1, 36); //On définit la distribution entre 1 et 36 

    std::cout<<"Combien souhaitez-vous parier ?"<<std::endl;
    int b;
    std::cin>>b;
    
    if (b <= balance && b > 0){
        balance = balance - b;

        std::cout<<"Sur combien de nombre(s) souhaitez-vous parier [1 - 36] ?"<<std::endl;
        int multiplicator, single_bet;
        std::cin>>multiplicator;

        single_bet = b/multiplicator;

        std::cout<<"Somme sur chaque nombre : "<< single_bet <<" euros"<<std::endl;

        std::vector<int> guess(multiplicator);

        for (int i=0; i<multiplicator; i++){
            std::cout<<"Sur quel nombre souhaitez-vous parier ?";
            std::cin>>guess[i];
        }
        std::cout<<" "<<std::endl;

        std::cout<<"Les jeux sont faits"<<std::endl;
        std::cout<<" "<<std::endl;
        usleep(1500000); // on attend 1.5 secondes

        int number = distr(gen);

        std::cout<< "Le nombre choisi par l'ordinateur est le nombre " << number << std::endl;
        usleep(1500000); // on attend 1.5 secondes pour pouvoir lire le dialogue
        std::cout<<" "<<std::endl;

        int find = 0;
        for (int i=0; i<multiplicator; i++){
            if (number == guess[i]){
                find++;
            }
        }

        if (find){
            joueur.hasWonRoulette = 1;
            std::cout<<"FELICITATIONS !!"<<std::endl;
            usleep(1000000); // on attend 1 secondes pour pouvoir lire le dialogue
            std::cout<<" "<<std::endl;
            int gains = single_bet * 36 * find;
            balance += gains;
            std::cout<<"Vous avez gagne "<< gains << " euros" << std::endl;
            usleep(1000000); // on attend 1 secondes pour pouvoir lire le dialogue
            std::cout<<" "<<std::endl;
        }else{
            std::cout<<"Dommage.. Vous avez perdu !"<<std::endl;
            usleep(1000000); // on attend 1 seconde pour voir qu'on a perdu
            std::cout<<" "<<std::endl;
        }
       
    }else if (b<=0){
        std::cout<<"Vous ne pouvez pas mettre une mise negative ou nulle.."<<std::endl;
        std::cout<<" "<<std::endl;
    }else{
        std::cout<<"Vous n'avez pas assez d'argent pour placer cette mise !"<<std::endl;
        std::cout<<" "<<std::endl;
    }
    return balance;
}