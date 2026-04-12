#include <vector>
#include <memory>

#include "../Shop/Card.hpp"

class Inventory {
    private:
        std::vector<std::shared_ptr<Card>> cards;

    public:
    void addCard(std::shared_ptr<Card> card) {
        cards.push_back(card);
    }

    void showInventory() {
        if (cards.empty()) {
            std::cout << "Votre inventaire est vide." << std::endl;
        }else{
            for (const auto& card : cards) {
                card->display();
            }
        }
    }
};