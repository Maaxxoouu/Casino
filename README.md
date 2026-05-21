# 🎰 Casino - Projet C++

Bienvenue dans le jeu du Casino !
Vous commencez ce jeu avec une somme de 1 000 euros. Votre objectif est de devenir le plus riche possible, et de collectionner les meilleures cartes du jeu.
Pour ce faire, vous avez accès à 3 jeux : une Slot Machine, un jeu où il faut deviner un chiffre, et une Roulette.
Attention ! Vous devez gagner à un jeu pour débloquer le suivant. De même, vous devez gagner au dernier jeu pour accéder à la boutique.
Cette boutique vous permettra d'acheter des boosters, contenant des cartes. Cela vous permettra de compléter votre inventaire.
En cas de Game Over, la banque saisira l'intégralité de votre collection et vous devrez tout recommencer.

## 🛠️ Compiler et exécuter le code

### Compiler

Ouvrir un terminal à la racine du projet et exécuter les commandes suivantes :
```console
mkdir build_debug
cd build_debug
cmake -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles" ..
cmake --build .
```
### Executer

Il suffit d'ouvrir L'application exécutable en appelant `.\bin\Debug\Casino.exe`.

## Fonctionnalités implémentées

### Fonctionnalités ajoutées

1. **Mini-jeux :** Les 3 mini-jeux (Slot Machine, deviner un chiffre, roulette) représentent la fonctionnalité principale du Casino.

2. **Sérialisation/Désérialisation (Sauvegarde) :** Le solde du joueur et sa collection de cartes sont sauvegardés dynamiquement dans des fichiers textes ("save.txt" et "inventory.txt) et restaurés au lancement (tous deux ont besoin d'être à la racine du projet pour fonctionner). 

3. **Système de boutique :** Grâce à votre argent durement gagné, vous avez la possibilité d'acheter des boosters aléatoires dans la boutique. Le code gère les probabilités de drop.

4. **Inventaire :** On stocke les cartes obtenues dans un inventaire. On peut ensuite visualiser ce dernier dans le menu du Casino (avec "5").

### Fonctionnalités demandées

* **Mascotte :** Une Mascotte en ASCII Art est intégrée et peut être affichée ou masquée à volonté via le menu principal (En envoyant "-1").
* **Gamification :** Les jeux se débloquent au fur et à mesure, comme pour des "niveaux" dans un jeu. Pour accéder à un jeu du Casino, il faut gagner au jeu précédent. De même, pour débloquer le shop, il faut gagner au 3ème jeu.

## 📂 Architecture du projet

* `src/main.cpp` : Le point d'entrée, on ne gère ici que la boucle du menu principale.
* `src/Player/` : Contient la classe `Player` (gestion du solde et de la sauvegarde de profil) et `Inventory` (gestion de la collection de cartes).
* `src/Jeux/` : Contient les mini-jeux (`SlotMachine`, `GuessNumber` et `Roulette`).
* `src/Card/` : Contient l'architecture de collection avec la classe abstraite `Card` et ses enfants (uniquement `PokemonCard` pour le moment).
* `src/Shop/` : Contient la logique d'achats de boosters (`Shop`) et le générateur de probabilités (`CardFactory`).
* `src/Mascotte/` : Gestion isolée de l'interface visuelle de la mascotte.
* `save.txt` : Fichier texte de la forme `[nom_joueur];[balance];[bool_jeu_1_reussit];[bool_jeu_2_reussit];[bool_jeu_3_reussit]`. Il suffit de se rendre dans ce fichier pour changer le nom du joueur.
* `inventory.txt` : C'est ici que vous retrouverez toutes les cartes de votre inventaire.

## 🧠 Choix techniques et Design Patterns

* **Héritage et Polymorphisme :** Permet à l'inventaire de stocker une liste hétérogène d'objets.(`std::vector<std::shared_ptr<Card>>`). La méthode virtuelle `toCSV()` permet à chaque sous-type de carte de dicter sa propre façon de se sauvegarder.
* **Design Pattern : Factory (`CardFactory`) :** Utilisé pour la génération aléatoire des cartes. Ce pattern décharge la classe `Shop` de la responsabilité de connaître les statistiques spécifiques de chaque carte (PV, Attaque, Type).
* **Smart Pointers :** Utilisés pour la gestion des objets alloués dynamiquement dans l'inventaire, pour éviter toute fuite de mémoire.
* **Flux de fichiers (`<fstream>`):** Choisi pour la sérialisation, avec utilisation de délimiteurs (";") pour structurer les données, rendant le parsing via `<sstream>` robuste et extensible.

## 💡 Pistes d'amélioration

Ce projet peut facilement être amélioré, par exemple, nous pourrions :

* Remplacer les chiffres dans la slot machine par des emojis
* Ajouter un système de prêts lors d'un Game Over (avec des intérêts)
* Ajouter un Blackjack
* Avoir la possibilité de vendre les cartes pour se faire de l'argent (et potentiellement avoir une côte qui change pour les cartes)
* Charger les cartes (commons, uncommons, rares, etc...) à partir d'une liste de cartes dans un fichier au lieu de les avoir en dur

## Utilisation de l'IA

Étant donné que c'est la première fois que je fais du cpp, j'ai utilisé l'IA à plusieurs reprises :
* Création / Modifications des CMakeLists
* Debug des erreurs que je ne connaissais pas et que je n'arrivais pas à résoudre
* (Parfois) lors de l'utilisation de pointeurs
* Relecture/emojis de ce README
* Quelques reformulations de phrases dans ce README