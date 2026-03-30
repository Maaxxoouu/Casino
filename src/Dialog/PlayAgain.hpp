
#pragma once

#include <string>
#include <iostream>

class PlayAgain{
    public:
        PlayAgain(std::string, int);
        int Dialog();
    private:
        std::string txt;
        int bal;
};