set(SOURCES
    main.cpp
    Player/Player.cpp
    Jeux/SlotMachine.cpp
    Jeux/GuessNumber.cpp
    Mascotte/Mascotte.cpp
    Dialog/PlayAgain.cpp

)

add_executable(${PROJECT_NAME} ${SOURCES})