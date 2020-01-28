//Author: Michael McComas
//CSCI 3110-001
//Project #4
//File: card.cpp
//Due: 2/28/19

#include "card.h"
#include <iostream>

using namespace std;

Card::Card(){}

Card::Card(int face, suit st){
    cardSuit = st;
    cardFace = face;
    if(face == 0)
        pointValue = 15;
    else if(face > 10)
        pointValue = 10;
    else
        pointValue = face+1;
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
        case 0: os << "A" << face << "[" << cd.pointValue << "]"; break;
        case 1 ... 9: os << cd.cardFace+1 << face << "[" << cd.pointValue << "]"; break;
        case 10: os << "J" << face << "[" << cd.pointValue << "]"; break;
        case 11: os << "Q" << face << "[" << cd.pointValue << "]"; break;
        case 12: os << "K" << face << "[" << cd.pointValue << "]"; break;
    }   
    return os;
}

bool Card::operator < (const Card& cd) const{
    return((this->getPointValue() < cd.getPointValue()) ? true:false);
}

bool Card::operator > (const Card& cd) const{
    return((this->getPointValue() > cd.getPointValue()) ? true:false);
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