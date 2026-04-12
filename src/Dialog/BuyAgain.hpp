
#pragma once

#include <string>
#include <iostream>

//Création d'une classe de dialogue pour demander au joueur s'il souhaite de nouveau acheter si il a encore l'argent nécessaire,
//afin d'eviter de surcharger le main
class BuyAgain{
    public:
        BuyAgain(int);
        int Dialog();
    private:
        int bal;
};