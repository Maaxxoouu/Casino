set(SOURCES
    main.cpp
    Player/Player.cpp
    Player/Inventory.cpp
    Jeux/SlotMachine.cpp
    Jeux/GuessNumber.cpp
    Jeux/Roulette.cpp
    Mascotte/Mascotte.cpp
    Dialog/PlayAgain.cpp
    Dialog/BuyAgain.cpp
    Shop/Shop.cpp
    Shop/CardFactory.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

