#include "Mascotte.hpp"

Mascotte::Mascotte(){
    isEnabled = true;
    ascii = R"( _._     _,-'""`-._
(,-.`._,'(       |\`-/|
    `-.-' \ )-`( , o o)
          `-    \`_`"'-)";
}

void Mascotte::toggle(){
    isEnabled = !isEnabled;
}

void Mascotte::display(){
    if (isEnabled){
        std::cout << ascii << std::endl;
        std::cout << " " << std::endl;
    }
}