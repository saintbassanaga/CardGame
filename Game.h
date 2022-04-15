//
// Created by gcode on 15/04/2022.
//

#ifndef CARDGAME_GAME_H
#define CARDGAME_GAME_H

#include <array>
#include <vector>
#include <chrono>
#include <random>
#include "card.h"

struct Game {
    std::array<card, 52> deck;
    std::vector<card> player1, player2, player3, player4;

    void buildDeck() {
        for (int i = 0; i < 13; i++)
            deck[i] = card{i + 1, card::HEART};
        for (int i = 0; i < 13; i++)
            deck[i + 13] = card{i + 1, card::SPADE};
        for (int i = 0; i < 13; ++i)
            deck[i + 26] = card{i + 1, card::CLUB};
        for (int i = 0; i < 13; ++i)
            deck[i + 39] = card{i + 1, card::DIAMOND};
    }

    void dealCards() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
        player1 = {deck.begin(), deck.begin() + 13};
        player2 = {deck.begin() + 13, deck.begin() + 26};
        player3 = {deck.begin() + 26, deck.begin() + 39};
        player4 = {deck.begin() + 39, deck.end()};
    }

    bool compareAndRemove(std::vector<card> &p1, std::vector<card> &p2) {
        if (p1.back().number == p2.back().number) {
            p1.pop_back();
            p2.pop_back();
            return true;
        }
        return false;
    }

    void playOneRound() {
        if (compareAndRemove(player1, player2)) {
            compareAndRemove(player3, player4);
            return;
        } else if (compareAndRemove(player1, player3)) {
            compareAndRemove(player2, player4);
            return;
        } else if (compareAndRemove(player1, player4)) {
            compareAndRemove(player2, player3);
            return;
        } else if (compareAndRemove(player2, player3)) {
            return;
        } else if (compareAndRemove(player2, player4)) {
            return;
        } else if (compareAndRemove(player3, player4)) {
            return;
        }

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(player1.begin(), player1.end(), std::default_random_engine(seed));
        std::shuffle(player2.begin(), player2.end(), std::default_random_engine(seed));
        std::shuffle(player3.begin(), player3.end(), std::default_random_engine(seed));
        std::shuffle(player4.begin(), player4.end(), std::default_random_engine(seed));
    }

    [[nodiscard]] bool isGameComplete() const {
        return player1.empty() || player2.empty() || player3.empty() ||
               player4.empty();
    }

    void playGame() {
        while (not isGameComplete()) {
            playOneRound();
        }

    }
    int getWinner() const {
        if (player1.empty())
            return 1;
        if (player2.empty())
            return 2;
        if (player3.empty())
            return 3;
        if (player4.empty())
            return 4;
    }
};

#endif //CARDGAME_GAME_H
