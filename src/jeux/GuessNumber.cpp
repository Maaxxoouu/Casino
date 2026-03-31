#include "GuessNumber.hpp"

GuessNumber::GuessNumber(int balance){
    bal = balance;
}

int GuessNumber::Play(){
    std::random_device rd; //On initialise la seed
    std::mt19937 gen(rd()); //On choisit le moteur
    std::uniform_int_distribution<> distr(1, 5); //On définit la distribution entre 1 et 5 inclus
    std::cout<<"Combien souhaitez-vous parier ?"<<std::endl;
    int b,guess;
    std::cin>>b;
    if (b <= bal && b > 0){
        bal = bal - b;
        std::cout<<"Choisissez un chiffre entre 1 et 5 (inclus) :"<<std::endl;
        std::cin>>guess;
        std::cout<<" "<<std::endl;
        std::cout<<"Les jeux sont faits"<<std::endl;
        std::cout<<" "<<std::endl;
        usleep(1500000); // on attend 1.5 secondes

        int number = distr(gen);

        std::cout<<"Le chiffre qu'il fallait deviner : "<< number << std::endl;
        std::cout<<"Votre chiffre : "<< guess << std::endl;
        std::cout<<" "<<std::endl;
        if (guess == number){
            std::cout<<"FELICITATIONS !!"<<std::endl;
            std::cout<<" "<<std::endl;
            int gains = b * 2;
            bal += gains;
            std::cout<<"Vous avez gagne "<< gains << " euros" << std::endl;
            std::cout<<" "<<std::endl;
        }else{
            std::cout<<"Dommage.. Vous avez perdu !"<<std::endl;
            std::cout<<" "<<std::endl;
        }
    }else if (b<=0){
        std::cout<<"Vous ne pouvez pas mettre une mise negative ou nulle.."<<std::endl;
    }else{
        std::cout<<"Vous n'avez pas assez d'argent pour placer cette mise !"<<std::endl;
    }
    return bal;
}