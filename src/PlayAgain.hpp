
#pragma once

#include <string>
#include <iostream>

class PlayAgain{
    public:
        PlayAgain(std::string);
        int Dialog();
    private:
        std::string txt;
};