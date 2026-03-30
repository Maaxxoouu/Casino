
#pragma once

#include <string>
#include <iostream>

class Mascotte{
    public:
        Mascotte();
        void toggle();
        void display();
    private:
        bool isEnabled;
        std::string ascii;
};