#include "PlayAgain.hpp"

PlayAgain::PlayAgain(std::string t, int balance){
    txt = t;
    bal = balance;
}

int PlayAgain::Dialog(){
    if (bal == 0){
        std::cout<<"GAME OVER ! Vous n'avez plus d'argent"<<std::endl;
        return 0;
    }else{
        std::cout<<"Souhaitez-vous rejouer au Jeu "<< txt <<" ?"<<std::endl;
        std::cout<<"0. Non"<<std::endl;
        std::cout<<"1. Oui"<<std::endl;
        std::cout<<"Veuillez entrer [0] ou [1]"<<std::endl;
        std::cout<<" "<<std::endl;
        int rep;
        std::cin>>rep;
        return rep;
    }
    
}