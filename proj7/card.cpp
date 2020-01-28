// Author: Michael McComas
// Project 7
// File: card.cpp
// CSCI 3110-001
// Due: 4/15/19

#include "card.h"
#include <iostream>

using namespace std;

Card::Card(){}

Card::Card(int face, suit st){
    cardSuit = st;
    cardFace = face + 1;
}

ostream& operator << (ostream& os, const Card& cd){
    char face;
    if(cd.cardSuit == diamonds)
        face = 'D';
    else if(cd.cardSuit == clubs)
        face = 'C';
    else if(cd.cardSuit == spades)
        face = 'S';
    else
        face = 'H';
    switch(cd.cardFace){
        case 0: os << "A" << face << "[" << cd.cardFace+1 << "]"; break;
        case 1 ... 9: os << cd.cardFace+1 << face << "[" << cd.cardFace+1 << "]"; break;
        case 10: os << "J" << face << "[" << cd.cardFace+1 << "]"; break;
        case 11: os << "Q" << face << "[" << cd.cardFace+1 << "]"; break;
        case 12: os << "K" << face << "[" << cd.cardFace+1 << "]"; break;
    }   
    return os;
}

bool Card::operator <= (const Card& cd) const{
    return((this->getPointValue() <= cd.getPointValue()) ? true:false);
}

bool Card::operator >= (const Card& cd) const{
    return((this->getPointValue() >= cd.getPointValue()) ? true:false);
}

bool Card::operator== (const Card& cd) const{
    return((this->getPointValue() == cd.getPointValue()) ? true:false);
}

int Card::getPointValue() const{
    return pointValue;
}

int Card::getFaceValue() const{
    return cardFace;
}

suit Card::getSuit() const{
    return cardSuit;
}