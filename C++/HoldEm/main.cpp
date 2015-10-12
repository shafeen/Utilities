#include <iostream>
#include "Card.h"

using namespace std;

int main() {


    vector<Card> deck = Card::createDeck();

    cout << deck[1].getValue() << endl;
    return 0;
}