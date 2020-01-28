//Author: Michael McComas
//CSCi 3110-001
//Project #4
//File: proj4.cpp
//Due: 2/28/19

#include "card.h"
#include "deck.h"
#include "player.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    // Variables:
    int cnt = 0;
    int seed;
    Card turn1, turn2;
    string player1;
    string player2;

    ifstream file;
    file.open("cardgame.txt");
    file >> player1 >> player2 >> seed;
    // Generate random generator
    srand(seed);
    // Instantiate players
    Player p1(player1), p2(player2);
    // Instantiate the Deck
    Deck deck;
    cout << deck << endl;
    cout << endl;
    // Shuffle the deck
    deck.Shuffle();
    cout << deck << endl;
    // Players draw 3 cards
    for(int i = 0; i < 3; i++){
        p1.drawCard(deck);
        p2.drawCard(deck);
    }
    // Play until the deck is empty
    while(cnt < 26){
        cout << cnt+1 << ") " << p1.getName() << " " << p1 << "(" << p1.getScore()
             << ")" << " - " << p2.getName() << " " << p2 << "(" << p2.getScore()
             << ")" << endl;
        // Play highest card
        turn1 = p1.playCard();
        turn2 = p2.playCard();
        // Determine highest card and round winner
        if(turn1 > turn2){
            p1.addScore(turn1);
            p1.addScore(turn2);
            cout << cnt+1 << ") " << p1.getName() << "* " << p1 << "(" << p1.getScore()
             << ")" << " - " << p2.getName() << " " << p2 << "(" << p2.getScore()
             << ")" << endl;
        }
        else if(turn1 < turn2){
            p2.addScore(turn2);
            p2.addScore(turn1);
            cout << cnt+1 << ") " << p1.getName() << " " << p1 << "(" << p1.getScore()
             << ")" << " - " << p2.getName() << "* " << p2 << "(" << p2.getScore()
             << ")" << endl;
        }
        else if(turn1 == turn2){
            cout << cnt+1 << ") " << p1.getName() << " " << p1 << "(" << p1.getScore()
             << ")" << " - " << p2.getName() << " " << p2 << "(" << p2.getScore()
             << ")" << endl;
        }
        // Draw cards to replace played card if deck isn't empty
        if(!deck.isEmpty()){
            p1.drawCard(deck);
            p2.drawCard(deck);
        }
        cout << endl;
        cnt++;
    }
    // Print results
    if(p1.getScore() > p2.getScore())
        cout << "Winner " << p1.getName() << " " << p1.getScore() << endl;
    else if(p2.getScore() > p1.getScore())
        cout << "Winner " << p2.getName() << " " << p2.getScore() << endl;
    else
        cout << "Tie " << p1.getScore() << endl;
    return 0;
}