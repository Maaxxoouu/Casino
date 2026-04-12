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
 - Blackjack (optionnel)
 - Système de cartes pokémons / un shop (fait)
 - Initialiser l'instance joueur à partir d'un fichier (fait)
 - Save l'instance joueur dans le même fichier (fait)
 - Il faut gagner à la Slot Machine pour Débloquer le Guess Number, et faut gagner au Guess Number pour débloquer la roulette (gamification) (fait)
 - pouvoir vendre les cartes pour se refaire de l'argent (et potentiellement avoir une côte qui change pour les cartes) (optionnel)
 - charger les cartes commons, uncommon, rare, etc... à partir d'une liste de cartes dans un fichier au lieu de les avoir en dur
 - opti le code en passant le joueur par référence pour les jeux au lieu de faire plusieurs appels à getBal() et setBal()


 bien dire que les fichiers save.txt et inventory.txt doivent être à la racine du projet sinon ça ne fonctionne pas