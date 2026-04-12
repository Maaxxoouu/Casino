#include "Player.hpp"

Player::Player(){
    bool test = load("../save.txt");
    if (!test){
        std::cout << "Impossible de charger le fichier save.txt" << std::endl;
    }

    bool testInventory = inventaire.load("../inventory.txt");
    if (!testInventory){
        std::cout << "Impossible de charger le fichier inventory.txt" << std::endl;
    }
}

std::string Player::getName(){
    return name;
}

int Player::getBal(){
    return balance;
}

void Player::setBal(int newBal){
    balance = newBal;
}

bool Player::load(const std::string& filename) {
    std::ifstream file(filename);
    
    if (file.is_open()) {
        std::string line;
        // On lit la première ligne du fichier
        if (std::getline(file, line)) {
            // On utilise stringstream pour découper la ligne
            std::stringstream ss(line);
            std::string loadedName;
            std::string loadedBalanceStr;
            std::string slotStr;
            std::string guessStr;
            std::string rouletteStr;
            
            // On coupe à chaque ';'
            if (std::getline(ss, loadedName, ';') &&
                std::getline(ss, loadedBalanceStr, ';') &&
                std::getline(ss, slotStr, ';') &&
                std::getline(ss, guessStr, ';') &&
                std::getline(ss, rouletteStr)) {
                name = loadedName;
                // On convertit le string de la balance en entier (int)
                balance = std::stoi(loadedBalanceStr);
                // On convertit les "0" ou "1" en booléens
                hasWonSlotMachine = std::stoi(slotStr); 
                hasWonGuessNumber = std::stoi(guessStr);
                hasWonRoulette = std::stoi(rouletteStr);
                file.close();
                return true; // Le chargement a réussi
            }
        }
        file.close();
    }
    return false; // Le fichier n'a pas été trouvé, n'existe pas ou est corrompu
}

void Player::save(const std::string& filename) {
    std::ofstream file(filename); 
    
    if (file.is_open()) {
        if (balance == 0){
            file << name << ";1000;0;0;0\n";
            file.close();
            std::cout << "Sauvegarde reset !" << std::endl;
        }else{
            file << name << ";" << balance << ";" << hasWonSlotMachine <<";"<<hasWonGuessNumber<<";"<<hasWonRoulette<<"\n";
            file.close();
            std::cout << "Sauvegarde reussie !" << std::endl;
        }
    } else {
        std::cout << "Erreur : Impossible de creer le fichier de sauvegarde." << std::endl;
    }
}