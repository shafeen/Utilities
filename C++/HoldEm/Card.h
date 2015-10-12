//
// Created by Shafeen M. on 10/11/2015.
//

#ifndef CLIONTEST_CARD_H
#define CLIONTEST_CARD_H

#include <vector>
using std::vector;

class Card {
public:
    static vector<Card> createDeck();

    enum FaceCard { A=1, J=11, Q=12, K=13 };
    enum Suit { Hearts=0, Diamonds=1, Spades=2, Clubs=3 };

private:
    unsigned int value;
    unsigned int suit;

public:
    Card(unsigned int, unsigned int);

    bool operator==(const Card &otherCard);

    unsigned int getValue() const {return this->value;}
    unsigned int getSuit() const {return this->suit;}
};


#endif //CLIONTEST_CARD_H
