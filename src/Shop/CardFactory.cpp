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