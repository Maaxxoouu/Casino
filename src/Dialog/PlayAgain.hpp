
#pragma once

#include <string>
#include <iostream>

//Création d'une classe de dialogue pour demander au joueur s'il souhaite rejouer si il a encore l'argent nécessaire,
//afin d'eviter a la fois de repeter le code plusieurs fois et donc aussi de surcharger le main
class PlayAgain{
    public:
        PlayAgain(std::string, int);
        int Dialog();
    private:
        std::string txt;
        int bal;
};