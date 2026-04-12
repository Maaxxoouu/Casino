#include "Inventory.hpp"

void Inventory::showInventory(){
    if (cards.empty()) {
                std::cout << "Votre inventaire est vide." << std::endl;
            }else{
                for (const auto& card : cards) {
                    card->display();
                }
            }
            std::cout<<" "<<std::endl;
}

void Inventory::save(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& card : cards) {
        file << card->toCSV() << "\n";
    }
    file.close();
}


bool Inventory::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return 0;

    //cards.clear(); // On vide l'inventaire actuel avant de charger
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        auto card = CardFactory::createFromCSV(line);
        if (card) {
            cards.push_back(card);
        }
    }
    file.close();
    return 1;
}

void Inventory::clear() {
    cards.clear();
}