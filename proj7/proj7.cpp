// Author: Michael McComas
// Project 7
// File: proj7.cpp
// CSCI 3110-001
// Due: 4/15/19

#include <iostream>
#include <fstream>
#include <algorithm>
#include "priorityqueue.h"
#include "card.h"

using namespace std;

int main(){
    // Variables
    int seed;
    Card deck1[13];
    Card deck2[13];

    // Declare Min and Max Priority Queues
    PriorityQueue<Card, MaxPriority<Card>> Min;
    PriorityQueue<Card, MinPriority<Card>> Max;

    // Open file 
    ifstream file;
    file.open("pqseed.txt");
    file >> seed;
    srand(seed);

    // Initialize Spades and Hearts Decks
    for(int i = 0; i < 13; i++){
        deck1[i] = Card(i, spades);
        deck2[i] = Card(i, hearts);
    }

    // Shuffle Decks
    random_shuffle(begin(deck1), end(deck1));
    random_shuffle(begin(deck2), end(deck2));

    // Display Max enqueue and dequeue
    for(int i = 0; i < 13; i++){
        cout << "Enqueueing ";
        Max.enqueue(deck1[i]);
        Max.print();
        cout << "\n";
    }
    cout << "\n";
    while(!Max.empty()){
        Max.dequeue();
        if(Max.empty()){
            cout << "Max Heap Empty" << endl;
            break;
        }
        cout << "Dequeueing ";
        Max.print();
        cout << "\n";
    }
    cout << "\n";
    // Display Min enqueue and dequeue
    for(int i = 0; i < 13; i++){
        cout << "Enqueueing ";
        Min.enqueue(deck2[i]);
        Min.print();
        cout << "\n";
    }
    cout << "\n";
    while(!Min.empty()){
        Min.dequeue();
        if(Min.empty()){
            cout << "Max Heap Empty" << endl;
            break;
        }
        cout << "Dequeueing ";
        Min.print();
        cout << "\n";
    }
    cout << "\n";
    return 0;
}