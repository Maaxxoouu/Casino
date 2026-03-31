
#pragma once

#include <iostream>
#include <unistd.h>
#include <random>

//Ajout d'une classe abstraite Games pour regrouper le maximum de choses en commun entre tous les Jeux
class Games{
    public:
        virtual int Play() = 0;
    protected:
        int bal;
};