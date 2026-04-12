#include <vector>
#include <memory>
#include <fstream>

#include "../Shop/Card.hpp"
#include "../Shop/CardFactory.hpp"

class Inventory {
    private:
        std::vector<std::shared_ptr<Card>> cards;

    public:
        void save(const std::string& filename);
        bool load(const std::string& filename);

        void addCard(std::shared_ptr<Card> card) {
            cards.push_back(card);
        }

        void showInventory();

        void clear();
};