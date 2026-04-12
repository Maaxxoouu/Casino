#include "BuyAgain.hpp"

BuyAgain::BuyAgain(int balance){
    bal = balance;
}

int BuyAgain::Dialog(){
    if (bal < 200){ // car le prix d'un booster est de 200
        std::cout<<"Vous n'avez pas assez d'argent !"<<std::endl;
        return 0;
    }else{
        std::cout<<"Vous avez actuellement "<<bal<<" euros."<<std::endl;
        std::cout<<"Souhaitez-vous de nouveau acheter un booster ?" <<std::endl;
        std::cout<<"0. Non"<<std::endl;
        std::cout<<"1. Oui"<<std::endl;
        std::cout<<"Veuillez entrer [0] ou [1]"<<std::endl;
        std::cout<<" "<<std::endl;
        int rep;
        std::cin>>rep;
        return rep;
    }
    
}