#pragma once
#include <memory>
#include <random>
#include "Card.hpp"
#include "PokemonCard.hpp"

//on créé une Factory car de base la génération de carte random était dans le Shop.cpp,
//or ce n'est pas le job du Shop de générer ces cartes.
//c'est aussi elle qui va permettre de faire le lien entre l'inventaire et le fichier de save de l'inventaire

class CardFactory {
    public:
        static std::shared_ptr<Card> generateRandomCard();

        static std::shared_ptr<Card> createFromCSV(const std::string& line);
};