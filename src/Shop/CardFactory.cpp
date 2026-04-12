
#include "CardFactory.hpp"

std::shared_ptr<Card> CardFactory::generateRandomCard() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // 55% Commune, 27% Rare, 13% Epique, 5% Légendaire
    std::discrete_distribution<> dist({55, 27, 13, 5});

    int rarityIndex = dist(gen); // Renvoie 0, 1, 2 ou 3

    switch(rarityIndex) {
        case 0: 
            return std::make_shared<PokemonCard>("Roucool", Rarity::COMMON, 10, 40, 30, "Vol");
        case 1: 
            return std::make_shared<PokemonCard>("Reptincel", Rarity::RARE, 50, 80, 50, "Feu");
        case 2: 
            return std::make_shared<PokemonCard>("Dracaufeu", Rarity::EPIC, 200, 150, 80, "Feu");
        case 3: 
            return std::make_shared<PokemonCard>("Mewtwo", Rarity::LEGENDARY, 1000, 200, 120, "Psy");
        default: 
            return std::make_shared<PokemonCard>("MissingNo", Rarity::COMMON, 0, 0, 0, "Bug");
    }
}

std::shared_ptr<Card> CardFactory::createFromCSV(const std::string& line) {
    std::stringstream ss(line);
    std::string typeTag;
    std::getline(ss, typeTag, ';');

    if (typeTag == "POKEMON") { //si on rajoute d'autres types de cartes => code facile à évoluer
        std::string n, rStr, pStr, hStr, aStr, t;
        std::getline(ss, n, ';');
        std::getline(ss, rStr, ';');
        std::getline(ss, pStr, ';');
        std::getline(ss, hStr, ';');
        std::getline(ss, aStr, ';');
        std::getline(ss, t, ';');

        return std::make_shared<PokemonCard>(
            n, 
            static_cast<Rarity>(std::stoi(rStr)), 
            std::stoi(pStr), 
            std::stoi(hStr), 
            std::stoi(aStr), 
            t
        );
    }
    return nullptr;
}