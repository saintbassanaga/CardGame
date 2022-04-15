#include <iostream>
#include "Game.h"

int main() {
    Game newGame;
    newGame.buildDeck();
    newGame.dealCards();
    newGame.playGame();
    auto winner = newGame.getWinner();
    std::cout << "Player " << winner << " won the game." << std::endl;
    return 0;
}
