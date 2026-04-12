#include "Shop.hpp"

Shop::Shop(int price) {
    boosterPrice = price;
    NbOfCardPerBooster = 3; // par défaut on va mettre le nombre de cartes par booster à 3
}

int Shop::buyAndOpenBooster(Player& player) {
    if (player.getBal() < boosterPrice) {
        std::cout << "Fonds insuffisants. Un booster coute " << boosterPrice << " euros." << std::endl;
        usleep(1500000);
        return 0;
    }else{
        player.setBal(player.getBal() - boosterPrice);
    
        std::cout << "Achat d'un booster" << std::endl;
        usleep(1000000);
        std::cout << "Ouverture..." << std::endl;
        usleep(1500000);

        std::cout << "\n--- NOUVELLES CARTES ---" << std::endl;

        for (int i = 0; i < NbOfCardPerBooster; ++i) { //on génère NbOfCardPerBooster cartes
            std::shared_ptr<Card> newCard = CardFactory::generateRandomCard();
        
            newCard->display();
        
            // On ajoute la carte à l'inventaire du joueur
            player.inventaire.addCard(newCard); 
        
            usleep(300000); // 3s d'attente entre les cartes
        }
        std::cout << "------------------------\n" << std::endl;
        usleep(1500000);
        return 1;
    }
}

