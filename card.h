//
// Created by gcode on 15/04/2022.
//

#ifndef CARDGAME_CARD_H
#define CARDGAME_CARD_H


#include <sstream>

struct card {
    int number;
    enum suit {
        HEART, SPADE, CLUB, DIAMOND
    } suit;

    [[nodiscard]] std::string to_string() const {
        std::ostringstream os;
        if (number > 0 && number <= 10) {
            os << number;
        } else {
            switch (number) {
                case 1:
                    os << "Ace";
                    break;
                case 11 :
                    os << "Jack";
                    break;
                case 12:
                    os << "Queen";
                    break;
                case 13:
                    os << "King";
                    break;
                default:
                    return " Invalid card";
            }
        }
        os<<"of";
        switch (suit) {
            case HEART:
                os<<"Hearts";
                break;
            case SPADE:
                os<<"Spades";
                break;
            case CLUB:
                os<<"Clubs";
                break;
            case DIAMOND:
                os<<"diamonds";
                break;
        }
        return os.str();
    }
};


#endif //CARDGAME_CARD_H
