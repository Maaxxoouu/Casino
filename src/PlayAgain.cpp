#include "PlayAgain.hpp"

PlayAgain::PlayAgain(std::string t){
    txt = t;
}

int PlayAgain::Dialog(){
    std::cout<<"Souhaitez-vous rejouer au Jeu "<< txt <<" ?"<<std::endl;
    std::cout<<"0. Non"<<std::endl;
    std::cout<<"1. Oui"<<std::endl;
    std::cout<<"Veuillez entrer [0] ou [1]"<<std::endl;
    std::cout<<" "<<std::endl;
    int rep;
    std::cin>>rep;
    return rep;
}