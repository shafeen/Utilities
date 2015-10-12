//
// Created by Shafeen M. on 10/11/2015.
//

#include "Card.h"
#include <stdexcept>
#include <iostream>

using std::cout;
using std::endl;

Card::Card(unsigned int _value, unsigned int _suit) {
    if (_value  >= 1 && _value <= Card::FaceCard::K) {
        this->value = _value;
    } else {
        throw new std::runtime_error("Invaid Card value!");
    }
    if (_suit >= Card::Suit::Hearts && _suit <= Card::Suit::Clubs) {
        this->suit = _suit;
    } else {
        throw new std::runtime_error("Invalid Suit value!");
    }
}


bool Card::operator==(const Card &otherCard) {
    return (this->value == otherCard.getValue() &&
            this->suit == otherCard.getSuit());
}

vector<Card> Card::createDeck() {
    vector<Card> deck;
    for (unsigned int suit = Card::Hearts; suit <= Card::Clubs; suit++) {
        for (unsigned int value = Card::A; value <= Card::K ; value++) {
//            cout << suit << " " << value << endl;
            deck.push_back(Card(value, suit));
        }
    }
    if (deck.size() != 52) {
        throw new std::runtime_error("Deck must contain 52 cards exactly!");
    }
    return deck;
}
