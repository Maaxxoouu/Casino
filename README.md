En mode concis :
```console
mkdir build_debug
cd build_debug
cmake -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles" ..
cmake --build .
```

 L'application exécutable en appelant `.\bin\Debug\Casino.exe`.


 A faire :
 - remplacer les chiffres dans la slot machine par des emojis (optionnel)
 - système de prêts (avec des intérêts?) (optionnel)
 - Roulette
 - Blackjack (optionnel)
 - Système de cartes pokémons
 - Initialiser l'instance joueur à partir d'un fichier
 - Save l'instance joueur dans le même fichier
 - Il faut gagner à la Slot Machine pour Débloquer le Guess Number, et faut gagner au Guess Number pour débloquer la roulette (gamification)