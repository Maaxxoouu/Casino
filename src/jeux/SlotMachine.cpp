#include "SlotMachine.hpp"




SlotMachine::SlotMachine(int balance){
    bal = balance;
}

int SlotMachine::Play(){
    std::random_device rd; //On initialise la seed
    std::mt19937 gen(rd()); //On choisit le moteur
    std::uniform_int_distribution<> distr(1, 9); //On définit la distribution entre 1 et 9 inclus
    std::cout<<"Combien souhaitez-vous parier ?"<<std::endl;
    int b;
    std::cin>>b;
    if (b <= bal && b > 0){
        bal = bal - b;
        std::cout<<"Les jeux sont faits"<<std::endl;
        std::cout<<" "<<std::endl;
        usleep(1500000); // on attend 1.5 secondes

        int number1 = distr(gen);
        int number2 = distr(gen);
        int number3 = distr(gen);

        std::cout<<"-------------"<<std::endl;
        std::cout<<"- "<< number1 << " - "<< number2 << " - " << number3 << " -"<<std::endl;
        std::cout<<"-------------"<<std::endl;
        std::cout<<" "<<std::endl;

        usleep(1500000); // on attend 1.5 secondes pour voir le resultat tranquillement

        if (number1 % 2 == 0 && number2 % 2 == 0 && number3 % 2 == 0){
            std::cout<<"FELICITATIONS !!"<<std::endl;
            usleep(500000); // on attend 0.5 secondes
            std::cout<<" "<<std::endl;
            int gains = b * 2;
            bal += gains;
            std::cout<<"Vous avez gagne "<< gains << " euros" << std::endl;
            usleep(1500000); // on attend 1.5 secondes pour voir nos gains
            std::cout<<" "<<std::endl;
        }else if (number1 % 2 != 0 && number2 % 2 != 0 && number3 % 2 != 0){
            std::cout<<"FELICITATIONS !!"<<std::endl;
            usleep(500000); // on attend 0.5 secondes
            std::cout<<" "<<std::endl;
            int gains = b * 2;
            bal += gains;
            std::cout<<"Vous avez gagne "<< gains << " euros" << std::endl;
            usleep(1500000); // on attend 1.5 secondes pour voir nos gains
            std::cout<<" "<<std::endl;
        } else if (number1 == number2 && number2 == number3){
            std::cout<<"FELICITATIONS !!"<<std::endl;
            usleep(500000); // on attend 0.5 secondes
            std::cout<<" "<<std::endl;
            int gains = b * 5;
            bal += gains;
            std::cout<<"Vous avez gagne "<< gains << " euros" << std::endl;
            usleep(1500000); // on attend 1.5 secondes pour voir nos gains
            std::cout<<" "<<std::endl;
        } else if (number1 == 7 && number2 == 7 && number3 == 7){
            std::cout<<"FELICITATIONS !!"<<std::endl;
            usleep(500000); // on attend 0.5 secondes
            std::cout<<" "<<std::endl;
            int gains = b * 10;
            bal += gains;
            std::cout<<"Vous avez gagne "<< gains << " euros" << std::endl;
            usleep(1500000); // on attend 1.5 secondes pour voir nos gains
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
    return bal;
}