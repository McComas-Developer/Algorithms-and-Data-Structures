//Author: Michael McComas
//CSCI 3110-001
//Project #4
//File: player.cpp
//Due: 2/28/19

#include "player.h"
#include <iostream>

using namespace std;

Player::Player(string n){
    name = n;
    score = 0;
    hasPlayed[0] = true;
    hasPlayed[1] = true;
    hasPlayed[2] = true;
}

Card Player::playCard(){
    // Variables
    Card best = hand[0];
    int index = 0;
    int cnt = 0;
    // Determine card start point
    if(!hasPlayed[0]){
        best = hand[0];
        cnt = 1;
        index = 0;
    }
    else if(!hasPlayed[1]){
        best = hand[1];
        cnt = 2;
        index = 1;
    }
    else{
        best = hand[2];
        hasPlayed[2] = true;
        return best;
    }
    // Determine best card to play in hand
    while(cnt < 3){
        if(best < hand[cnt] && !hasPlayed[cnt]){
            best = hand[cnt];
            index = cnt;
        }
        else if(best == hand[cnt] && !hasPlayed[cnt]){
            if(best.getFaceValue() < hand[cnt].getFaceValue()){
                best = hand[cnt];
                index = cnt;
            }
            else if(best.getFaceValue() == hand[cnt].getFaceValue()){
                if(best.getSuit() > hand[cnt].getSuit()){
                    best = hand[cnt];
                    index = cnt;
                }
            }
        }
        cnt++;
    }
    hasPlayed[index] = true;
    return best;
}

// draw top card from the deck to replace played card in hand
void Player::drawCard(Deck& dk){
    if(this->hasPlayed[0] == true){
        this->hand[0] = dk.dealCard();
        this->hasPlayed[0] = false;
    }
    else if(this->hasPlayed[1] == true){
        this->hand[1] = dk.dealCard();
        this->hasPlayed[1] = false;
    }
    else if(hasPlayed[2] == true){
        this->hand[2] = dk.dealCard();
        this->hasPlayed[2] = false;
    }
}

// add the point value of the card to the player's score
void Player::addScore(Card acard){
    score += acard.getPointValue();
}

// return the score the player has earned so far
int Player::getScore() const{
    return score;
}

// return the name of the player
string Player::getName() const{
    return name;
}

// return true if the player's hand is out of cards
bool Player::emptyHand() const{
    return((hasPlayed[0] == true && hasPlayed[1] == true && hasPlayed[2] == true) ? true:false);
}

// overload the << operator to display cards in player's hand (or _____ if no card)
ostream& operator << (ostream& os, const Player& p){
    for(int i = 0; i < 3; i++){
        if(p.hasPlayed[i] != true)
            os << p.hand[i] << " ";
        else
            os << "_____" << " ";
        }
    return os;
}