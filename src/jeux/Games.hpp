
#pragma once

#include <iostream>
#include <unistd.h>
#include <random>

class Games{
    public:
        virtual int Play() = 0;
    protected:
        int bal;
};