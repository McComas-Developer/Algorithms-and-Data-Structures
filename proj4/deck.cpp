//Author: Michael McComas
//CSCI 3110-001
//Project #4
//File: deck.cpp
//Due: 2/28/19

#include "deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

Deck::Deck(){
    topCard = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 12; j >= 0; j--){
            switch(i){
                case 0: theDeck[topCard++] = Card(j, diamonds); break;
                case 1: theDeck[topCard++] = Card(j, spades); break;
                case 2: theDeck[topCard++] = Card(j, hearts); break;
                case 3: theDeck[topCard++] = Card(j, clubs); break;
            }
        }
    }
    topCard--;
}

Card Deck::dealCard(){
    // Remove the top card from the deck and return it
    return theDeck[topCard--];
}

void Deck::Shuffle(){
    random_shuffle(std::begin(theDeck), std::end(theDeck));
}

bool Deck::isEmpty(){
    return((topCard > 0) ? false:true);
}

ostream& operator << (ostream& os, const Deck& d){
//overload << operator to display the deck
    for(int i = 0; i <= d.topCard; i++){
        os << d.theDeck[i] << " ";
        if(i==12 || i == 25 || i ==38 || i==51)
            os << endl;
    }
    return os;
}