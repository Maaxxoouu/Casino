#pragma once
#include <memory>
#include <random>
#include "Card.hpp"
#include "PokemonCard.hpp"

//on créé une Factory car de base la génération de carte random était dans le Shop.cpp,
//or ce n'est pas le job du Shop de générer ces cartes.

class CardFactory {
    public:
        static std::shared_ptr<Card> generateRandomCard();
};